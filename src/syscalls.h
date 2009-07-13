
#ifndef _SYSCALLS_H
#define _SYSCALLS_H

#include <unistd.h>
/*# #include <linux/linkage.h> */

/* asmlinkage */ long sys_perf_counter_open(struct perf_counter_attr *hw_event,
				     pid_t pid, int cpu, int group_fd, unsigned long flags);
#endif
