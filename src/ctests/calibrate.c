/*
   Calibrate.c
        A program to perform one or all of three tests to count flops.
        Test 1. Inner Product:                          2*n operations
                for i = 1:n; a = a + x(i)*y(i); end
        Test 2. Matrix Vector Product:          2*n^2 operations
                for i = 1:n; for j = 1:n; x(i) = x(i) + a(i,j)*y(j); end; end;
        Test 3. Matrix Matrix Multiply:         2*n^3 operations
                for i = 1:n; for j = 1:n; for k = 1:n; c(i,j) = c(i,j) + a(i,k)*b(k,j); end; end; end;

  Supply a command line argument of 1, 2, or 3 to perform each test, or
  no argument to perform all three.

  Each test initializes PAPI and presents a header with processor information.
  Then it performs 500 iterations, printing result lines containing:
  n, measured counts, theoretical counts, (measured - theory), % error
 */

#include "papi_test.h"

static void resultline(int i, int j, int TESTS_QUIET);
static void headerlines(char *title, int TESTS_QUIET);

#define INDEX1 100
#define INDEX5 500

/* #define DONT_FAIL */
#if _WIN32 /* recognize that Windows has more noise */
  #define MAX_ERROR 20
#else
  #define MAX_ERROR 10
#endif
#define MAX_DIFF  14

extern int TESTS_QUIET;

static void print_help(char **argv)
{
   printf("Usage: %s [-ivmdh]\n",argv[0]);
   printf("Options:\n\n");
   printf("\t-i            Inner Product test.\n");
   printf("\t-v            Matrix-Vector multiply test.\n");
   printf("\t-m            Matrix-Matrix multiply test.\n");
   printf("\t-d            Double precision data. Default is float.\n");
   printf("\t-h            Print this help message\n");
   printf("\n");
   printf("This test measures floating point operations for the specified test.\n");
   printf("Operations can be performed in single or double precision.\n");
   printf("Default operation is all three tests in single precision.\n");
}

static float inner_single(int n, float *x, float *y)
{
   float aa = 0.0;
   int i;

   for (i = 0; i <= n; i++)
      aa = aa + x[i] * y[i];
   return(aa);
}

static double inner_double(int n, double *x, double *y)
{
   double aa = 0.0;
   int i;

   for (i = 0; i <= n; i++)
      aa = aa + x[i] * y[i];
   return(aa);
}

static void vector_single(int n, float *a, float *x, float *y)
{
    int i, j;

    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
	 y[i] = y[i] + a[i * n + j] * x[i];
}

static void vector_double(int n, double *a, double *x, double *y)
{
    int i, j;

    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
	 y[i] = y[i] + a[i * n + j] * x[i];
}

static void matrix_single(int n, float *c, float *a, float *b)
{
    int i, j, k;

   for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
         for (k = 0; k <= n; k++)
            c[i * n + j] = c[i * n + j] + a[i * n + k] * b[k * n + j];
}

static void matrix_double(int n, double *c, double *a, double *b)
{
    int i, j, k;

   for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
         for (k = 0; k <= n; k++)
            c[i * n + j] = c[i * n + j] + a[i * n + k] * b[k * n + j];
}

static void reset_flops(char *title) {
    int retval;
    char err_str[PAPI_MAX_STR_LEN];
    float real_time, proc_time, mflops;
    long_long flpins;

    retval = PAPI_stop_counters(NULL, 0);
    if (!(retval == PAPI_OK || retval == PAPI_ENOTRUN)){
	sprintf(err_str, "%s: PAPI_stop_counters", title);
	test_fail(__FILE__, __LINE__, err_str, retval);
    }
    retval = PAPI_flops(&real_time, &proc_time, &flpins, &mflops);
    if (retval != PAPI_OK) {
	sprintf(err_str, "%s: PAPI_flops", title);
	test_fail(__FILE__, __LINE__, err_str, retval);
    }
}

int main(int argc, char *argv[])
{
   extern void dummy(void *);

   float aa, *a, *b, *c, *x, *y;
   double aad, *ad, *bd, *cd, *xd, *yd;
   int i, j, n;
   int inner = 0;
   int vector = 0;
   int matrix = 0;
   int double_precision = 0;
   int element_size;
   int retval = PAPI_OK;

/* Parse the input arguments */
   for (i = 0; i < argc; i++)
     {
       if (strstr(argv[i], "-i"))
	 inner = 1;
       else if (strstr(argv[i], "-v"))
	 vector = 1;
       else if (strstr(argv[i], "-m"))
	 matrix = 1;
       else if (strstr(argv[i], "-d"))
	 double_precision = 1;
       else if (strstr(argv[i], "-h")) {
	 print_help(argv);
	 exit(1);
       }
     }

   /* if no options specified, set all tests to TRUE */
   if (inner + vector + matrix == 0)
       inner = vector = matrix = 1;


   tests_quiet(argc, argv);     /* Set TESTS_QUIET variable */

   if (!TESTS_QUIET)
      printf("Initializing...");

   /* Initialize PAPI */
   retval = PAPI_library_init(PAPI_VER_CURRENT);
   if (retval != PAPI_VER_CURRENT)
      test_fail(__FILE__, __LINE__, "PAPI_library_init", retval);

/* If this platform doesn't support floating point, skip the test */
   if (PAPI_query_event(PAPI_FP_OPS) != PAPI_OK) {
      test_skip(__FILE__, __LINE__, "PAPI_query_event", PAPI_ENOEVNT);
   }

if (double_precision) element_size = sizeof(double);
else element_size = sizeof(float);

   retval = PAPI_OK;

   /* Inner Product test */
   if (inner) {
      /* Allocate the linear arrays */
	x = malloc(INDEX5 * element_size);
	y = malloc(INDEX5 * element_size);
	if (!(x && y))
	    retval = PAPI_ENOMEM;
	xd = (double *)x;
	yd = (double *)y;

       if (retval == PAPI_OK) {
         headerlines("Inner Product Test", TESTS_QUIET);

         /* step through the different array sizes */
         for (n = 0; n < INDEX5; n++) {
            if (n < INDEX1 || ((n + 1) % 50) == 0) {

               /* Initialize the needed arrays at this size */
		if (double_precision) {
		   for (i = 0; i <= n; i++) {
		      xd[i] = (double)rand() * (double) 1.1;
		      yd[i] = (double)rand() * (double) 1.1;
		   }
		} else {
		   for (i = 0; i <= n; i++) {
		      x[i] = rand() * (float) 1.1;
		      y[i] = rand() * (float) 1.1;
		   }
		}

               /* reset PAPI flops count */
		reset_flops("Inner Product Test");

               /* do the multiplication */
	       if (double_precision) {
		   aad = inner_double(n, xd, yd);
		   dummy((void *) &aad);
	       } else {
		   aa = inner_single(n, x, y);
		   dummy((void *) &aa);
	       }
	       resultline(n, 1, TESTS_QUIET);
            }
         }
      }
       free(x);
       free(y);
   }

   /* Matrix Vector test */
   if (vector && retval != PAPI_ENOMEM) {
      /* Allocate the needed arrays */
      a = malloc(INDEX5 * INDEX5 * element_size);
      x = malloc(INDEX5 * element_size);
      y = malloc(INDEX5 * element_size);
      if (!(a && x && y))
         retval = PAPI_ENOMEM;
      ad = (double *)a;
      xd = (double *)x;
      yd = (double *)y;

      if (retval == PAPI_OK) {
         headerlines("Matrix Vector Test", TESTS_QUIET);

         /* step through the different array sizes */
         for (n = 0; n < INDEX5; n++) {
            if (n < INDEX1 || ((n + 1) % 50) == 0) {

               /* Initialize the needed arrays at this size */
		if (double_precision) {
		   for (i = 0; i <= n; i++) {
		      yd[i] = 0.0;
		      xd[i] = (double)rand() * (double) 1.1;
		      for (j = 0; j <= n; j++)
			 ad[i * n + j] = (double)rand() * (double) 1.1;
		   }
		} else {
		   for (i = 0; i <= n; i++) {
		      y[i] = 0.0;
		      x[i] = rand() * (float) 1.1;
		      for (j = 0; j <= n; j++)
			 a[i * n + j] = rand() * (float) 1.1;
		   }
		}

               /* reset PAPI flops count */
		reset_flops("Matrix Vector Test");

               /* compute the resultant vector */
		if (double_precision) {
		    vector_double(n, ad, xd, yd);
		    dummy((void *) yd);
		} else {
		    vector_single(n, a, x, y);
		    dummy((void *) y);
		}
                resultline(n, 2, TESTS_QUIET);
            }
         }
      }
      free(a);
      free(x);
      free(y);
   }

   /* Matrix Multiply test */
   if (matrix && retval != PAPI_ENOMEM) {
      /* Allocate the needed arrays */
      a = malloc(INDEX5 * INDEX5 * element_size);
      b = malloc(INDEX5 * INDEX5 * element_size);
      c = malloc(INDEX5 * INDEX5 * element_size);
      if (!(a && b && c))
         retval = PAPI_ENOMEM;
      ad = (double *)a;
      bd = (double *)b;
      cd = (double *)c;

      if (retval == PAPI_OK) {
         headerlines("Matrix Multiply Test", TESTS_QUIET);

         /* step through the different array sizes */
         for (n = 0; n < INDEX5; n++) {
            if (n < INDEX1 || ((n + 1) % 50) == 0) {

               /* Initialize the needed arrays at this size */
		if (double_precision) {
		    for (i = 0; i <= n * n + n; i++) {
		      cd[i] = 0.0;
		      ad[i] = (double)rand() * (double) 1.1;
		      bd[i] = (double)rand() * (double) 1.1;
		    }
		} else {
		    for (i = 0; i <= n * n + n; i++) {
		      c[i] = 0.0;
		      a[i] = rand() * (float) 1.1;
		      b[i] = rand() * (float) 1.1;
		    }
		}

               /* reset PAPI flops count */
		reset_flops("Matrix Multiply Test");

               /* compute the resultant matrix */
		if (double_precision) {
		    matrix_double(n, cd, ad, bd);
		    dummy((void *) c);
		} else {
		    matrix_single(n, c, a, b);
		    dummy((void *) c);
		}
		resultline(n, 3, TESTS_QUIET);
            }
         }
      }
      free(a);
      free(b);
      free(c);
   }

   /* exit with status code */
   if (retval == PAPI_ENOMEM)
      test_fail(__FILE__, __LINE__, "malloc", retval);
   else
      test_pass(__FILE__, NULL, 0);
   exit(1);
}

/*
        Extract and display hardware information for this processor.
        (Re)Initialize PAPI_flops() and begin counting floating ops.
*/
static void headerlines(char *title, int TESTS_QUIET)
{
   const PAPI_hw_info_t *hwinfo = NULL;

   if (!TESTS_QUIET) {
      if ((hwinfo = PAPI_get_hardware_info()) == NULL)
         test_fail(__FILE__, __LINE__, "PAPI_get_hardware_info", 1);

      printf
          ("\n-------------------------------------------------------------------------\n");
      printf("Vendor string and code   : %s (%d)\n", hwinfo->vendor_string,
             hwinfo->vendor);
      printf("Model string and code    : %s (%d)\n", hwinfo->model_string, hwinfo->model);
      printf("CPU revision             : %f\n", hwinfo->revision);
      printf("CPU Megahertz            : %f\n", hwinfo->mhz);
      printf("CPU's in an SMP node     : %d\n", hwinfo->ncpu);
      printf("Nodes in the system      : %d\n", hwinfo->nnodes);
      printf("Total CPU's in the system: %d\n", hwinfo->totalcpus);
      printf
          ("-------------------------------------------------------------------------\n");
      printf("\n%s:\n%8s %12s %12s %8s %8s\n", title, "i", "papi", "theory", "diff",
             "%error");
      printf
          ("-------------------------------------------------------------------------\n");
   }
}

/*
  Read PAPI_flops.
  Format and display results.
  Compute error without using floating ops.
*/
#if defined(mips)
#define SLOPE 9
#define FMA 1
#elif (defined(sparc) && defined(sun))
#define SLOPE 0
#define FMA 1
#else
#define SLOPE 0
#define FMA 0
#endif

static void resultline(int i, int j, int TESTS_QUIET)
{
   float real_time, proc_time, mflops, ferror = 0;
   long_long flpins = 0;
   int papi, theory, diff = 0;
   int retval;

   retval = PAPI_flops(&real_time, &proc_time, &flpins, &mflops);
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "resultline: PAPI_flops", retval);

   i++;                         /* convert to 1s base  */
   theory = 2;
   while (j--)
      theory *= i;              /* theoretical ops   */
   papi = (int) (flpins) << FMA;

   diff = papi - theory;

   ferror = ((float) abs(diff)) / ((float) theory) * 100;

   if (!TESTS_QUIET)
      printf("%8d %12d %12d %8d %10.4f\n", i, papi, theory, diff, ferror);

#ifndef DONT_FAIL
   if (ferror > MAX_ERROR && diff > MAX_DIFF)
#if defined(__ALPHA) && defined(__osf__)
      if (!TESTS_QUIET)
         fprintf(stderr, "Calibrate: error exceeds %d percent\n", MAX_ERROR);
#else
      test_fail(__FILE__, __LINE__, "Calibrate: error exceeds 10%", PAPI_EMISC);
#endif
#endif
}
