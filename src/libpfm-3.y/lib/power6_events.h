/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

#ifndef __POWER6_EVENTS_H__
#define __POWER6_EVENTS_H__

/*
* File:    power6_events.h
* CVS:
* Author:  Corey Ashford
*          cjashfor@us.ibm.com
* Mods:    <your name here>
*          <your email address>
*
* (C) Copyright IBM Corporation, 2007.  All Rights Reserved.
* Contributed by Corey Ashford <cjashfor.ibm.com>
*
* Note: This code was automatically generated and should not be modified by
* hand.
*
*/
static pme_power6_entry_t power6_pe[] = {
#define POWER6_PME_PM_LSU_REJECT_STQ_FULL 0
	[ POWER6_PME_PM_LSU_REJECT_STQ_FULL ] = {
		.pme_name = "PM_LSU_REJECT_STQ_FULL",
		.pme_short_desc = "LSU reject due to store queue full",
		.pme_long_desc = "LSU reject due to store queue full",
		.pme_event_ids = { 243, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_FXU_MULTI 1
	[ POWER6_PME_PM_DPU_HELD_FXU_MULTI ] = {
		.pme_name = "PM_DPU_HELD_FXU_MULTI",
		.pme_short_desc = "DISP unit held due to FXU multicycle",
		.pme_long_desc = "DISP unit held due to FXU multicycle",
		.pme_event_ids = { 37, 45, 36, 44, -1, -1 },
		.pme_group_vector = {
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX1_STALL 2
	[ POWER6_PME_PM_VMX1_STALL ] = {
		.pme_name = "PM_VMX1_STALL",
		.pme_short_desc = "VMX1 stall",
		.pme_long_desc = "VMX1 stall",
		.pme_event_ids = { 328, 335, 322, 320, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000001000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC2_SAVED 3
	[ POWER6_PME_PM_PMC2_SAVED ] = {
		.pme_name = "PM_PMC2_SAVED",
		.pme_short_desc = "PMC2 rewind value saved",
		.pme_long_desc = "PMC2 rewind value saved",
		.pme_event_ids = { 291, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_IC_INV 4
	[ POWER6_PME_PM_L2SB_IC_INV ] = {
		.pme_name = "PM_L2SB_IC_INV",
		.pme_short_desc = "L2 slice B I cache invalidate",
		.pme_long_desc = "L2 slice B I cache invalidate",
		.pme_event_ids = { 174, 183, 174, 180, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IERAT_MISS_64K 5
	[ POWER6_PME_PM_IERAT_MISS_64K ] = {
		.pme_name = "PM_IERAT_MISS_64K",
		.pme_short_desc = "IERAT misses for 64K page",
		.pme_long_desc = "IERAT misses for 64K page",
		.pme_event_ids = { -1, -1, 344, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_3or4_CYC 6
	[ POWER6_PME_PM_THRD_PRIO_DIFF_3or4_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_3or4_CYC",
		.pme_short_desc = "Cycles thread priority difference is 3 or 4",
		.pme_long_desc = "Cycles thread priority difference is 3 or 4",
		.pme_event_ids = { -1, -1, 310, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000010000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LD_REF_L1_BOTH 7
	[ POWER6_PME_PM_LD_REF_L1_BOTH ] = {
		.pme_name = "PM_LD_REF_L1_BOTH",
		.pme_short_desc = "Both units L1 D cache load reference",
		.pme_long_desc = "Both units L1 D cache load reference",
		.pme_event_ids = { 202, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000400000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FCONV 8
	[ POWER6_PME_PM_FPU1_FCONV ] = {
		.pme_name = "PM_FPU1_FCONV",
		.pme_short_desc = "FPU1 executed FCONV instruction",
		.pme_long_desc = "FPU1 executed FCONV instruction",
		.pme_event_ids = { 88, 97, 86, 94, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x4000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IBUF_FULL_COUNT 9
	[ POWER6_PME_PM_IBUF_FULL_COUNT ] = {
		.pme_name = "PM_IBUF_FULL_COUNT",
		.pme_short_desc = "Periods instruction buffer full",
		.pme_long_desc = "Periods instruction buffer full",
		.pme_event_ids = { 338, 345, 332, 330, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU_DERAT_MISS 10
	[ POWER6_PME_PM_MRK_LSU_DERAT_MISS ] = {
		.pme_name = "PM_MRK_LSU_DERAT_MISS",
		.pme_short_desc = "Marked DERAT miss",
		.pme_long_desc = "Marked DERAT miss",
		.pme_event_ids = { -1, -1, -1, 271, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000800000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_ST_CMPL 11
	[ POWER6_PME_PM_MRK_ST_CMPL ] = {
		.pme_name = "PM_MRK_ST_CMPL",
		.pme_short_desc = "Marked store instruction completed",
		.pme_long_desc = "A sampled store has completed (data home)",
		.pme_event_ids = { 282, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_CASTOUT_MOD 12
	[ POWER6_PME_PM_L2_CASTOUT_MOD ] = {
		.pme_name = "PM_L2_CASTOUT_MOD",
		.pme_short_desc = "L2 castouts - Modified (M",
		.pme_long_desc = " Mu",
		.pme_event_ids = { 185, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_ST_FOLDED 13
	[ POWER6_PME_PM_FPU1_ST_FOLDED ] = {
		.pme_name = "PM_FPU1_ST_FOLDED",
		.pme_short_desc = "FPU1 folded store",
		.pme_long_desc = "FPU1 folded store",
		.pme_event_ids = { 100, 109, 98, 106, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x4000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_INST_TIMEO 14
	[ POWER6_PME_PM_MRK_INST_TIMEO ] = {
		.pme_name = "PM_MRK_INST_TIMEO",
		.pme_short_desc = "Marked Instruction finish timeout ",
		.pme_long_desc = "Marked Instruction finish timeout ",
		.pme_event_ids = { -1, -1, -1, 263, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000400000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_WT 15
	[ POWER6_PME_PM_DPU_WT ] = {
		.pme_name = "PM_DPU_WT",
		.pme_short_desc = "Cycles DISP unit is stalled waiting for instructions",
		.pme_long_desc = "Cycles DISP unit is stalled waiting for instructions",
		.pme_event_ids = { -1, -1, 54, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000800000000ULL,
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_RESTART 16
	[ POWER6_PME_PM_DPU_HELD_RESTART ] = {
		.pme_name = "PM_DPU_HELD_RESTART",
		.pme_short_desc = "DISP unit held after restart coming",
		.pme_long_desc = "DISP unit held after restart coming",
		.pme_event_ids = { 47, 56, 46, 54, -1, -1 },
		.pme_group_vector = {
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IERAT_MISS 17
	[ POWER6_PME_PM_IERAT_MISS ] = {
		.pme_name = "PM_IERAT_MISS",
		.pme_short_desc = "IERAT miss count",
		.pme_long_desc = "IERAT miss count",
		.pme_event_ids = { 137, 146, 136, 143, -1, -1 },
		.pme_group_vector = {
			0x0400000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_SINGLE 18
	[ POWER6_PME_PM_FPU_SINGLE ] = {
		.pme_name = "PM_FPU_SINGLE",
		.pme_short_desc = "FPU executed single precision instruction",
		.pme_long_desc = "FPU is executing single precision instruction. Combined Unit 0 + Unit 1",
		.pme_event_ids = { -1, -1, -1, 122, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_LMEM 19
	[ POWER6_PME_PM_MRK_PTEG_FROM_LMEM ] = {
		.pme_name = "PM_MRK_PTEG_FROM_LMEM",
		.pme_short_desc = "Marked PTEG loaded from local memory",
		.pme_long_desc = "Marked PTEG loaded from local memory",
		.pme_event_ids = { -1, -1, -1, 278, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_HV_COUNT 20
	[ POWER6_PME_PM_HV_COUNT ] = {
		.pme_name = "PM_HV_COUNT",
		.pme_short_desc = "Hypervisor Periods",
		.pme_long_desc = "Periods when the processor is executing in Hypervisor (MSR[HV] = 1 and MSR[PR]=0)",
		.pme_event_ids = { -1, 351, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000800000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_ST_HIT 21
	[ POWER6_PME_PM_L2SA_ST_HIT ] = {
		.pme_name = "PM_L2SA_ST_HIT",
		.pme_short_desc = "L2 slice A store hits",
		.pme_long_desc = "A store request made from the core hit in the L2 directory.  This event is provided on each of the three L2 slices A,B, and C.",
		.pme_event_ids = { 168, 177, 168, 174, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0001000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_LD_MISS_INST 22
	[ POWER6_PME_PM_L2_LD_MISS_INST ] = {
		.pme_name = "PM_L2_LD_MISS_INST",
		.pme_short_desc = "L2 instruction load misses",
		.pme_long_desc = "L2 instruction load misses",
		.pme_event_ids = { -1, 196, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000004000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_EXT_INT 23
	[ POWER6_PME_PM_EXT_INT ] = {
		.pme_name = "PM_EXT_INT",
		.pme_short_desc = "External interrupts",
		.pme_long_desc = "An external interrupt occurred",
		.pme_event_ids = { -1, 67, 57, -1, -1, -1 },
		.pme_group_vector = {
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_LDF 24
	[ POWER6_PME_PM_LSU1_LDF ] = {
		.pme_name = "PM_LSU1_LDF",
		.pme_short_desc = "LSU1 executed Floating Point load instruction",
		.pme_long_desc = "A floating point load was executed from LSU unit 1",
		.pme_event_ids = { 221, 230, 216, 221, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_CMD_ISSUED 25
	[ POWER6_PME_PM_FAB_CMD_ISSUED ] = {
		.pme_name = "PM_FAB_CMD_ISSUED",
		.pme_short_desc = "Fabric command issued",
		.pme_long_desc = "Fabric command issued",
		.pme_event_ids = { 59, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000028000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L21 26
	[ POWER6_PME_PM_PTEG_FROM_L21 ] = {
		.pme_name = "PM_PTEG_FROM_L21",
		.pme_short_desc = "PTEG loaded from private L2 other core",
		.pme_long_desc = "PTEG loaded from private L2 other core",
		.pme_event_ids = { -1, 305, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000018000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_MISS 27
	[ POWER6_PME_PM_L2SA_MISS ] = {
		.pme_name = "PM_L2SA_MISS",
		.pme_short_desc = "L2 slice A misses",
		.pme_long_desc = "L2 slice A misses",
		.pme_event_ids = { 167, 176, 167, 173, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_RL2L3_MOD 28
	[ POWER6_PME_PM_PTEG_FROM_RL2L3_MOD ] = {
		.pme_name = "PM_PTEG_FROM_RL2L3_MOD",
		.pme_short_desc = "PTEG loaded from remote L2 or L3 modified",
		.pme_long_desc = "PTEG loaded from remote L2 or L3 modified",
		.pme_event_ids = { 299, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_WT_COUNT 29
	[ POWER6_PME_PM_DPU_WT_COUNT ] = {
		.pme_name = "PM_DPU_WT_COUNT",
		.pme_short_desc = "Periods DISP unit is stalled waiting for instructions",
		.pme_long_desc = "Periods DISP unit is stalled waiting for instructions",
		.pme_event_ids = { -1, -1, 340, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0002040000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L25_MOD 30
	[ POWER6_PME_PM_MRK_PTEG_FROM_L25_MOD ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L25_MOD",
		.pme_short_desc = "Marked PTEG loaded from L2.5 modified",
		.pme_long_desc = "Marked PTEG loaded from L2.5 modified",
		.pme_event_ids = { -1, -1, 272, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000008000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LD_HIT_L2 31
	[ POWER6_PME_PM_LD_HIT_L2 ] = {
		.pme_name = "PM_LD_HIT_L2",
		.pme_short_desc = "L2 D cache load hits",
		.pme_long_desc = "L2 D cache load hits",
		.pme_event_ids = { -1, 209, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000010000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_DL2L3_SHR 32
	[ POWER6_PME_PM_PTEG_FROM_DL2L3_SHR ] = {
		.pme_name = "PM_PTEG_FROM_DL2L3_SHR",
		.pme_short_desc = "PTEG loaded from distant L2 or L3 shared",
		.pme_long_desc = "PTEG loaded from distant L2 or L3 shared",
		.pme_event_ids = { -1, -1, 290, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM_DP_RQ_GLOB_LOC 33
	[ POWER6_PME_PM_MEM_DP_RQ_GLOB_LOC ] = {
		.pme_name = "PM_MEM_DP_RQ_GLOB_LOC",
		.pme_short_desc = "Memory read queue marking cache line double pump state from global to local",
		.pme_long_desc = "Memory read queue marking cache line double pump state from global to local",
		.pme_event_ids = { 257, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L3SA_MISS 34
	[ POWER6_PME_PM_L3SA_MISS ] = {
		.pme_name = "PM_L3SA_MISS",
		.pme_short_desc = "L3 slice A misses",
		.pme_long_desc = "L3 slice A misses",
		.pme_event_ids = { 192, 202, 190, 195, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_NO_ITAG_COUNT 35
	[ POWER6_PME_PM_NO_ITAG_COUNT ] = {
		.pme_name = "PM_NO_ITAG_COUNT",
		.pme_short_desc = "Periods no ITAG available",
		.pme_long_desc = "Periods no ITAG available",
		.pme_event_ids = { 340, 347, 334, 332, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DSLB_MISS 36
	[ POWER6_PME_PM_DSLB_MISS ] = {
		.pme_name = "PM_DSLB_MISS",
		.pme_short_desc = "Data SLB misses",
		.pme_long_desc = "A SLB miss for a data request occurred. SLB misses trap to the operating system to resolve",
		.pme_event_ids = { 56, 65, 55, 63, -1, -1 },
		.pme_group_vector = {
			0x0600000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_FLUSH_ALIGN 37
	[ POWER6_PME_PM_LSU_FLUSH_ALIGN ] = {
		.pme_name = "PM_LSU_FLUSH_ALIGN",
		.pme_short_desc = "Flush caused by alignement exception",
		.pme_long_desc = "Flush caused by alignement exception",
		.pme_event_ids = { 235, 244, 229, 235, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_FPU_CR 38
	[ POWER6_PME_PM_DPU_HELD_FPU_CR ] = {
		.pme_name = "PM_DPU_HELD_FPU_CR",
		.pme_short_desc = "DISP unit held due to FPU updating CR",
		.pme_long_desc = "DISP unit held due to FPU updating CR",
		.pme_event_ids = { 35, 43, 34, 42, -1, -1 },
		.pme_group_vector = {
			0x0000188000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L2MISS 39
	[ POWER6_PME_PM_PTEG_FROM_L2MISS ] = {
		.pme_name = "PM_PTEG_FROM_L2MISS",
		.pme_short_desc = "PTEG loaded from L2 miss",
		.pme_long_desc = "PTEG loaded from L2 miss",
		.pme_event_ids = { 296, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_DMEM 40
	[ POWER6_PME_PM_MRK_DATA_FROM_DMEM ] = {
		.pme_name = "PM_MRK_DATA_FROM_DMEM",
		.pme_short_desc = "Marked data loaded from distant memory",
		.pme_long_desc = "Marked data loaded from distant memory",
		.pme_event_ids = { -1, 269, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_COMPLEX_ISUED 41
	[ POWER6_PME_PM_VMX_COMPLEX_ISUED ] = {
		.pme_name = "PM_VMX_COMPLEX_ISUED",
		.pme_short_desc = "VMX instruction issued to complex",
		.pme_long_desc = "VMX instruction issued to complex",
		.pme_event_ids = { 329, 336, 323, 321, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000100000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_LMEM 42
	[ POWER6_PME_PM_PTEG_FROM_LMEM ] = {
		.pme_name = "PM_PTEG_FROM_LMEM",
		.pme_short_desc = "PTEG loaded from local memory",
		.pme_long_desc = "PTEG loaded from local memory",
		.pme_event_ids = { -1, -1, -1, 291, -1, -1 },
		.pme_group_vector = {
			0x0000000060000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_REF_64K 43
	[ POWER6_PME_PM_MRK_DERAT_REF_64K ] = {
		.pme_name = "PM_MRK_DERAT_REF_64K",
		.pme_short_desc = "Marked DERAT reference for 64K page",
		.pme_long_desc = "Marked DERAT reference for 64K page",
		.pme_event_ids = { 353, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000000000000010ULL }
	},
#define POWER6_PME_PM_L2SA_LD_REQ_INST 44
	[ POWER6_PME_PM_L2SA_LD_REQ_INST ] = {
		.pme_name = "PM_L2SA_LD_REQ_INST",
		.pme_short_desc = "L2 slice A instruction load requests",
		.pme_long_desc = "L2 slice A instruction load requests",
		.pme_event_ids = { 166, 175, 166, 172, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_MISS_16M 45
	[ POWER6_PME_PM_MRK_DERAT_MISS_16M ] = {
		.pme_name = "PM_MRK_DERAT_MISS_16M",
		.pme_short_desc = "Marked DERAT misses for 16M page",
		.pme_long_desc = "A marked data request (load or store) missed the ERAT for 16M page and resulted in an ERAT reload.",
		.pme_event_ids = { -1, -1, 346, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_DL2L3_MOD 46
	[ POWER6_PME_PM_DATA_FROM_DL2L3_MOD ] = {
		.pme_name = "PM_DATA_FROM_DL2L3_MOD",
		.pme_short_desc = "Data loaded from distant L2 or L3 modified",
		.pme_long_desc = "Data loaded from distant L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 13, -1, -1 },
		.pme_group_vector = {
			0x0000000000000400ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FXMULT 47
	[ POWER6_PME_PM_FPU0_FXMULT ] = {
		.pme_name = "PM_FPU0_FXMULT",
		.pme_short_desc = "FPU0 executed fixed point multiplication",
		.pme_long_desc = "FPU0 executed fixed point multiplication",
		.pme_event_ids = { 82, 91, 80, 88, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0200000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L3SB_MISS 48
	[ POWER6_PME_PM_L3SB_MISS ] = {
		.pme_name = "PM_L3SB_MISS",
		.pme_short_desc = "L3 slice B misses",
		.pme_long_desc = "L3 slice B misses",
		.pme_event_ids = { 195, 205, 193, 198, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0008000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_STCX_CANCEL 49
	[ POWER6_PME_PM_STCX_CANCEL ] = {
		.pme_name = "PM_STCX_CANCEL",
		.pme_short_desc = "stcx cancel by core",
		.pme_long_desc = "stcx cancel by core",
		.pme_event_ids = { 305, 311, 297, 296, -1, -1 },
		.pme_group_vector = {
			0x0008000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_LD_MISS_DATA 50
	[ POWER6_PME_PM_L2SA_LD_MISS_DATA ] = {
		.pme_name = "PM_L2SA_LD_MISS_DATA",
		.pme_short_desc = "L2 slice A data load misses",
		.pme_long_desc = "L2 slice A data load misses",
		.pme_event_ids = { 162, 171, 162, 168, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_INV_L2 51
	[ POWER6_PME_PM_IC_INV_L2 ] = {
		.pme_name = "PM_IC_INV_L2",
		.pme_short_desc = "L1 I cache entries invalidated from L2",
		.pme_long_desc = "L1 I cache entries invalidated from L2",
		.pme_event_ids = { -1, 141, 131, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD 52
	[ POWER6_PME_PM_DPU_HELD ] = {
		.pme_name = "PM_DPU_HELD",
		.pme_short_desc = "DISP unit held",
		.pme_long_desc = "DISP unit held",
		.pme_event_ids = { -1, 38, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC1_OVERFLOW 53
	[ POWER6_PME_PM_PMC1_OVERFLOW ] = {
		.pme_name = "PM_PMC1_OVERFLOW",
		.pme_short_desc = "PMC1 Overflow",
		.pme_long_desc = "PMC1 Overflow",
		.pme_event_ids = { -1, 303, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_6_CYC 54
	[ POWER6_PME_PM_THRD_PRIO_6_CYC ] = {
		.pme_name = "PM_THRD_PRIO_6_CYC",
		.pme_short_desc = "Cycles thread running at priority level 6",
		.pme_long_desc = "Cycles thread running at priority level 6",
		.pme_event_ids = { -1, 323, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000008000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L3MISS 55
	[ POWER6_PME_PM_MRK_PTEG_FROM_L3MISS ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L3MISS",
		.pme_short_desc = "Marked PTEG loaded from L3 miss",
		.pme_long_desc = "Marked PTEG loaded from L3 miss",
		.pme_event_ids = { -1, -1, 274, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU0_REJECT_UST 56
	[ POWER6_PME_PM_MRK_LSU0_REJECT_UST ] = {
		.pme_name = "PM_MRK_LSU0_REJECT_UST",
		.pme_short_desc = "LSU0 marked unaligned store reject",
		.pme_long_desc = "LSU0 marked unaligned store reject",
		.pme_event_ids = { 272, 284, 266, 267, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_INST_DISP 57
	[ POWER6_PME_PM_MRK_INST_DISP ] = {
		.pme_name = "PM_MRK_INST_DISP",
		.pme_short_desc = "Marked instruction dispatched",
		.pme_long_desc = "Marked instruction dispatched",
		.pme_event_ids = { 267, 279, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LARX 58
	[ POWER6_PME_PM_LARX ] = {
		.pme_name = "PM_LARX",
		.pme_short_desc = "Larx executed",
		.pme_long_desc = "Larx executed",
		.pme_event_ids = { 197, 207, 195, 200, -1, -1 },
		.pme_group_vector = {
			0x0018000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_CMPL 59
	[ POWER6_PME_PM_INST_CMPL ] = {
		.pme_name = "PM_INST_CMPL",
		.pme_short_desc = "Instructions completed",
		.pme_long_desc = "Number of PPC instructions completed. ",
		.pme_event_ids = { 139, 148, 138, 145, -1, -1 },
		.pme_group_vector = {
			0x0100000000006001ULL,
			0x0000000000000000ULL,
			0x3800003ffffffe18ULL,
			0x0000000000000038ULL }
	},
#define POWER6_PME_PM_FXU_IDLE 60
	[ POWER6_PME_PM_FXU_IDLE ] = {
		.pme_name = "PM_FXU_IDLE",
		.pme_short_desc = "FXU idle",
		.pme_long_desc = "FXU0 and FXU1 are both idle",
		.pme_event_ids = { 117, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_DL2L3_MOD 61
	[ POWER6_PME_PM_MRK_DATA_FROM_DL2L3_MOD ] = {
		.pme_name = "PM_MRK_DATA_FROM_DL2L3_MOD",
		.pme_short_desc = "Marked data loaded from distant L2 or L3 modified",
		.pme_long_desc = "Marked data loaded from distant L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 256, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_LD_REQ_DATA 62
	[ POWER6_PME_PM_L2_LD_REQ_DATA ] = {
		.pme_name = "PM_L2_LD_REQ_DATA",
		.pme_short_desc = "L2 data load requests",
		.pme_long_desc = "L2 data load requests",
		.pme_event_ids = { 186, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_DERAT_MISS_CYC 63
	[ POWER6_PME_PM_LSU_DERAT_MISS_CYC ] = {
		.pme_name = "PM_LSU_DERAT_MISS_CYC",
		.pme_short_desc = "DERAT miss latency",
		.pme_long_desc = "DERAT miss latency",
		.pme_event_ids = { 234, -1, -1, 234, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0040000000000020ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_POWER_COUNT 64
	[ POWER6_PME_PM_DPU_HELD_POWER_COUNT ] = {
		.pme_name = "PM_DPU_HELD_POWER_COUNT",
		.pme_short_desc = "Periods DISP unit held due to Power Management",
		.pme_long_desc = "Periods DISP unit held due to Power Management",
		.pme_event_ids = { -1, 356, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0100020000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_RL2L3_MOD 65
	[ POWER6_PME_PM_INST_FROM_RL2L3_MOD ] = {
		.pme_name = "PM_INST_FROM_RL2L3_MOD",
		.pme_short_desc = "Instruction fetched from remote L2 or L3 modified",
		.pme_long_desc = "Instruction fetched from remote L2 or L3 modified",
		.pme_event_ids = { 146, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000001000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_DMEM_CYC 66
	[ POWER6_PME_PM_DATA_FROM_DMEM_CYC ] = {
		.pme_name = "PM_DATA_FROM_DMEM_CYC",
		.pme_short_desc = "Load latency from distant memory",
		.pme_long_desc = "Load latency from distant memory",
		.pme_event_ids = { -1, 14, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000004000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_DMEM 67
	[ POWER6_PME_PM_DATA_FROM_DMEM ] = {
		.pme_name = "PM_DATA_FROM_DMEM",
		.pme_short_desc = "Data loaded from distant memory",
		.pme_long_desc = "Data loaded from distant memory",
		.pme_event_ids = { -1, 13, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000800ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_PARTIAL_SECTOR 68
	[ POWER6_PME_PM_LSU_REJECT_PARTIAL_SECTOR ] = {
		.pme_name = "PM_LSU_REJECT_PARTIAL_SECTOR",
		.pme_short_desc = "LSU reject due to partial sector valid",
		.pme_long_desc = "LSU reject due to partial sector valid",
		.pme_event_ids = { 241, -1, -1, 242, -1, -1 },
		.pme_group_vector = {
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_DERAT_MPRED 69
	[ POWER6_PME_PM_LSU_REJECT_DERAT_MPRED ] = {
		.pme_name = "PM_LSU_REJECT_DERAT_MPRED",
		.pme_short_desc = "LSU reject due to mispredicted DERAT",
		.pme_long_desc = "LSU reject due to mispredicted DERAT",
		.pme_event_ids = { -1, 249, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_ULD 70
	[ POWER6_PME_PM_LSU1_REJECT_ULD ] = {
		.pme_name = "PM_LSU1_REJECT_ULD",
		.pme_short_desc = "LSU1 unaligned load reject",
		.pme_long_desc = "LSU1 unaligned load reject",
		.pme_event_ids = { 231, 240, 226, 231, -1, -1 },
		.pme_group_vector = {
			0x8000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L3_CYC 71
	[ POWER6_PME_PM_DATA_FROM_L3_CYC ] = {
		.pme_name = "PM_DATA_FROM_L3_CYC",
		.pme_short_desc = "Load latency from L3",
		.pme_long_desc = "Load latency from L3",
		.pme_event_ids = { -1, 21, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000010000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FXU1_BUSY_FXU0_IDLE 72
	[ POWER6_PME_PM_FXU1_BUSY_FXU0_IDLE ] = {
		.pme_name = "PM_FXU1_BUSY_FXU0_IDLE",
		.pme_short_desc = "FXU1 busy FXU0 idle",
		.pme_long_desc = "FXU0 was idle while FXU1 was busy",
		.pme_event_ids = { -1, -1, -1, 124, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_MEM_DP 73
	[ POWER6_PME_PM_INST_FROM_MEM_DP ] = {
		.pme_name = "PM_INST_FROM_MEM_DP",
		.pme_short_desc = "Instruction fetched from double pump memory",
		.pme_long_desc = "Instruction fetched from double pump memory",
		.pme_event_ids = { 145, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_FLUSH_DSI 74
	[ POWER6_PME_PM_LSU_FLUSH_DSI ] = {
		.pme_name = "PM_LSU_FLUSH_DSI",
		.pme_short_desc = "Flush caused by DSI",
		.pme_long_desc = "Flush caused by DSI",
		.pme_event_ids = { 236, 245, 230, 236, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_REF_16G 75
	[ POWER6_PME_PM_MRK_DERAT_REF_16G ] = {
		.pme_name = "PM_MRK_DERAT_REF_16G",
		.pme_short_desc = "Marked DERAT reference for 16G page",
		.pme_long_desc = "Marked DERAT reference for 16G page",
		.pme_event_ids = { -1, -1, -1, 345, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000010ULL }
	},
#define POWER6_PME_PM_LSU_LDF_BOTH 76
	[ POWER6_PME_PM_LSU_LDF_BOTH ] = {
		.pme_name = "PM_LSU_LDF_BOTH",
		.pme_short_desc = "Both LSU units executed Floating Point load instruction",
		.pme_long_desc = "Both LSU units executed Floating Point load instruction",
		.pme_event_ids = { 237, -1, 232, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_1FLOP 77
	[ POWER6_PME_PM_FPU1_1FLOP ] = {
		.pme_name = "PM_FPU1_1FLOP",
		.pme_short_desc = "FPU1 executed add",
		.pme_long_desc = " mult",
		.pme_event_ids = { 86, 95, 84, 92, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_RMEM_CYC 78
	[ POWER6_PME_PM_DATA_FROM_RMEM_CYC ] = {
		.pme_name = "PM_DATA_FROM_RMEM_CYC",
		.pme_short_desc = "Load latency from remote memory",
		.pme_long_desc = "Load latency from remote memory",
		.pme_event_ids = { -1, -1, -1, 23, -1, -1 },
		.pme_group_vector = {
			0x0000000000004000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_PTEG_SECONDARY 79
	[ POWER6_PME_PM_INST_PTEG_SECONDARY ] = {
		.pme_name = "PM_INST_PTEG_SECONDARY",
		.pme_short_desc = "Instruction table walk matched in secondary PTEG",
		.pme_long_desc = "Instruction table walk matched in secondary PTEG",
		.pme_event_ids = { 150, 159, 150, 156, -1, -1 },
		.pme_group_vector = {
			0x0000000200000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L1_ICACHE_MISS 80
	[ POWER6_PME_PM_L1_ICACHE_MISS ] = {
		.pme_name = "PM_L1_ICACHE_MISS",
		.pme_short_desc = "L1 I cache miss count",
		.pme_long_desc = "L1 I cache miss count",
		.pme_event_ids = { 154, 163, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000800000000ULL,
			0x0000000000000000ULL,
			0x0000040000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_DISP_LLA 81
	[ POWER6_PME_PM_INST_DISP_LLA ] = {
		.pme_name = "PM_INST_DISP_LLA",
		.pme_short_desc = "Instruction dispatched under load look ahead",
		.pme_long_desc = "Instruction dispatched under load look ahead",
		.pme_event_ids = { 140, 150, 140, 146, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000001000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_BOTH_RUN_CYC 82
	[ POWER6_PME_PM_THRD_BOTH_RUN_CYC ] = {
		.pme_name = "PM_THRD_BOTH_RUN_CYC",
		.pme_short_desc = "Both threads in run cycles",
		.pme_long_desc = "Both threads in run cycles",
		.pme_event_ids = { -1, -1, -1, 304, -1, -1 },
		.pme_group_vector = {
			0x0020000000000000ULL,
			0x0000000000000000ULL,
			0x0200000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_ST_CHAINED 83
	[ POWER6_PME_PM_LSU_ST_CHAINED ] = {
		.pme_name = "PM_LSU_ST_CHAINED",
		.pme_short_desc = "number of chained stores",
		.pme_long_desc = "number of chained stores",
		.pme_event_ids = { 246, 257, 240, 245, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FXDIV 84
	[ POWER6_PME_PM_FPU1_FXDIV ] = {
		.pme_name = "PM_FPU1_FXDIV",
		.pme_short_desc = "FPU1 executed fixed point division",
		.pme_long_desc = "FPU1 executed fixed point division",
		.pme_event_ids = { 96, 105, 94, 102, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FREQ_UP 85
	[ POWER6_PME_PM_FREQ_UP ] = {
		.pme_name = "PM_FREQ_UP",
		.pme_short_desc = "Frequency is being slewed up due to Power Management",
		.pme_long_desc = "Frequency is being slewed up due to Power Management",
		.pme_event_ids = { -1, -1, -1, 123, -1, -1 },
		.pme_group_vector = {
			0x0000000400000000ULL,
			0x0000000000000000ULL,
			0x0000020000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_RETRY_SYS_PUMP 86
	[ POWER6_PME_PM_FAB_RETRY_SYS_PUMP ] = {
		.pme_name = "PM_FAB_RETRY_SYS_PUMP",
		.pme_short_desc = "Retry of a system pump",
		.pme_long_desc = " locally mastered  ",
		.pme_event_ids = { 65, 75, 64, 71, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_LMEM 87
	[ POWER6_PME_PM_DATA_FROM_LMEM ] = {
		.pme_name = "PM_DATA_FROM_LMEM",
		.pme_short_desc = "Data loaded from local memory",
		.pme_long_desc = "Data loaded from local memory",
		.pme_event_ids = { -1, -1, -1, 20, -1, -1 },
		.pme_group_vector = {
			0x0000000000100800ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC3_OVERFLOW 88
	[ POWER6_PME_PM_PMC3_OVERFLOW ] = {
		.pme_name = "PM_PMC3_OVERFLOW",
		.pme_short_desc = "PMC3 Overflow",
		.pme_long_desc = "PMC3 Overflow",
		.pme_event_ids = { -1, -1, -1, 288, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_SET_MPRED 89
	[ POWER6_PME_PM_LSU0_REJECT_SET_MPRED ] = {
		.pme_name = "PM_LSU0_REJECT_SET_MPRED",
		.pme_short_desc = "LSU0 reject due to mispredicted set",
		.pme_long_desc = "LSU0 reject due to mispredicted set",
		.pme_event_ids = { 216, 225, 211, 216, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000001ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_DERAT_MPRED 90
	[ POWER6_PME_PM_LSU0_REJECT_DERAT_MPRED ] = {
		.pme_name = "PM_LSU0_REJECT_DERAT_MPRED",
		.pme_short_desc = "LSU0 reject due to mispredicted DERAT",
		.pme_long_desc = "LSU0 reject due to mispredicted DERAT",
		.pme_event_ids = { 209, 218, 204, 209, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000084ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_STQ_FULL 91
	[ POWER6_PME_PM_LSU1_REJECT_STQ_FULL ] = {
		.pme_name = "PM_LSU1_REJECT_STQ_FULL",
		.pme_short_desc = "LSU1 reject due to store queue full",
		.pme_long_desc = "LSU1 reject due to store queue full",
		.pme_event_ids = { 230, 239, 225, 230, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000040ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_BR_MPRED 92
	[ POWER6_PME_PM_MRK_BR_MPRED ] = {
		.pme_name = "PM_MRK_BR_MPRED",
		.pme_short_desc = "Marked branch mispredicted",
		.pme_long_desc = "Marked branch mispredicted",
		.pme_event_ids = { -1, -1, 251, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_ST_MISS 93
	[ POWER6_PME_PM_L2SA_ST_MISS ] = {
		.pme_name = "PM_L2SA_ST_MISS",
		.pme_short_desc = "L2 slice A store misses",
		.pme_long_desc = "L2 slice A store misses",
		.pme_event_ids = { 169, 178, 169, 175, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000080000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_EXTERN 94
	[ POWER6_PME_PM_LSU0_REJECT_EXTERN ] = {
		.pme_name = "PM_LSU0_REJECT_EXTERN",
		.pme_short_desc = "LSU0 external reject request ",
		.pme_long_desc = "LSU0 external reject request ",
		.pme_event_ids = { 210, 219, 205, 210, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000008ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_BR_TAKEN 95
	[ POWER6_PME_PM_MRK_BR_TAKEN ] = {
		.pme_name = "PM_MRK_BR_TAKEN",
		.pme_short_desc = "Marked branch taken",
		.pme_long_desc = "Marked branch taken",
		.pme_event_ids = { 258, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ISLB_MISS 96
	[ POWER6_PME_PM_ISLB_MISS ] = {
		.pme_name = "PM_ISLB_MISS",
		.pme_short_desc = "Instruction SLB misses",
		.pme_long_desc = "A SLB miss for an instruction fetch as occurred",
		.pme_event_ids = { 152, 161, 152, 158, -1, -1 },
		.pme_group_vector = {
			0x0600000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_CYC 97
	[ POWER6_PME_PM_CYC ] = {
		.pme_name = "PM_CYC",
		.pme_short_desc = "Processor cycles",
		.pme_long_desc = "Processor cycles",
		.pme_event_ids = { 12, 11, 10, 12, -1, -1 },
		.pme_group_vector = {
			0x0100200000283003ULL,
			0x0000000000000000ULL,
			0x5c00000481000018ULL,
			0x0000000000000005ULL }
	},
#define POWER6_PME_PM_FPU_FXDIV 98
	[ POWER6_PME_PM_FPU_FXDIV ] = {
		.pme_name = "PM_FPU_FXDIV",
		.pme_short_desc = "FPU executed fixed point division",
		.pme_long_desc = "FPU executed fixed point division",
		.pme_event_ids = { 105, -1, -1, 110, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_LLA_END 99
	[ POWER6_PME_PM_DPU_HELD_LLA_END ] = {
		.pme_name = "PM_DPU_HELD_LLA_END",
		.pme_short_desc = "DISP unit held due to load look ahead ended",
		.pme_long_desc = "DISP unit held due to load look ahead ended",
		.pme_event_ids = { 43, 51, 42, 50, -1, -1 },
		.pme_group_vector = {
			0x0000020000000000ULL,
			0x0000000000001000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM0_DP_CL_WR_LOC 100
	[ POWER6_PME_PM_MEM0_DP_CL_WR_LOC ] = {
		.pme_name = "PM_MEM0_DP_CL_WR_LOC",
		.pme_short_desc = "cacheline write setting dp to local side 0",
		.pme_long_desc = "cacheline write setting dp to local side 0",
		.pme_event_ids = { 249, 260, 243, 248, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU_REJECT_ULD 101
	[ POWER6_PME_PM_MRK_LSU_REJECT_ULD ] = {
		.pme_name = "PM_MRK_LSU_REJECT_ULD",
		.pme_short_desc = "Marked unaligned load reject",
		.pme_long_desc = "Marked unaligned load reject",
		.pme_event_ids = { 276, -1, -1, 274, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000210000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_1PLUS_PPC_CMPL 102
	[ POWER6_PME_PM_1PLUS_PPC_CMPL ] = {
		.pme_name = "PM_1PLUS_PPC_CMPL",
		.pme_short_desc = "One or more PPC instruction completed",
		.pme_long_desc = "A group containing at least one PPC instruction completed. For microcoded instructions that span multiple groups, this will only occur once.",
		.pme_event_ids = { 1, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0040000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_DMEM 103
	[ POWER6_PME_PM_PTEG_FROM_DMEM ] = {
		.pme_name = "PM_PTEG_FROM_DMEM",
		.pme_short_desc = "PTEG loaded from distant memory",
		.pme_long_desc = "PTEG loaded from distant memory",
		.pme_event_ids = { -1, 304, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_WT_BR_MPRED_COUNT 104
	[ POWER6_PME_PM_DPU_WT_BR_MPRED_COUNT ] = {
		.pme_name = "PM_DPU_WT_BR_MPRED_COUNT",
		.pme_short_desc = "Periods DISP unit is stalled due to branch misprediction",
		.pme_long_desc = "Periods DISP unit is stalled due to branch misprediction",
		.pme_event_ids = { -1, -1, -1, 340, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0002040000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GCT_FULL_CYC 105
	[ POWER6_PME_PM_GCT_FULL_CYC ] = {
		.pme_name = "PM_GCT_FULL_CYC",
		.pme_short_desc = "Cycles GCT full",
		.pme_long_desc = "The ISU sends a signal indicating the gct is full. ",
		.pme_event_ids = { 120, 128, 119, 127, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L25_SHR 106
	[ POWER6_PME_PM_INST_FROM_L25_SHR ] = {
		.pme_name = "PM_INST_FROM_L25_SHR",
		.pme_short_desc = "Instruction fetched from L2.5 shared",
		.pme_long_desc = "Instruction fetched from L2.5 shared",
		.pme_event_ids = { -1, -1, -1, 150, -1, -1 },
		.pme_group_vector = {
			0x0000000000800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_MISS_4K 107
	[ POWER6_PME_PM_MRK_DERAT_MISS_4K ] = {
		.pme_name = "PM_MRK_DERAT_MISS_4K",
		.pme_short_desc = "Marked DERAT misses for 4K page",
		.pme_long_desc = "A marked data request (load or store) missed the ERAT for 4K page and resulted in an ERAT reload.",
		.pme_event_ids = { -1, 364, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000020ULL }
	},
#define POWER6_PME_PM_DC_PREF_STREAM_ALLOC 108
	[ POWER6_PME_PM_DC_PREF_STREAM_ALLOC ] = {
		.pme_name = "PM_DC_PREF_STREAM_ALLOC",
		.pme_short_desc = "D cache new prefetch stream allocated",
		.pme_long_desc = "A new Prefetch Stream was allocated",
		.pme_event_ids = { 22, 29, 21, 29, -1, -1 },
		.pme_group_vector = {
			0x0001000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FIN 109
	[ POWER6_PME_PM_FPU1_FIN ] = {
		.pme_name = "PM_FPU1_FIN",
		.pme_short_desc = "FPU1 produced a result",
		.pme_long_desc = "fp1 finished, produced a result. This only indicates finish, not completion. ",
		.pme_event_ids = { 90, 99, 88, 96, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_MPRED_TA 110
	[ POWER6_PME_PM_BR_MPRED_TA ] = {
		.pme_name = "PM_BR_MPRED_TA",
		.pme_short_desc = "Branch mispredictions due to target address",
		.pme_long_desc = "branch miss predict due to a target address prediction. This signal will be asserted each time the branch execution unit detects an incorrect target address prediction. This signal will be asserted after a valid branch execution unit issue and will cause a branch mispredict flush unless a flush is detected from an older instruction.",
		.pme_event_ids = { 7, 5, 5, 7, -1, -1 },
		.pme_group_vector = {
			0x0000000000000028ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_POWER 111
	[ POWER6_PME_PM_DPU_HELD_POWER ] = {
		.pme_name = "PM_DPU_HELD_POWER",
		.pme_short_desc = "DISP unit held due to Power Management",
		.pme_long_desc = "DISP unit held due to Power Management",
		.pme_event_ids = { -1, 55, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000001400000000ULL,
			0x0000000000000000ULL,
			0x0200000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_RUN_INST_CMPL 112
	[ POWER6_PME_PM_RUN_INST_CMPL ] = {
		.pme_name = "PM_RUN_INST_CMPL",
		.pme_short_desc = "Run instructions completed",
		.pme_long_desc = "Number of run instructions completed. ",
		.pme_event_ids = { -1, -1, -1, -1, 0, -1 },
		.pme_group_vector = {
			0xffffffffffffffffULL,
			0xffffffffffffffffULL,
			0xffffffffffffffffULL,
			0x000000000000003fULL }
	},
#define POWER6_PME_PM_GCT_EMPTY_CYC 113
	[ POWER6_PME_PM_GCT_EMPTY_CYC ] = {
		.pme_name = "PM_GCT_EMPTY_CYC",
		.pme_short_desc = "Cycles GCT empty",
		.pme_long_desc = "The Global Completion Table is completely empty",
		.pme_event_ids = { 119, 127, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LLA_COUNT 114
	[ POWER6_PME_PM_LLA_COUNT ] = {
		.pme_name = "PM_LLA_COUNT",
		.pme_short_desc = "Transitions into Load Look Ahead mode",
		.pme_long_desc = "Transitions into Load Look Ahead mode",
		.pme_event_ids = { 347, 354, 339, 339, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000080000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_NO_SCRATCH 115
	[ POWER6_PME_PM_LSU0_REJECT_NO_SCRATCH ] = {
		.pme_name = "PM_LSU0_REJECT_NO_SCRATCH",
		.pme_short_desc = "LSU0 reject due to scratch register not available",
		.pme_long_desc = "LSU0 reject due to scratch register not available",
		.pme_event_ids = { 214, 223, 209, 214, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000010ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_WT_IC_MISS 116
	[ POWER6_PME_PM_DPU_WT_IC_MISS ] = {
		.pme_name = "PM_DPU_WT_IC_MISS",
		.pme_short_desc = "Cycles DISP unit is stalled due to I cache miss",
		.pme_long_desc = "Cycles DISP unit is stalled due to I cache miss",
		.pme_event_ids = { -1, 64, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000800000000ULL,
			0x0000000000000000ULL,
			0x0000080000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L3MISS 117
	[ POWER6_PME_PM_DATA_FROM_L3MISS ] = {
		.pme_name = "PM_DATA_FROM_L3MISS",
		.pme_short_desc = "Data loaded from private L3 miss",
		.pme_long_desc = "Data loaded from private L3 miss",
		.pme_event_ids = { -1, -1, 15, 19, -1, -1 },
		.pme_group_vector = {
			0x0000000000000180ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000008ULL }
	},
#define POWER6_PME_PM_FPU_FPSCR 118
	[ POWER6_PME_PM_FPU_FPSCR ] = {
		.pme_name = "PM_FPU_FPSCR",
		.pme_short_desc = "FPU executed FPSCR instruction",
		.pme_long_desc = "FPU executed FPSCR instruction",
		.pme_event_ids = { -1, 112, 100, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000001ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX1_INST_ISSUED 119
	[ POWER6_PME_PM_VMX1_INST_ISSUED ] = {
		.pme_name = "PM_VMX1_INST_ISSUED",
		.pme_short_desc = "VMX1 instruction issued",
		.pme_long_desc = "VMX1 instruction issued",
		.pme_event_ids = { 325, 332, 319, 317, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000200000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FLUSH 120
	[ POWER6_PME_PM_FLUSH ] = {
		.pme_name = "PM_FLUSH",
		.pme_short_desc = "Flushes",
		.pme_long_desc = "Flushes",
		.pme_event_ids = { 67, -1, -1, 73, -1, -1 },
		.pme_group_vector = {
			0x0002000000080000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ST_HIT_L2 121
	[ POWER6_PME_PM_ST_HIT_L2 ] = {
		.pme_name = "PM_ST_HIT_L2",
		.pme_short_desc = "L2 D cache store hits",
		.pme_long_desc = "L2 D cache store hits",
		.pme_event_ids = { 308, -1, -1, 298, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000010000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_SYNC_CYC 122
	[ POWER6_PME_PM_SYNC_CYC ] = {
		.pme_name = "PM_SYNC_CYC",
		.pme_short_desc = "Sync duration",
		.pme_long_desc = "Sync duration",
		.pme_event_ids = { 312, 319, 303, 303, -1, -1 },
		.pme_group_vector = {
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0061800000000010ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_SYS_PUMP 123
	[ POWER6_PME_PM_FAB_SYS_PUMP ] = {
		.pme_name = "PM_FAB_SYS_PUMP",
		.pme_short_desc = "System pump operation",
		.pme_long_desc = " locally mastered",
		.pme_event_ids = { 66, 76, 65, 72, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_PREF_REQ 124
	[ POWER6_PME_PM_IC_PREF_REQ ] = {
		.pme_name = "PM_IC_PREF_REQ",
		.pme_short_desc = "Instruction prefetch requests",
		.pme_long_desc = "Asserted when a non-canceled prefetch is made to the cache interface unit (CIU).",
		.pme_event_ids = { 133, 142, 132, 139, -1, -1 },
		.pme_group_vector = {
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM0_DP_RQ_GLOB_LOC 125
	[ POWER6_PME_PM_MEM0_DP_RQ_GLOB_LOC ] = {
		.pme_name = "PM_MEM0_DP_RQ_GLOB_LOC",
		.pme_short_desc = "Memory read queue marking cache line double pump state from global to local side 0",
		.pme_long_desc = "Memory read queue marking cache line double pump state from global to local side 0",
		.pme_event_ids = { 250, 261, 244, 249, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_0 126
	[ POWER6_PME_PM_FPU_ISSUE_0 ] = {
		.pme_name = "PM_FPU_ISSUE_0",
		.pme_short_desc = "FPU issue 0 per cycle",
		.pme_long_desc = "FPU issue 0 per cycle",
		.pme_event_ids = { 107, 115, 103, 112, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_2_CYC 127
	[ POWER6_PME_PM_THRD_PRIO_2_CYC ] = {
		.pme_name = "PM_THRD_PRIO_2_CYC",
		.pme_short_desc = "Cycles thread running at priority level 2",
		.pme_long_desc = "Cycles thread running at priority level 2",
		.pme_event_ids = { -1, -1, 308, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000004000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_SIMPLE_ISSUED 128
	[ POWER6_PME_PM_VMX_SIMPLE_ISSUED ] = {
		.pme_name = "PM_VMX_SIMPLE_ISSUED",
		.pme_short_desc = "VMX instruction issued to simple",
		.pme_long_desc = "VMX instruction issued to simple",
		.pme_event_ids = { 335, 342, 329, 327, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000100000ULL,
			0x0000000400000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_FPU1_FIN 129
	[ POWER6_PME_PM_MRK_FPU1_FIN ] = {
		.pme_name = "PM_MRK_FPU1_FIN",
		.pme_short_desc = "Marked instruction FPU1 processing finished",
		.pme_long_desc = "Marked instruction FPU1 processing finished",
		.pme_event_ids = { 266, 275, 260, 261, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000800100000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_CW 130
	[ POWER6_PME_PM_DPU_HELD_CW ] = {
		.pme_name = "PM_DPU_HELD_CW",
		.pme_short_desc = "DISP unit held due to cache writes ",
		.pme_long_desc = "DISP unit held due to cache writes ",
		.pme_event_ids = { 33, 41, 32, 40, -1, -1 },
		.pme_group_vector = {
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L3SA_REF 131
	[ POWER6_PME_PM_L3SA_REF ] = {
		.pme_name = "PM_L3SA_REF",
		.pme_short_desc = "L3 slice A references",
		.pme_long_desc = "L3 slice A references",
		.pme_event_ids = { 193, 203, 191, 196, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_STCX 132
	[ POWER6_PME_PM_STCX ] = {
		.pme_name = "PM_STCX",
		.pme_short_desc = "STCX executed",
		.pme_long_desc = "STCX executed",
		.pme_event_ids = { 304, 310, 296, 295, -1, -1 },
		.pme_group_vector = {
			0x0018000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_MISS 133
	[ POWER6_PME_PM_L2SB_MISS ] = {
		.pme_name = "PM_L2SB_MISS",
		.pme_short_desc = "L2 slice B misses",
		.pme_long_desc = "L2 slice B misses",
		.pme_event_ids = { 181, 190, 181, 187, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT 134
	[ POWER6_PME_PM_LSU0_REJECT ] = {
		.pme_name = "PM_LSU0_REJECT",
		.pme_short_desc = "LSU0 reject",
		.pme_long_desc = "LSU0 reject",
		.pme_event_ids = { 208, 217, 203, 208, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000044ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_TB_BIT_TRANS 135
	[ POWER6_PME_PM_TB_BIT_TRANS ] = {
		.pme_name = "PM_TB_BIT_TRANS",
		.pme_short_desc = "Time Base bit transition",
		.pme_long_desc = "When the selected time base bit (as specified in MMCR0[TBSEL])transitions from 0 to 1 ",
		.pme_event_ids = { 313, -1, 304, -1, -1, -1 },
		.pme_group_vector = {
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THERMAL_MAX 136
	[ POWER6_PME_PM_THERMAL_MAX ] = {
		.pme_name = "PM_THERMAL_MAX",
		.pme_short_desc = "Processor in thermal MAX",
		.pme_long_desc = "Processor in thermal MAX",
		.pme_event_ids = { -1, -1, 305, -1, -1, -1 },
		.pme_group_vector = {
			0x0000001000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_STF 137
	[ POWER6_PME_PM_FPU0_STF ] = {
		.pme_name = "PM_FPU0_STF",
		.pme_short_desc = "FPU0 executed store instruction",
		.pme_long_desc = "This signal is active for one cycle when fp0 is executing a store instruction.",
		.pme_event_ids = { 84, 93, 82, 90, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FMA 138
	[ POWER6_PME_PM_FPU1_FMA ] = {
		.pme_name = "PM_FPU1_FMA",
		.pme_short_desc = "FPU1 executed multiply-add instruction",
		.pme_long_desc = "This signal is active for one cycle when fp1 is executing multiply-add kind of instruction. This could be fmadd*, fnmadd*, fmsub*, fnmsub* where XYZ* means XYZ, XYZs, XYZ., XYZs.",
		.pme_event_ids = { 92, 101, 90, 98, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_LHS 139
	[ POWER6_PME_PM_LSU1_REJECT_LHS ] = {
		.pme_name = "PM_LSU1_REJECT_LHS",
		.pme_short_desc = "LSU1 load hit store reject",
		.pme_long_desc = "LSU1 load hit store reject",
		.pme_event_ids = { 226, 235, 221, 226, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000020ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_INT 140
	[ POWER6_PME_PM_DPU_HELD_INT ] = {
		.pme_name = "PM_DPU_HELD_INT",
		.pme_short_desc = "DISP unit held due to exception",
		.pme_long_desc = "DISP unit held due to exception",
		.pme_event_ids = { 40, 48, 39, 47, -1, -1 },
		.pme_group_vector = {
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_LLA_BOTH_CYC 141
	[ POWER6_PME_PM_THRD_LLA_BOTH_CYC ] = {
		.pme_name = "PM_THRD_LLA_BOTH_CYC",
		.pme_short_desc = "Both threads in Load Look Ahead",
		.pme_long_desc = "Both threads in Load Look Ahead",
		.pme_event_ids = { -1, -1, -1, 306, -1, -1 },
		.pme_group_vector = {
			0x0040000000000000ULL,
			0x0000000000001000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_THERMAL_COUNT 142
	[ POWER6_PME_PM_DPU_HELD_THERMAL_COUNT ] = {
		.pme_name = "PM_DPU_HELD_THERMAL_COUNT",
		.pme_short_desc = "Periods DISP unit held due to thermal condition",
		.pme_long_desc = "Periods DISP unit held due to thermal condition",
		.pme_event_ids = { 348, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0002020000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC4_REWIND 143
	[ POWER6_PME_PM_PMC4_REWIND ] = {
		.pme_name = "PM_PMC4_REWIND",
		.pme_short_desc = "PMC4 rewind event",
		.pme_long_desc = "PMC4 rewind event",
		.pme_event_ids = { 293, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_REF_16M 144
	[ POWER6_PME_PM_DERAT_REF_16M ] = {
		.pme_name = "PM_DERAT_REF_16M",
		.pme_short_desc = "DERAT reference for 16M page",
		.pme_long_desc = "DERAT reference for 16M page",
		.pme_event_ids = { -1, -1, 342, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000080ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FCONV 145
	[ POWER6_PME_PM_FPU0_FCONV ] = {
		.pme_name = "PM_FPU0_FCONV",
		.pme_short_desc = "FPU0 executed FCONV instruction",
		.pme_long_desc = "FPU0 executed FCONV instruction",
		.pme_event_ids = { 73, 82, 71, 79, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0400000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_LD_REQ_DATA 146
	[ POWER6_PME_PM_L2SA_LD_REQ_DATA ] = {
		.pme_name = "PM_L2SA_LD_REQ_DATA",
		.pme_short_desc = "L2 slice A data load requests",
		.pme_long_desc = "L2 slice A data load requests",
		.pme_event_ids = { 165, 174, 165, 171, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_MEM_DP 147
	[ POWER6_PME_PM_DATA_FROM_MEM_DP ] = {
		.pme_name = "PM_DATA_FROM_MEM_DP",
		.pme_short_desc = "Data loaded from double pump memory",
		.pme_long_desc = "Data loaded from double pump memory",
		.pme_event_ids = { 15, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000020800ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX_FLOAT_ISSUED 148
	[ POWER6_PME_PM_MRK_VMX_FLOAT_ISSUED ] = {
		.pme_name = "PM_MRK_VMX_FLOAT_ISSUED",
		.pme_short_desc = "Marked VMX instruction issued to float",
		.pme_long_desc = "Marked VMX instruction issued to float",
		.pme_event_ids = { 286, 298, 281, 283, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L2MISS 149
	[ POWER6_PME_PM_MRK_PTEG_FROM_L2MISS ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L2MISS",
		.pme_short_desc = "Marked PTEG loaded from L2 miss",
		.pme_long_desc = "Marked PTEG loaded from L2 miss",
		.pme_event_ids = { -1, -1, -1, 277, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000020000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_1or2_CYC 150
	[ POWER6_PME_PM_THRD_PRIO_DIFF_1or2_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_1or2_CYC",
		.pme_short_desc = "Cycles thread priority difference is 1 or 2",
		.pme_long_desc = "Cycles thread priority difference is 1 or 2",
		.pme_event_ids = { -1, 324, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000010000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX0_STALL 151
	[ POWER6_PME_PM_VMX0_STALL ] = {
		.pme_name = "PM_VMX0_STALL",
		.pme_short_desc = "VMX0 stall",
		.pme_long_desc = "VMX0 stall",
		.pme_event_ids = { 324, 331, 318, 316, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000001000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_DEMAND_L2_BHT_REDIRECT 152
	[ POWER6_PME_PM_IC_DEMAND_L2_BHT_REDIRECT ] = {
		.pme_name = "PM_IC_DEMAND_L2_BHT_REDIRECT",
		.pme_short_desc = "L2 I cache demand request due to BHT redirect",
		.pme_long_desc = "L2 I cache demand request due to BHT redirect",
		.pme_event_ids = { 131, 139, 129, 137, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0002000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_DERAT_MISS 153
	[ POWER6_PME_PM_LSU_DERAT_MISS ] = {
		.pme_name = "PM_LSU_DERAT_MISS",
		.pme_short_desc = "DERAT misses",
		.pme_long_desc = "Total DERAT Misses (Unit 0 + Unit 1). Requests that miss the Derat are rejected and retried until the request hits in the Erat. This may result in multiple erat misses for the same instruction.",
		.pme_event_ids = { -1, 243, -1, 335, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0020004000000020ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_SINGLE 154
	[ POWER6_PME_PM_FPU0_SINGLE ] = {
		.pme_name = "PM_FPU0_SINGLE",
		.pme_short_desc = "FPU0 executed single precision instruction",
		.pme_long_desc = "This signal is active for one cycle when fp0 is executing single precision instruction.",
		.pme_event_ids = { 83, 92, 81, 89, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0100000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_STEERING 155
	[ POWER6_PME_PM_FPU_ISSUE_STEERING ] = {
		.pme_name = "PM_FPU_ISSUE_STEERING",
		.pme_short_desc = "FPU issue steering",
		.pme_long_desc = "FPU issue steering",
		.pme_event_ids = { 115, 123, 111, 120, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_1_CYC 156
	[ POWER6_PME_PM_THRD_PRIO_1_CYC ] = {
		.pme_name = "PM_THRD_PRIO_1_CYC",
		.pme_short_desc = "Cycles thread running at priority level 1",
		.pme_long_desc = "Cycles thread running at priority level 1",
		.pme_event_ids = { -1, 322, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000004000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_ST_FOLDED 157
	[ POWER6_PME_PM_FPU_ISSUE_ST_FOLDED ] = {
		.pme_name = "PM_FPU_ISSUE_ST_FOLDED",
		.pme_short_desc = "FPU issue a folded store",
		.pme_long_desc = "FPU issue a folded store",
		.pme_event_ids = { 116, 124, 112, 121, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0020000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_FIN 158
	[ POWER6_PME_PM_DFU_FIN ] = {
		.pme_name = "PM_DFU_FIN",
		.pme_short_desc = "DFU instruction finish",
		.pme_long_desc = "DFU instruction finish",
		.pme_event_ids = { 29, 36, 28, 36, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_PRED_CCACHE 159
	[ POWER6_PME_PM_BR_PRED_CCACHE ] = {
		.pme_name = "PM_BR_PRED_CCACHE",
		.pme_short_desc = "Branch count cache prediction",
		.pme_long_desc = "Branch count cache prediction",
		.pme_event_ids = { 9, 7, 7, 9, -1, -1 },
		.pme_group_vector = {
			0x0000000000000018ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_ST_CMPL_INT 160
	[ POWER6_PME_PM_MRK_ST_CMPL_INT ] = {
		.pme_name = "PM_MRK_ST_CMPL_INT",
		.pme_short_desc = "Marked store completed with intervention",
		.pme_long_desc = "A marked store previously sent to the memory subsystem completed (data home) after requiring intervention",
		.pme_event_ids = { -1, -1, 277, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_MMIO 161
	[ POWER6_PME_PM_FAB_MMIO ] = {
		.pme_name = "PM_FAB_MMIO",
		.pme_short_desc = "MMIO operation",
		.pme_long_desc = " locally mastered",
		.pme_event_ids = { 62, 72, 61, 68, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000020000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX_SIMPLE_ISSUED 162
	[ POWER6_PME_PM_MRK_VMX_SIMPLE_ISSUED ] = {
		.pme_name = "PM_MRK_VMX_SIMPLE_ISSUED",
		.pme_short_desc = "Marked VMX instruction issued to simple",
		.pme_long_desc = "Marked VMX instruction issued to simple",
		.pme_event_ids = { 288, 300, 283, 285, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000400000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_STF 163
	[ POWER6_PME_PM_FPU_STF ] = {
		.pme_name = "PM_FPU_STF",
		.pme_short_desc = "FPU executed store instruction",
		.pme_long_desc = "FPU is executing a store instruction. Combined Unit 0 + Unit 1",
		.pme_event_ids = { -1, -1, 113, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0800000000000002ULL,
			0x0000000000000002ULL }
	},
#define POWER6_PME_PM_MEM1_DP_CL_WR_GLOB 164
	[ POWER6_PME_PM_MEM1_DP_CL_WR_GLOB ] = {
		.pme_name = "PM_MEM1_DP_CL_WR_GLOB",
		.pme_short_desc = "cacheline write setting dp to global side 1",
		.pme_long_desc = "cacheline write setting dp to global side 1",
		.pme_event_ids = { 252, 263, 246, 251, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L3MISS 165
	[ POWER6_PME_PM_MRK_DATA_FROM_L3MISS ] = {
		.pme_name = "PM_MRK_DATA_FROM_L3MISS",
		.pme_short_desc = "Marked data loaded from L3 miss",
		.pme_long_desc = "Marked data loaded from L3 miss",
		.pme_event_ids = { -1, -1, 255, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GCT_NOSLOT_CYC 166
	[ POWER6_PME_PM_GCT_NOSLOT_CYC ] = {
		.pme_name = "PM_GCT_NOSLOT_CYC",
		.pme_short_desc = "Cycles no GCT slot allocated",
		.pme_long_desc = "Cycles this thread does not have any slots allocated in the GCT.",
		.pme_event_ids = { 121, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_ST_REQ_DATA 167
	[ POWER6_PME_PM_L2_ST_REQ_DATA ] = {
		.pme_name = "PM_L2_ST_REQ_DATA",
		.pme_short_desc = "L2 data store requests",
		.pme_long_desc = "L2 data store requests",
		.pme_event_ids = { -1, 200, 188, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_TABLEWALK_COUNT 168
	[ POWER6_PME_PM_INST_TABLEWALK_COUNT ] = {
		.pme_name = "PM_INST_TABLEWALK_COUNT",
		.pme_short_desc = "Periods doing instruction tablewalks",
		.pme_long_desc = "Periods doing instruction tablewalks",
		.pme_event_ids = { 341, 348, 335, 333, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L35_SHR 169
	[ POWER6_PME_PM_PTEG_FROM_L35_SHR ] = {
		.pme_name = "PM_PTEG_FROM_L35_SHR",
		.pme_short_desc = "PTEG loaded from L3.5 shared",
		.pme_long_desc = "PTEG loaded from L3.5 shared",
		.pme_event_ids = { -1, 306, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000020000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_ISYNC 170
	[ POWER6_PME_PM_DPU_HELD_ISYNC ] = {
		.pme_name = "PM_DPU_HELD_ISYNC",
		.pme_short_desc = "DISP unit held due to ISYNC ",
		.pme_long_desc = "DISP unit held due to ISYNC ",
		.pme_event_ids = { 41, 49, 40, 48, -1, -1 },
		.pme_group_vector = {
			0x0000184000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L25_SHR 171
	[ POWER6_PME_PM_MRK_DATA_FROM_L25_SHR ] = {
		.pme_name = "PM_MRK_DATA_FROM_L25_SHR",
		.pme_short_desc = "Marked data loaded from L2.5 shared",
		.pme_long_desc = "DL1 was reloaded with shared (T or SL) data from the L2 of a chip on this MCM due to a marked demand load",
		.pme_event_ids = { -1, -1, -1, 257, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000001000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L3SA_HIT 172
	[ POWER6_PME_PM_L3SA_HIT ] = {
		.pme_name = "PM_L3SA_HIT",
		.pme_short_desc = "L3 slice A hits",
		.pme_long_desc = "L3 slice A hits",
		.pme_event_ids = { 191, 201, 189, 194, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_MISS_16G 173
	[ POWER6_PME_PM_DERAT_MISS_16G ] = {
		.pme_name = "PM_DERAT_MISS_16G",
		.pme_short_desc = "DERAT misses for 16G page",
		.pme_long_desc = "A data request (load or store) missed the ERAT for 16G page and resulted in an ERAT reload.",
		.pme_event_ids = { -1, -1, -1, 343, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000040ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_PTEG_2ND_HALF 174
	[ POWER6_PME_PM_DATA_PTEG_2ND_HALF ] = {
		.pme_name = "PM_DATA_PTEG_2ND_HALF",
		.pme_short_desc = "Data table walk matched in second half pri­mary PTEG",
		.pme_long_desc = "Data table walk matched in second half pri­mary PTEG",
		.pme_event_ids = { 18, 26, 18, 25, -1, -1 },
		.pme_group_vector = {
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_ST_REQ 175
	[ POWER6_PME_PM_L2SA_ST_REQ ] = {
		.pme_name = "PM_L2SA_ST_REQ",
		.pme_short_desc = "L2 slice A store requests",
		.pme_long_desc = "A store request as seen at the L2 directory has been made from the core. Stores are counted after gathering in the L2 store queues. The event is provided on each of the three slices A,B,and C.",
		.pme_event_ids = { 170, 179, 170, 176, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0001080000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_LMEM 176
	[ POWER6_PME_PM_INST_FROM_LMEM ] = {
		.pme_name = "PM_INST_FROM_LMEM",
		.pme_short_desc = "Instruction fetched from local memory",
		.pme_long_desc = "Instruction fetched from local memory",
		.pme_event_ids = { -1, -1, -1, 152, -1, -1 },
		.pme_group_vector = {
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_DEMAND_L2_BR_REDIRECT 177
	[ POWER6_PME_PM_IC_DEMAND_L2_BR_REDIRECT ] = {
		.pme_name = "PM_IC_DEMAND_L2_BR_REDIRECT",
		.pme_short_desc = "L2 I cache demand request due to branch redirect",
		.pme_long_desc = "L2 I cache demand request due to branch redirect",
		.pme_event_ids = { 132, 140, 130, 138, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0002000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L2 178
	[ POWER6_PME_PM_PTEG_FROM_L2 ] = {
		.pme_name = "PM_PTEG_FROM_L2",
		.pme_short_desc = "PTEG loaded from L2",
		.pme_long_desc = "PTEG loaded from L2",
		.pme_event_ids = { 295, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000008000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_PTEG_1ST_HALF 179
	[ POWER6_PME_PM_DATA_PTEG_1ST_HALF ] = {
		.pme_name = "PM_DATA_PTEG_1ST_HALF",
		.pme_short_desc = "Data table walk matched in first half primary PTEG",
		.pme_long_desc = "Data table walk matched in first half primary PTEG",
		.pme_event_ids = { 17, 25, 17, 24, -1, -1 },
		.pme_group_vector = {
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_MPRED_COUNT 180
	[ POWER6_PME_PM_BR_MPRED_COUNT ] = {
		.pme_name = "PM_BR_MPRED_COUNT",
		.pme_short_desc = "Branch misprediction due to count prediction",
		.pme_long_desc = "Branch misprediction due to count prediction",
		.pme_event_ids = { 5, 3, 3, 5, -1, -1 },
		.pme_group_vector = {
			0x0000000000000024ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IERAT_MISS_4K 181
	[ POWER6_PME_PM_IERAT_MISS_4K ] = {
		.pme_name = "PM_IERAT_MISS_4K",
		.pme_short_desc = "IERAT misses for 4K page",
		.pme_long_desc = "IERAT misses for 4K page",
		.pme_event_ids = { -1, -1, -1, 344, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_BOTH_RUN_COUNT 182
	[ POWER6_PME_PM_THRD_BOTH_RUN_COUNT ] = {
		.pme_name = "PM_THRD_BOTH_RUN_COUNT",
		.pme_short_desc = "Periods both threads in run cycles",
		.pme_long_desc = "Periods both threads in run cycles",
		.pme_event_ids = { -1, -1, -1, 336, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0100000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_ULD 183
	[ POWER6_PME_PM_LSU_REJECT_ULD ] = {
		.pme_name = "PM_LSU_REJECT_ULD",
		.pme_short_desc = "Unaligned load reject",
		.pme_long_desc = "Unaligned load reject",
		.pme_event_ids = { 244, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x8000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_DL2L3_MOD_CYC 184
	[ POWER6_PME_PM_DATA_FROM_DL2L3_MOD_CYC ] = {
		.pme_name = "PM_DATA_FROM_DL2L3_MOD_CYC",
		.pme_short_desc = "Load latency from distant L2 or L3 modified",
		.pme_long_desc = "Load latency from distant L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 14, -1, -1 },
		.pme_group_vector = {
			0x0000000000002000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_RL2L3_MOD 185
	[ POWER6_PME_PM_MRK_PTEG_FROM_RL2L3_MOD ] = {
		.pme_name = "PM_MRK_PTEG_FROM_RL2L3_MOD",
		.pme_short_desc = "Marked PTEG loaded from remote L2 or L3 modified",
		.pme_long_desc = "Marked PTEG loaded from remote L2 or L3 modified",
		.pme_event_ids = { 280, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FLOP 186
	[ POWER6_PME_PM_FPU0_FLOP ] = {
		.pme_name = "PM_FPU0_FLOP",
		.pme_short_desc = "FPU0 executed 1FLOP",
		.pme_long_desc = " FMA",
		.pme_event_ids = { 76, 85, 74, 82, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0100000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FEST 187
	[ POWER6_PME_PM_FPU0_FEST ] = {
		.pme_name = "PM_FPU0_FEST",
		.pme_short_desc = "FPU0 executed FEST instruction",
		.pme_long_desc = "This signal is active for one cycle when fp0 is executing one of the estimate instructions. This could be fres* or frsqrte* where XYZ* means XYZ or XYZ. ",
		.pme_event_ids = { 74, 83, 72, 80, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0600000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU0_REJECT_LHS 188
	[ POWER6_PME_PM_MRK_LSU0_REJECT_LHS ] = {
		.pme_name = "PM_MRK_LSU0_REJECT_LHS",
		.pme_short_desc = "LSU0 marked load hit store reject",
		.pme_long_desc = "LSU0 marked load hit store reject",
		.pme_event_ids = { 270, 282, 264, 265, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_RESULT_SAT_1 189
	[ POWER6_PME_PM_VMX_RESULT_SAT_1 ] = {
		.pme_name = "PM_VMX_RESULT_SAT_1",
		.pme_short_desc = "VMX valid result with sat=1",
		.pme_long_desc = "VMX valid result with sat=1",
		.pme_event_ids = { 334, 341, 328, 326, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_NO_ITAG_CYC 190
	[ POWER6_PME_PM_NO_ITAG_CYC ] = {
		.pme_name = "PM_NO_ITAG_CYC",
		.pme_short_desc = "Cyles no ITAG available",
		.pme_long_desc = "Cyles no ITAG available",
		.pme_event_ids = { 290, 302, 285, 287, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_NO_SCRATCH 191
	[ POWER6_PME_PM_LSU1_REJECT_NO_SCRATCH ] = {
		.pme_name = "PM_LSU1_REJECT_NO_SCRATCH",
		.pme_short_desc = "LSU1 reject due to scratch register not available",
		.pme_long_desc = "LSU1 reject due to scratch register not available",
		.pme_event_ids = { 227, 236, 222, 227, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000014ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_0INST_FETCH 192
	[ POWER6_PME_PM_0INST_FETCH ] = {
		.pme_name = "PM_0INST_FETCH",
		.pme_short_desc = "No instructions fetched",
		.pme_long_desc = "No instructions were fetched this cycles (due to IFU hold, redirect, or icache miss)",
		.pme_event_ids = { 0, 0, 0, 0, -1, -1 },
		.pme_group_vector = {
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_WT_BR_MPRED 193
	[ POWER6_PME_PM_DPU_WT_BR_MPRED ] = {
		.pme_name = "PM_DPU_WT_BR_MPRED",
		.pme_short_desc = "Cycles DISP unit is stalled due to branch misprediction",
		.pme_long_desc = "Cycles DISP unit is stalled due to branch misprediction",
		.pme_event_ids = { -1, -1, -1, 62, -1, -1 },
		.pme_group_vector = {
			0x0000000800000000ULL,
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L1_PREF 194
	[ POWER6_PME_PM_L1_PREF ] = {
		.pme_name = "PM_L1_PREF",
		.pme_short_desc = "L1 cache data prefetches",
		.pme_long_desc = "A request to prefetch data into the L1 was made",
		.pme_event_ids = { 155, 164, 155, 161, -1, -1 },
		.pme_group_vector = {
			0x0001000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_FLOAT_MULTICYCLE 195
	[ POWER6_PME_PM_VMX_FLOAT_MULTICYCLE ] = {
		.pme_name = "PM_VMX_FLOAT_MULTICYCLE",
		.pme_short_desc = "VMX multi-cycle floating point instruction issued",
		.pme_long_desc = "VMX multi-cycle floating point instruction issued",
		.pme_event_ids = { 331, 338, 325, 323, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000001800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L25_SHR_CYC 196
	[ POWER6_PME_PM_DATA_FROM_L25_SHR_CYC ] = {
		.pme_name = "PM_DATA_FROM_L25_SHR_CYC",
		.pme_short_desc = "Load latency from L2.5 shared",
		.pme_long_desc = "Load latency from L2.5 shared",
		.pme_event_ids = { -1, 16, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000020000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L3 197
	[ POWER6_PME_PM_DATA_FROM_L3 ] = {
		.pme_name = "PM_DATA_FROM_L3",
		.pme_short_desc = "Data loaded from L3",
		.pme_long_desc = "DL1 was reloaded from the local L3 due to a demand load",
		.pme_event_ids = { -1, -1, 14, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000010100ULL,
			0x000c000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000001ULL }
	},
#define POWER6_PME_PM_PMC2_OVERFLOW 198
	[ POWER6_PME_PM_PMC2_OVERFLOW ] = {
		.pme_name = "PM_PMC2_OVERFLOW",
		.pme_short_desc = "PMC2 Overflow",
		.pme_long_desc = "PMC2 Overflow",
		.pme_event_ids = { -1, -1, 286, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX0_LD_WRBACK 199
	[ POWER6_PME_PM_VMX0_LD_WRBACK ] = {
		.pme_name = "PM_VMX0_LD_WRBACK",
		.pme_short_desc = "VMX0 load writeback valid",
		.pme_long_desc = "VMX0 load writeback valid",
		.pme_event_ids = { 323, 330, 317, 315, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000400000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_DENORM 200
	[ POWER6_PME_PM_FPU0_DENORM ] = {
		.pme_name = "PM_FPU0_DENORM",
		.pme_short_desc = "FPU0 received denormalized data",
		.pme_long_desc = "This signal is active for one cycle when one of the operands is denormalized.",
		.pme_event_ids = { 72, 81, 70, 78, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0100000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FETCH_CYC 201
	[ POWER6_PME_PM_INST_FETCH_CYC ] = {
		.pme_name = "PM_INST_FETCH_CYC",
		.pme_short_desc = "Cycles at least 1 instruction fetched",
		.pme_long_desc = "Asserted each cycle when the IFU sends at least one instruction to the IDU. ",
		.pme_event_ids = { 141, 151, 141, 147, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0000010000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_LDF 202
	[ POWER6_PME_PM_LSU_LDF ] = {
		.pme_name = "PM_LSU_LDF",
		.pme_short_desc = "LSU executed Floating Point load instruction",
		.pme_long_desc = "LSU executed Floating Point load instruction",
		.pme_event_ids = { -1, 246, 231, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0800000000000000ULL,
			0x0000000000000004ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_L2_CORR 203
	[ POWER6_PME_PM_LSU_REJECT_L2_CORR ] = {
		.pme_name = "PM_LSU_REJECT_L2_CORR",
		.pme_short_desc = "LSU reject due to L2 correctable error",
		.pme_long_desc = "LSU reject due to L2 correctable error",
		.pme_event_ids = { 239, -1, -1, 239, -1, -1 },
		.pme_group_vector = {
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_REF_64K 204
	[ POWER6_PME_PM_DERAT_REF_64K ] = {
		.pme_name = "PM_DERAT_REF_64K",
		.pme_short_desc = "DERAT reference for 64K page",
		.pme_long_desc = "DERAT reference for 64K page",
		.pme_event_ids = { -1, 360, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000080ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_3_CYC 205
	[ POWER6_PME_PM_THRD_PRIO_3_CYC ] = {
		.pme_name = "PM_THRD_PRIO_3_CYC",
		.pme_short_desc = "Cycles thread running at priority level 3",
		.pme_long_desc = "Cycles thread running at priority level 3",
		.pme_event_ids = { -1, -1, -1, 307, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000004000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FMA 206
	[ POWER6_PME_PM_FPU_FMA ] = {
		.pme_name = "PM_FPU_FMA",
		.pme_short_desc = "FPU executed multiply-add instruction",
		.pme_long_desc = "This signal is active for one cycle when FPU is executing multiply-add kind of instruction. This could be fmadd*, fnmadd*, fmsub*, fnmsub* where XYZ* means XYZ, XYZs, XYZ., XYZs. Combined Unit 0 + Unit 1",
		.pme_event_ids = { -1, 111, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0400000000000000ULL,
			0x0000000000000002ULL }
	},
#define POWER6_PME_PM_INST_FROM_L35_MOD 207
	[ POWER6_PME_PM_INST_FROM_L35_MOD ] = {
		.pme_name = "PM_INST_FROM_L35_MOD",
		.pme_short_desc = "Instruction fetched from L3.5 modified",
		.pme_long_desc = "Instruction fetched from L3.5 modified",
		.pme_event_ids = { 144, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_CONV 208
	[ POWER6_PME_PM_DFU_CONV ] = {
		.pme_name = "PM_DFU_CONV",
		.pme_short_desc = "DFU convert from fixed op",
		.pme_long_desc = "DFU convert from fixed op",
		.pme_event_ids = { 26, 33, 25, 33, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L25_MOD 209
	[ POWER6_PME_PM_INST_FROM_L25_MOD ] = {
		.pme_name = "PM_INST_FROM_L25_MOD",
		.pme_short_desc = "Instruction fetched from L2.5 modified",
		.pme_long_desc = "Instruction fetched from L2.5 modified",
		.pme_event_ids = { -1, -1, 144, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000400000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L35_MOD 210
	[ POWER6_PME_PM_PTEG_FROM_L35_MOD ] = {
		.pme_name = "PM_PTEG_FROM_L35_MOD",
		.pme_short_desc = "PTEG loaded from L3.5 modified",
		.pme_long_desc = "PTEG loaded from L3.5 modified",
		.pme_event_ids = { 297, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000020000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX_ST_ISSUED 211
	[ POWER6_PME_PM_MRK_VMX_ST_ISSUED ] = {
		.pme_name = "PM_MRK_VMX_ST_ISSUED",
		.pme_short_desc = "Marked VMX store issued",
		.pme_long_desc = "Marked VMX store issued",
		.pme_event_ids = { 289, 301, 284, 286, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000800000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_FLOAT_ISSUED 212
	[ POWER6_PME_PM_VMX_FLOAT_ISSUED ] = {
		.pme_name = "PM_VMX_FLOAT_ISSUED",
		.pme_short_desc = "VMX instruction issued to float",
		.pme_long_desc = "VMX instruction issued to float",
		.pme_event_ids = { 330, 337, 324, 322, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000100000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_L2_CORR 213
	[ POWER6_PME_PM_LSU0_REJECT_L2_CORR ] = {
		.pme_name = "PM_LSU0_REJECT_L2_CORR",
		.pme_short_desc = "LSU0 reject due to L2 correctable error",
		.pme_long_desc = "LSU0 reject due to L2 correctable error",
		.pme_event_ids = { 212, 221, 207, 212, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000008ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_L2MISS 214
	[ POWER6_PME_PM_THRD_L2MISS ] = {
		.pme_name = "PM_THRD_L2MISS",
		.pme_short_desc = "Thread in L2 miss",
		.pme_long_desc = "Thread in L2 miss",
		.pme_event_ids = { 314, 321, 307, 305, -1, -1 },
		.pme_group_vector = {
			0x0100000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FCONV 215
	[ POWER6_PME_PM_FPU_FCONV ] = {
		.pme_name = "PM_FPU_FCONV",
		.pme_short_desc = "FPU executed FCONV instruction",
		.pme_long_desc = "FPU executed FCONV instruction",
		.pme_event_ids = { 102, -1, -1, 107, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000004ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FXMULT 216
	[ POWER6_PME_PM_FPU_FXMULT ] = {
		.pme_name = "PM_FPU_FXMULT",
		.pme_short_desc = "FPU executed fixed point multiplication",
		.pme_long_desc = "FPU executed fixed point multiplication",
		.pme_event_ids = { 106, -1, -1, 111, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000001ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FRSP 217
	[ POWER6_PME_PM_FPU1_FRSP ] = {
		.pme_name = "PM_FPU1_FRSP",
		.pme_short_desc = "FPU1 executed FRSP instruction",
		.pme_long_desc = "FPU1 executed FRSP instruction",
		.pme_event_ids = { 94, 103, 92, 100, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x4000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_REF_16M 218
	[ POWER6_PME_PM_MRK_DERAT_REF_16M ] = {
		.pme_name = "PM_MRK_DERAT_REF_16M",
		.pme_short_desc = "Marked DERAT reference for 16M page",
		.pme_long_desc = "Marked DERAT reference for 16M page",
		.pme_event_ids = { -1, -1, 345, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_CASTOUT_SHR 219
	[ POWER6_PME_PM_L2SB_CASTOUT_SHR ] = {
		.pme_name = "PM_L2SB_CASTOUT_SHR",
		.pme_short_desc = "L2 slice B castouts - Shared",
		.pme_long_desc = "L2 slice B castouts - Shared",
		.pme_event_ids = { 172, 181, 172, 178, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_ONE_RUN_COUNT 220
	[ POWER6_PME_PM_THRD_ONE_RUN_COUNT ] = {
		.pme_name = "PM_THRD_ONE_RUN_COUNT",
		.pme_short_desc = "Periods one of the threads in run cycles",
		.pme_long_desc = "Periods one of the threads in run cycles",
		.pme_event_ids = { 344, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000800000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_RMEM 221
	[ POWER6_PME_PM_INST_FROM_RMEM ] = {
		.pme_name = "PM_INST_FROM_RMEM",
		.pme_short_desc = "Instruction fetched from remote memory",
		.pme_long_desc = "Instruction fetched from remote memory",
		.pme_event_ids = { -1, -1, 147, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_BOTH_BUS 222
	[ POWER6_PME_PM_LSU_BOTH_BUS ] = {
		.pme_name = "PM_LSU_BOTH_BUS",
		.pme_short_desc = "Both data return buses busy simultaneously",
		.pme_long_desc = "Both data return buses busy simultaneously",
		.pme_event_ids = { 233, 242, 228, 233, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FSQRT_FDIV 223
	[ POWER6_PME_PM_FPU1_FSQRT_FDIV ] = {
		.pme_name = "PM_FPU1_FSQRT_FDIV",
		.pme_short_desc = "FPU1 executed FSQRT or FDIV instruction",
		.pme_long_desc = "FPU1 executed FSQRT or FDIV instruction",
		.pme_event_ids = { 95, 104, 93, 101, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_LD_REQ_INST 224
	[ POWER6_PME_PM_L2_LD_REQ_INST ] = {
		.pme_name = "PM_L2_LD_REQ_INST",
		.pme_short_desc = "L2 instruction load requests",
		.pme_long_desc = "L2 instruction load requests",
		.pme_event_ids = { 187, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000004000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L35_SHR 225
	[ POWER6_PME_PM_MRK_PTEG_FROM_L35_SHR ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L35_SHR",
		.pme_short_desc = "Marked PTEG loaded from L3.5 shared",
		.pme_long_desc = "Marked PTEG loaded from L3.5 shared",
		.pme_event_ids = { -1, 291, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_PRED_CR 226
	[ POWER6_PME_PM_BR_PRED_CR ] = {
		.pme_name = "PM_BR_PRED_CR",
		.pme_short_desc = "A conditional branch was predicted",
		.pme_long_desc = " CR prediction",
		.pme_event_ids = { 10, 8, 8, 10, -1, -1 },
		.pme_group_vector = {
			0x0000000000000014ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU0_REJECT_ULD 227
	[ POWER6_PME_PM_MRK_LSU0_REJECT_ULD ] = {
		.pme_name = "PM_MRK_LSU0_REJECT_ULD",
		.pme_short_desc = "LSU0 marked unaligned load reject",
		.pme_long_desc = "LSU0 marked unaligned load reject",
		.pme_event_ids = { 271, 283, 265, 266, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT 228
	[ POWER6_PME_PM_LSU_REJECT ] = {
		.pme_name = "PM_LSU_REJECT",
		.pme_short_desc = "LSU reject",
		.pme_long_desc = "LSU reject",
		.pme_event_ids = { -1, -1, -1, 238, -1, -1 },
		.pme_group_vector = {
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_LHS_BOTH 229
	[ POWER6_PME_PM_LSU_REJECT_LHS_BOTH ] = {
		.pme_name = "PM_LSU_REJECT_LHS_BOTH",
		.pme_short_desc = "Load hit store reject both units",
		.pme_long_desc = "Load hit store reject both units",
		.pme_event_ids = { -1, 250, -1, 241, -1, -1 },
		.pme_group_vector = {
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GXO_ADDR_CYC_BUSY 230
	[ POWER6_PME_PM_GXO_ADDR_CYC_BUSY ] = {
		.pme_name = "PM_GXO_ADDR_CYC_BUSY",
		.pme_short_desc = "Outbound GX address utilization (# of cycles address out is valid)",
		.pme_long_desc = "Outbound GX address utilization (# of cycles address out is valid)",
		.pme_event_ids = { 125, 132, 123, 131, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000200000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_SRQ_EMPTY_COUNT 231
	[ POWER6_PME_PM_LSU_SRQ_EMPTY_COUNT ] = {
		.pme_name = "PM_LSU_SRQ_EMPTY_COUNT",
		.pme_short_desc = "Periods SRQ empty",
		.pme_long_desc = "The Store Request Queue is empty",
		.pme_event_ids = { -1, -1, -1, 341, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0008000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L3 232
	[ POWER6_PME_PM_PTEG_FROM_L3 ] = {
		.pme_name = "PM_PTEG_FROM_L3",
		.pme_short_desc = "PTEG loaded from L3",
		.pme_long_desc = "PTEG loaded from L3",
		.pme_event_ids = { -1, -1, 292, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX0_LD_ISSUED 233
	[ POWER6_PME_PM_VMX0_LD_ISSUED ] = {
		.pme_name = "PM_VMX0_LD_ISSUED",
		.pme_short_desc = "VMX0 load issued",
		.pme_long_desc = "VMX0 load issued",
		.pme_event_ids = { 322, 329, 316, 314, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000600000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FXU_PIPELINED_MULT_DIV 234
	[ POWER6_PME_PM_FXU_PIPELINED_MULT_DIV ] = {
		.pme_name = "PM_FXU_PIPELINED_MULT_DIV",
		.pme_short_desc = "Fix point multiply/divide pipelined",
		.pme_long_desc = "Fix point multiply/divide pipelined",
		.pme_event_ids = { 118, 126, 118, 126, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_STF 235
	[ POWER6_PME_PM_FPU1_STF ] = {
		.pme_name = "PM_FPU1_STF",
		.pme_short_desc = "FPU1 executed store instruction",
		.pme_long_desc = "This signal is active for one cycle when fp1 is executing a store instruction.",
		.pme_event_ids = { 99, 108, 97, 105, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_ADD 236
	[ POWER6_PME_PM_DFU_ADD ] = {
		.pme_name = "PM_DFU_ADD",
		.pme_short_desc = "DFU add type instruction",
		.pme_long_desc = "DFU add type instruction",
		.pme_event_ids = { 23, 30, 22, 30, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM_DP_CL_WR_GLOB 237
	[ POWER6_PME_PM_MEM_DP_CL_WR_GLOB ] = {
		.pme_name = "PM_MEM_DP_CL_WR_GLOB",
		.pme_short_desc = "cache line write setting double pump state to global",
		.pme_long_desc = "cache line write setting double pump state to global",
		.pme_event_ids = { -1, 267, 250, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU1_REJECT_ULD 238
	[ POWER6_PME_PM_MRK_LSU1_REJECT_ULD ] = {
		.pme_name = "PM_MRK_LSU1_REJECT_ULD",
		.pme_short_desc = "LSU1 marked unaligned load reject",
		.pme_long_desc = "LSU1 marked unaligned load reject",
		.pme_event_ids = { 274, 286, 268, 269, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ITLB_REF 239
	[ POWER6_PME_PM_ITLB_REF ] = {
		.pme_name = "PM_ITLB_REF",
		.pme_short_desc = "Instruction TLB reference",
		.pme_long_desc = "Instruction TLB reference",
		.pme_event_ids = { 153, 162, 153, 159, -1, -1 },
		.pme_group_vector = {
			0x0200000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_L2MISS 240
	[ POWER6_PME_PM_LSU0_REJECT_L2MISS ] = {
		.pme_name = "PM_LSU0_REJECT_L2MISS",
		.pme_short_desc = "LSU0 L2 miss reject",
		.pme_long_desc = "LSU0 L2 miss reject",
		.pme_event_ids = { 211, 220, 206, 211, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0000008000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L35_SHR 241
	[ POWER6_PME_PM_DATA_FROM_L35_SHR ] = {
		.pme_name = "PM_DATA_FROM_L35_SHR",
		.pme_short_desc = "Data loaded from L3.5 shared",
		.pme_long_desc = "Data loaded from L3.5 shared",
		.pme_event_ids = { -1, 19, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000300ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000001ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_RL2L3_MOD 242
	[ POWER6_PME_PM_MRK_DATA_FROM_RL2L3_MOD ] = {
		.pme_name = "PM_MRK_DATA_FROM_RL2L3_MOD",
		.pme_short_desc = "Marked data loaded from remote L2 or L3 modified",
		.pme_long_desc = "Marked data loaded from remote L2 or L3 modified",
		.pme_event_ids = { 263, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000008000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FPSCR 243
	[ POWER6_PME_PM_FPU0_FPSCR ] = {
		.pme_name = "PM_FPU0_FPSCR",
		.pme_short_desc = "FPU0 executed FPSCR instruction",
		.pme_long_desc = "This signal is active for one cycle when fp0 is executing fpscr move related instruction. This could be mtfsfi*, mtfsb0*, mtfsb1*. mffs*, mtfsf*, mcrsf* where XYZ* means XYZ, XYZs, XYZ., XYZs",
		.pme_event_ids = { 78, 87, 76, 84, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0200000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L2 244
	[ POWER6_PME_PM_DATA_FROM_L2 ] = {
		.pme_name = "PM_DATA_FROM_L2",
		.pme_short_desc = "Data loaded from L2",
		.pme_long_desc = "DL1 was reloaded from the local L2 due to a demand load",
		.pme_event_ids = { 13, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000040080ULL,
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_XER 245
	[ POWER6_PME_PM_DPU_HELD_XER ] = {
		.pme_name = "PM_DPU_HELD_XER",
		.pme_short_desc = "DISP unit held due to XER dependency",
		.pme_long_desc = "DISP unit held due to XER dependency",
		.pme_event_ids = { 54, 62, 52, 60, -1, -1 },
		.pme_group_vector = {
			0x0000004000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_NODE_PUMP 246
	[ POWER6_PME_PM_FAB_NODE_PUMP ] = {
		.pme_name = "PM_FAB_NODE_PUMP",
		.pme_short_desc = "Node pump operation",
		.pme_long_desc = " locally mastered",
		.pme_event_ids = { 63, 73, 62, 69, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_RESULT_SAT_0_1 247
	[ POWER6_PME_PM_VMX_RESULT_SAT_0_1 ] = {
		.pme_name = "PM_VMX_RESULT_SAT_0_1",
		.pme_short_desc = "VMX valid result with sat bit is set (0->1)",
		.pme_long_desc = "VMX valid result with sat bit is set (0->1)",
		.pme_event_ids = { 333, 340, 327, 325, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LD_REF_L1 248
	[ POWER6_PME_PM_LD_REF_L1 ] = {
		.pme_name = "PM_LD_REF_L1",
		.pme_short_desc = "L1 D cache load references",
		.pme_long_desc = "Total DL1 Load references",
		.pme_event_ids = { 201, 212, 198, 203, -1, -1 },
		.pme_group_vector = {
			0x0000c00000000000ULL,
			0x0000000000000000ULL,
			0x2080000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_TLB_REF 249
	[ POWER6_PME_PM_TLB_REF ] = {
		.pme_name = "PM_TLB_REF",
		.pme_short_desc = "TLB reference",
		.pme_long_desc = "TLB reference",
		.pme_event_ids = { 320, 327, 314, 312, -1, -1 },
		.pme_group_vector = {
			0x0200000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DC_PREF_OUT_OF_STREAMS 250
	[ POWER6_PME_PM_DC_PREF_OUT_OF_STREAMS ] = {
		.pme_name = "PM_DC_PREF_OUT_OF_STREAMS",
		.pme_short_desc = "D cache out of streams",
		.pme_long_desc = "out of streams",
		.pme_event_ids = { 21, 28, 20, 28, -1, -1 },
		.pme_group_vector = {
			0x0001000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FLUSH_FPU 251
	[ POWER6_PME_PM_FLUSH_FPU ] = {
		.pme_name = "PM_FLUSH_FPU",
		.pme_short_desc = "Flush caused by FPU exception",
		.pme_long_desc = "Flush caused by FPU exception",
		.pme_event_ids = { 69, 78, 67, 75, -1, -1 },
		.pme_group_vector = {
			0x0002000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM1_DP_CL_WR_LOC 252
	[ POWER6_PME_PM_MEM1_DP_CL_WR_LOC ] = {
		.pme_name = "PM_MEM1_DP_CL_WR_LOC",
		.pme_short_desc = "cacheline write setting dp to local side 1",
		.pme_long_desc = "cacheline write setting dp to local side 1",
		.pme_event_ids = { 253, 264, 247, 252, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_LD_HIT 253
	[ POWER6_PME_PM_L2SB_LD_HIT ] = {
		.pme_name = "PM_L2SB_LD_HIT",
		.pme_short_desc = "L2 slice B load hits",
		.pme_long_desc = "L2 slice B load hits",
		.pme_event_ids = { 175, 184, 175, 181, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000800000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_DCLAIM 254
	[ POWER6_PME_PM_FAB_DCLAIM ] = {
		.pme_name = "PM_FAB_DCLAIM",
		.pme_short_desc = "Dclaim operation",
		.pme_long_desc = " locally mastered",
		.pme_event_ids = { 60, 70, 59, 66, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000008000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM_DP_CL_WR_LOC 255
	[ POWER6_PME_PM_MEM_DP_CL_WR_LOC ] = {
		.pme_name = "PM_MEM_DP_CL_WR_LOC",
		.pme_short_desc = "cache line write setting double pump state to local",
		.pme_long_desc = "cache line write setting double pump state to local",
		.pme_event_ids = { 256, -1, -1, 255, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_MPRED_CR 256
	[ POWER6_PME_PM_BR_MPRED_CR ] = {
		.pme_name = "PM_BR_MPRED_CR",
		.pme_short_desc = "Branch mispredictions due to CR bit setting",
		.pme_long_desc = "This signal is asserted when the branch execution unit detects a branch mispredict because the CR value is opposite of the predicted value. This signal is asserted after a branch issue event and will result in a branch redirect flush if not overridden by a flush of an older instruction.",
		.pme_event_ids = { 6, 4, 4, 6, -1, -1 },
		.pme_group_vector = {
			0x0000000000000024ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_EXTERN 257
	[ POWER6_PME_PM_LSU_REJECT_EXTERN ] = {
		.pme_name = "PM_LSU_REJECT_EXTERN",
		.pme_short_desc = "LSU external reject request ",
		.pme_long_desc = "LSU external reject request ",
		.pme_event_ids = { -1, -1, 235, -1, -1, -1 },
		.pme_group_vector = {
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_RL2L3_MOD 258
	[ POWER6_PME_PM_DATA_FROM_RL2L3_MOD ] = {
		.pme_name = "PM_DATA_FROM_RL2L3_MOD",
		.pme_short_desc = "Data loaded from remote L2 or L3 modified",
		.pme_long_desc = "Data loaded from remote L2 or L3 modified",
		.pme_event_ids = { 16, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000010400ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_RU_WQ 259
	[ POWER6_PME_PM_DPU_HELD_RU_WQ ] = {
		.pme_name = "PM_DPU_HELD_RU_WQ",
		.pme_short_desc = "DISP unit held due to RU FXU write queue full",
		.pme_long_desc = "DISP unit held due to RU FXU write queue full",
		.pme_event_ids = { 48, 57, 47, 55, -1, -1 },
		.pme_group_vector = {
			0x0000084000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LD_MISS_L1 260
	[ POWER6_PME_PM_LD_MISS_L1 ] = {
		.pme_name = "PM_LD_MISS_L1",
		.pme_short_desc = "L1 D cache load misses",
		.pme_long_desc = "Total DL1 Load references that miss the DL1",
		.pme_event_ids = { 199, 210, 197, 202, -1, -1 },
		.pme_group_vector = {
			0x0000800000000000ULL,
			0x0000000000000000ULL,
			0x1080084000000020ULL,
			0x0000000000000006ULL }
	},
#define POWER6_PME_PM_DC_INV_L2 261
	[ POWER6_PME_PM_DC_INV_L2 ] = {
		.pme_name = "PM_DC_INV_L2",
		.pme_short_desc = "L1 D cache entries invalidated from L2",
		.pme_long_desc = "A dcache invalidated was received from the L2 because a line in L2 was castout.",
		.pme_event_ids = { 20, -1, -1, 27, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_RMEM 262
	[ POWER6_PME_PM_MRK_PTEG_FROM_RMEM ] = {
		.pme_name = "PM_MRK_PTEG_FROM_RMEM",
		.pme_short_desc = "Marked PTEG loaded from remote memory",
		.pme_long_desc = "Marked PTEG loaded from remote memory",
		.pme_event_ids = { -1, -1, 275, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000080000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FIN 263
	[ POWER6_PME_PM_FPU_FIN ] = {
		.pme_name = "PM_FPU_FIN",
		.pme_short_desc = "FPU produced a result",
		.pme_long_desc = "FPU finished, produced a result This only indicates finish, not completion. Combined Unit 0 + Unit 1",
		.pme_event_ids = { 103, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x4000000000000001ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FXU0_FIN 264
	[ POWER6_PME_PM_FXU0_FIN ] = {
		.pme_name = "PM_FXU0_FIN",
		.pme_short_desc = "FXU0 produced a result",
		.pme_long_desc = "The Fixed Point unit 0 finished an instruction and produced a result",
		.pme_event_ids = { -1, -1, 117, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x4000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_FPQ 265
	[ POWER6_PME_PM_DPU_HELD_FPQ ] = {
		.pme_name = "PM_DPU_HELD_FPQ",
		.pme_short_desc = "DISP unit held due to FPU issue queue full",
		.pme_long_desc = "DISP unit held due to FPU issue queue full",
		.pme_event_ids = { 34, 42, 33, 41, -1, -1 },
		.pme_group_vector = {
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GX_DMA_READ 266
	[ POWER6_PME_PM_GX_DMA_READ ] = {
		.pme_name = "PM_GX_DMA_READ",
		.pme_short_desc = "DMA Read Request",
		.pme_long_desc = "DMA Read Request",
		.pme_event_ids = { 128, 135, 126, 134, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000800000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_PARTIAL_SECTOR 267
	[ POWER6_PME_PM_LSU1_REJECT_PARTIAL_SECTOR ] = {
		.pme_name = "PM_LSU1_REJECT_PARTIAL_SECTOR",
		.pme_short_desc = "LSU1 reject due to partial sector valid",
		.pme_long_desc = "LSU1 reject due to partial sector valid",
		.pme_event_ids = { 228, 237, 223, 228, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000010ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_0INST_FETCH_COUNT 268
	[ POWER6_PME_PM_0INST_FETCH_COUNT ] = {
		.pme_name = "PM_0INST_FETCH_COUNT",
		.pme_short_desc = "Periods with no instructions fetched",
		.pme_long_desc = "No instructions were fetched this periods (due to IFU hold, redirect, or icache miss)",
		.pme_event_ids = { 337, 344, 331, 329, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC5_OVERFLOW 269
	[ POWER6_PME_PM_PMC5_OVERFLOW ] = {
		.pme_name = "PM_PMC5_OVERFLOW",
		.pme_short_desc = "PMC5 Overflow",
		.pme_long_desc = "PMC5 Overflow",
		.pme_event_ids = { 294, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_LD_REQ 270
	[ POWER6_PME_PM_L2SB_LD_REQ ] = {
		.pme_name = "PM_L2SB_LD_REQ",
		.pme_short_desc = "L2 slice B load requests ",
		.pme_long_desc = "L2 slice B load requests ",
		.pme_event_ids = { 178, 187, 178, 184, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000800000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_0_CYC 271
	[ POWER6_PME_PM_THRD_PRIO_DIFF_0_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_0_CYC",
		.pme_short_desc = "Cycles no thread priority difference",
		.pme_long_desc = "Cycles no thread priority difference",
		.pme_event_ids = { 318, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000010000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_RMEM 272
	[ POWER6_PME_PM_DATA_FROM_RMEM ] = {
		.pme_name = "PM_DATA_FROM_RMEM",
		.pme_short_desc = "Data loaded from remote memory",
		.pme_long_desc = "Data loaded from remote memory",
		.pme_event_ids = { -1, -1, 16, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000004800ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_BOTH_CYC 273
	[ POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_BOTH_CYC ] = {
		.pme_name = "PM_LSU_LMQ_SRQ_EMPTY_BOTH_CYC",
		.pme_short_desc = "Cycles both threads LMQ and SRQ empty",
		.pme_long_desc = "Cycles both threads LMQ and SRQ empty",
		.pme_event_ids = { -1, -1, 234, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ST_REF_L1_BOTH 274
	[ POWER6_PME_PM_ST_REF_L1_BOTH ] = {
		.pme_name = "PM_ST_REF_L1_BOTH",
		.pme_short_desc = "Both units L1 D cache store reference",
		.pme_long_desc = "Both units L1 D cache store reference",
		.pme_event_ids = { -1, 316, -1, 301, -1, -1 },
		.pme_group_vector = {
			0x0000400000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_PERMUTE_ISSUED 275
	[ POWER6_PME_PM_VMX_PERMUTE_ISSUED ] = {
		.pme_name = "PM_VMX_PERMUTE_ISSUED",
		.pme_short_desc = "VMX instruction issued to permute",
		.pme_long_desc = "VMX instruction issued to permute",
		.pme_event_ids = { 332, 339, 326, 324, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000100000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_TAKEN 276
	[ POWER6_PME_PM_BR_TAKEN ] = {
		.pme_name = "PM_BR_TAKEN",
		.pme_short_desc = "Branches taken",
		.pme_long_desc = "Branches taken",
		.pme_event_ids = { -1, 10, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000040ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_DMA 277
	[ POWER6_PME_PM_FAB_DMA ] = {
		.pme_name = "PM_FAB_DMA",
		.pme_short_desc = "DMA operation",
		.pme_long_desc = " locally mastered",
		.pme_event_ids = { 61, 71, 60, 67, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000008000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GCT_EMPTY_COUNT 278
	[ POWER6_PME_PM_GCT_EMPTY_COUNT ] = {
		.pme_name = "PM_GCT_EMPTY_COUNT",
		.pme_short_desc = "Periods GCT empty",
		.pme_long_desc = "The Global Completion Table is completely empty.",
		.pme_event_ids = { -1, 358, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0008010000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_SINGLE 279
	[ POWER6_PME_PM_FPU1_SINGLE ] = {
		.pme_name = "PM_FPU1_SINGLE",
		.pme_short_desc = "FPU1 executed single precision instruction",
		.pme_long_desc = "This signal is active for one cycle when fp1 is executing single precision instruction.",
		.pme_event_ids = { 98, 107, 96, 104, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_CASTOUT_SHR 280
	[ POWER6_PME_PM_L2SA_CASTOUT_SHR ] = {
		.pme_name = "PM_L2SA_CASTOUT_SHR",
		.pme_short_desc = "L2 slice A castouts - Shared",
		.pme_long_desc = "L2 slice A castouts - Shared",
		.pme_event_ids = { 158, 167, 158, 164, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L3SB_REF 281
	[ POWER6_PME_PM_L3SB_REF ] = {
		.pme_name = "PM_L3SB_REF",
		.pme_short_desc = "L3 slice B references",
		.pme_long_desc = "L3 slice B references",
		.pme_event_ids = { 196, 206, 194, 199, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0008000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FRSP 282
	[ POWER6_PME_PM_FPU0_FRSP ] = {
		.pme_name = "PM_FPU0_FRSP",
		.pme_short_desc = "FPU0 executed FRSP instruction",
		.pme_long_desc = "FPU0 executed FRSP instruction",
		.pme_event_ids = { 79, 88, 77, 85, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0400000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC4_SAVED 283
	[ POWER6_PME_PM_PMC4_SAVED ] = {
		.pme_name = "PM_PMC4_SAVED",
		.pme_short_desc = "PMC4 rewind value saved",
		.pme_long_desc = "PMC4 rewind value saved",
		.pme_event_ids = { -1, -1, 288, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_DC_INV 284
	[ POWER6_PME_PM_L2SA_DC_INV ] = {
		.pme_name = "PM_L2SA_DC_INV",
		.pme_short_desc = "L2 slice A D cache invalidate",
		.pme_long_desc = "L2 slice A D cache invalidate",
		.pme_event_ids = { 159, 168, 159, 165, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GXI_ADDR_CYC_BUSY 285
	[ POWER6_PME_PM_GXI_ADDR_CYC_BUSY ] = {
		.pme_name = "PM_GXI_ADDR_CYC_BUSY",
		.pme_short_desc = "Inbound GX address utilization (# of cycle address is in valid)",
		.pme_long_desc = "Inbound GX address utilization (# of cycle address is in valid)",
		.pme_event_ids = { 122, 129, 120, 128, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000400000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FMA 286
	[ POWER6_PME_PM_FPU0_FMA ] = {
		.pme_name = "PM_FPU0_FMA",
		.pme_short_desc = "FPU0 executed multiply-add instruction",
		.pme_long_desc = "This signal is active for one cycle when fp0 is executing multiply-add kind of instruction. This could be fmadd*, fnmadd*, fmsub*, fnmsub* where XYZ* means XYZ, XYZs, XYZ., XYZs.",
		.pme_event_ids = { 77, 86, 75, 83, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_SLB_MISS 287
	[ POWER6_PME_PM_SLB_MISS ] = {
		.pme_name = "PM_SLB_MISS",
		.pme_short_desc = "SLB misses",
		.pme_long_desc = "SLB misses",
		.pme_event_ids = { 303, -1, -1, 294, -1, -1 },
		.pme_group_vector = {
			0x0400000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_ST_GPS 288
	[ POWER6_PME_PM_MRK_ST_GPS ] = {
		.pme_name = "PM_MRK_ST_GPS",
		.pme_short_desc = "Marked store sent to GPS",
		.pme_long_desc = "A sampled store has been sent to the memory subsystem",
		.pme_event_ids = { -1, 294, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_REF_4K 289
	[ POWER6_PME_PM_DERAT_REF_4K ] = {
		.pme_name = "PM_DERAT_REF_4K",
		.pme_short_desc = "DERAT reference for 4K page",
		.pme_long_desc = "DERAT reference for 4K page",
		.pme_event_ids = { 350, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000080ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_CASTOUT_SHR 290
	[ POWER6_PME_PM_L2_CASTOUT_SHR ] = {
		.pme_name = "PM_L2_CASTOUT_SHR",
		.pme_short_desc = "L2 castouts - Shared (T",
		.pme_long_desc = " Te",
		.pme_event_ids = { -1, 194, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_STCX_CR 291
	[ POWER6_PME_PM_DPU_HELD_STCX_CR ] = {
		.pme_name = "PM_DPU_HELD_STCX_CR",
		.pme_short_desc = "DISP unit held due to STCX updating CR ",
		.pme_long_desc = "DISP unit held due to STCX updating CR ",
		.pme_event_ids = { 51, 60, 50, 58, -1, -1 },
		.pme_group_vector = {
			0x0000084000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_ST_FOLDED 292
	[ POWER6_PME_PM_FPU0_ST_FOLDED ] = {
		.pme_name = "PM_FPU0_ST_FOLDED",
		.pme_short_desc = "FPU0 folded store",
		.pme_long_desc = "FPU0 folded store",
		.pme_event_ids = { 85, 94, 83, 91, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0400000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L21 293
	[ POWER6_PME_PM_MRK_DATA_FROM_L21 ] = {
		.pme_name = "PM_MRK_DATA_FROM_L21",
		.pme_short_desc = "Marked data loaded from private L2 other core",
		.pme_long_desc = "Marked data loaded from private L2 other core",
		.pme_event_ids = { -1, 270, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_minus3or4_CYC 294
	[ POWER6_PME_PM_THRD_PRIO_DIFF_minus3or4_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_minus3or4_CYC",
		.pme_short_desc = "Cycles thread priority difference is -3 or -4",
		.pme_long_desc = "Cycles thread priority difference is -3 or -4",
		.pme_event_ids = { -1, -1, 311, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L35_MOD 295
	[ POWER6_PME_PM_DATA_FROM_L35_MOD ] = {
		.pme_name = "PM_DATA_FROM_L35_MOD",
		.pme_short_desc = "Data loaded from L3.5 modified",
		.pme_long_desc = "Data loaded from L3.5 modified",
		.pme_event_ids = { 14, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000208300ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000001ULL }
	},
#define POWER6_PME_PM_DATA_FROM_DL2L3_SHR 296
	[ POWER6_PME_PM_DATA_FROM_DL2L3_SHR ] = {
		.pme_name = "PM_DATA_FROM_DL2L3_SHR",
		.pme_short_desc = "Data loaded from distant L2 or L3 shared",
		.pme_long_desc = "Data loaded from distant L2 or L3 shared",
		.pme_event_ids = { -1, -1, 11, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000008400ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GXI_DATA_CYC_BUSY 297
	[ POWER6_PME_PM_GXI_DATA_CYC_BUSY ] = {
		.pme_name = "PM_GXI_DATA_CYC_BUSY",
		.pme_short_desc = "Inbound GX Data utilization (# of cycle data in is valid)",
		.pme_long_desc = "Inbound GX Data utilization (# of cycle data in is valid)",
		.pme_event_ids = { 124, 131, 122, 130, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000400000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_STEAL 298
	[ POWER6_PME_PM_LSU_REJECT_STEAL ] = {
		.pme_name = "PM_LSU_REJECT_STEAL",
		.pme_short_desc = "LSU reject due to steal",
		.pme_long_desc = "LSU reject due to steal",
		.pme_event_ids = { 242, 254, 239, 243, -1, -1 },
		.pme_group_vector = {
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ST_FIN 299
	[ POWER6_PME_PM_ST_FIN ] = {
		.pme_name = "PM_ST_FIN",
		.pme_short_desc = "Store instructions finished",
		.pme_long_desc = "Store instructions finished",
		.pme_event_ids = { 307, 313, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0100000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_CR_LOGICAL 300
	[ POWER6_PME_PM_DPU_HELD_CR_LOGICAL ] = {
		.pme_name = "PM_DPU_HELD_CR_LOGICAL",
		.pme_short_desc = "DISP unit held due to CR",
		.pme_long_desc = " LR or CTR updated by CR logical",
		.pme_event_ids = { 32, 40, 31, 39, -1, -1 },
		.pme_group_vector = {
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0300000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_SEL_T0 301
	[ POWER6_PME_PM_THRD_SEL_T0 ] = {
		.pme_name = "PM_THRD_SEL_T0",
		.pme_short_desc = "Decode selected thread 0",
		.pme_long_desc = "Decode selected thread 0",
		.pme_event_ids = { 319, 326, 312, 311, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_RELOAD_VALID 302
	[ POWER6_PME_PM_PTEG_RELOAD_VALID ] = {
		.pme_name = "PM_PTEG_RELOAD_VALID",
		.pme_short_desc = "TLB reload valid",
		.pme_long_desc = "TLB reload valid",
		.pme_event_ids = { 300, 308, 295, 292, -1, -1 },
		.pme_group_vector = {
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_PREF_ST 303
	[ POWER6_PME_PM_L2_PREF_ST ] = {
		.pme_name = "PM_L2_PREF_ST",
		.pme_short_desc = "L2 cache prefetches",
		.pme_long_desc = "L2 cache prefetches",
		.pme_event_ids = { 189, 199, 187, 192, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0002000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_STCX_FAIL 304
	[ POWER6_PME_PM_MRK_STCX_FAIL ] = {
		.pme_name = "PM_MRK_STCX_FAIL",
		.pme_short_desc = "Marked STCX failed",
		.pme_long_desc = "A marked stcx (stwcx or stdcx) failed",
		.pme_event_ids = { 281, 293, 276, 279, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000400000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_LHS 305
	[ POWER6_PME_PM_LSU0_REJECT_LHS ] = {
		.pme_name = "PM_LSU0_REJECT_LHS",
		.pme_short_desc = "LSU0 load hit store reject",
		.pme_long_desc = "LSU0 load hit store reject",
		.pme_event_ids = { 213, 222, 208, 213, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000020ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_EXP_EQ 306
	[ POWER6_PME_PM_DFU_EXP_EQ ] = {
		.pme_name = "PM_DFU_EXP_EQ",
		.pme_short_desc = "DFU operand exponents are equal for add type",
		.pme_long_desc = "DFU operand exponents are equal for add type",
		.pme_event_ids = { 28, 35, 27, 35, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_FP_FX_MULT 307
	[ POWER6_PME_PM_DPU_HELD_FP_FX_MULT ] = {
		.pme_name = "PM_DPU_HELD_FP_FX_MULT",
		.pme_short_desc = "DISP unit held due to non fixed multiple/divide after fixed multiply/divide",
		.pme_long_desc = "DISP unit held due to non fixed multiple/divide after fixed multiply/divide",
		.pme_event_ids = { 36, 44, 35, 43, -1, -1 },
		.pme_group_vector = {
			0x0000010000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_LD_MISS_DATA 308
	[ POWER6_PME_PM_L2_LD_MISS_DATA ] = {
		.pme_name = "PM_L2_LD_MISS_DATA",
		.pme_short_desc = "L2 data load misses",
		.pme_long_desc = "L2 data load misses",
		.pme_event_ids = { -1, 195, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L35_MOD_CYC 309
	[ POWER6_PME_PM_DATA_FROM_L35_MOD_CYC ] = {
		.pme_name = "PM_DATA_FROM_L35_MOD_CYC",
		.pme_short_desc = "Load latency from L3.5 modified",
		.pme_long_desc = "Load latency from L3.5 modified",
		.pme_event_ids = { -1, -1, -1, 18, -1, -1 },
		.pme_group_vector = {
			0x0000000000208000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FLUSH_FXU 310
	[ POWER6_PME_PM_FLUSH_FXU ] = {
		.pme_name = "PM_FLUSH_FXU",
		.pme_short_desc = "Flush caused by FXU exception",
		.pme_long_desc = "Flush caused by FXU exception",
		.pme_event_ids = { 70, 79, 68, 76, -1, -1 },
		.pme_group_vector = {
			0x0002000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_1 311
	[ POWER6_PME_PM_FPU_ISSUE_1 ] = {
		.pme_name = "PM_FPU_ISSUE_1",
		.pme_short_desc = "FPU issue 1 per cycle",
		.pme_long_desc = "FPU issue 1 per cycle",
		.pme_event_ids = { 108, 116, 104, 113, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_LMEM_CYC 312
	[ POWER6_PME_PM_DATA_FROM_LMEM_CYC ] = {
		.pme_name = "PM_DATA_FROM_LMEM_CYC",
		.pme_short_desc = "Load latency from local memory",
		.pme_long_desc = "Load latency from local memory",
		.pme_event_ids = { -1, 22, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000102000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_LSU_SOPS 313
	[ POWER6_PME_PM_DPU_HELD_LSU_SOPS ] = {
		.pme_name = "PM_DPU_HELD_LSU_SOPS",
		.pme_short_desc = "DISP unit held due to LSU slow ops (sync",
		.pme_long_desc = " tlbie",
		.pme_event_ids = { 45, 53, 44, 52, -1, -1 },
		.pme_group_vector = {
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_PTEG_2ND_HALF 314
	[ POWER6_PME_PM_INST_PTEG_2ND_HALF ] = {
		.pme_name = "PM_INST_PTEG_2ND_HALF",
		.pme_short_desc = "Instruction table walk matched in second half primary PTEG",
		.pme_long_desc = "Instruction table walk matched in second half primary PTEG",
		.pme_event_ids = { 149, 158, 149, 155, -1, -1 },
		.pme_group_vector = {
			0x0000000200000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRESH_TIMEO 315
	[ POWER6_PME_PM_THRESH_TIMEO ] = {
		.pme_name = "PM_THRESH_TIMEO",
		.pme_short_desc = "Threshold timeout",
		.pme_long_desc = "The threshold timer expired",
		.pme_event_ids = { -1, -1, 313, -1, -1, -1 },
		.pme_group_vector = {
			0x0040000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_UST_BOTH 316
	[ POWER6_PME_PM_LSU_REJECT_UST_BOTH ] = {
		.pme_name = "PM_LSU_REJECT_UST_BOTH",
		.pme_short_desc = "Unaligned store reject both units",
		.pme_long_desc = "Unaligned store reject both units",
		.pme_event_ids = { 245, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x4000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_FAST 317
	[ POWER6_PME_PM_LSU_REJECT_FAST ] = {
		.pme_name = "PM_LSU_REJECT_FAST",
		.pme_short_desc = "LSU fast reject",
		.pme_long_desc = "LSU fast reject",
		.pme_event_ids = { -1, -1, 236, -1, -1, -1 },
		.pme_group_vector = {
			0x0800000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_THRD_PRIO 318
	[ POWER6_PME_PM_DPU_HELD_THRD_PRIO ] = {
		.pme_name = "PM_DPU_HELD_THRD_PRIO",
		.pme_short_desc = "DISP unit held due to lower priority thread",
		.pme_long_desc = "DISP unit held due to lower priority thread",
		.pme_event_ids = { 53, 61, 51, 59, -1, -1 },
		.pme_group_vector = {
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_PREF_LD 319
	[ POWER6_PME_PM_L2_PREF_LD ] = {
		.pme_name = "PM_L2_PREF_LD",
		.pme_short_desc = "L2 cache prefetches",
		.pme_long_desc = "L2 cache prefetches",
		.pme_event_ids = { 188, 198, 186, 191, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0002004000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FEST 320
	[ POWER6_PME_PM_FPU_FEST ] = {
		.pme_name = "PM_FPU_FEST",
		.pme_short_desc = "FPU executed FEST instruction",
		.pme_long_desc = "This signal is active for one cycle when executing one of the estimate instructions. This could be fres* or frsqrte* where XYZ* means XYZ or XYZ. Combined Unit 0 + Unit 1.",
		.pme_event_ids = { -1, -1, -1, 108, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000004ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_RMEM 321
	[ POWER6_PME_PM_MRK_DATA_FROM_RMEM ] = {
		.pme_name = "PM_MRK_DATA_FROM_RMEM",
		.pme_short_desc = "Marked data loaded from remote memory",
		.pme_long_desc = "Marked data loaded from remote memory",
		.pme_event_ids = { -1, -1, 256, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000008000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LD_MISS_L1_CYC 322
	[ POWER6_PME_PM_LD_MISS_L1_CYC ] = {
		.pme_name = "PM_LD_MISS_L1_CYC",
		.pme_short_desc = "L1 data load miss cycles",
		.pme_long_desc = "L1 data load miss cycles",
		.pme_event_ids = { 200, 211, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000001000ULL,
			0x0000000000000000ULL,
			0x0000000000000020ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_MISS_4K 323
	[ POWER6_PME_PM_DERAT_MISS_4K ] = {
		.pme_name = "PM_DERAT_MISS_4K",
		.pme_short_desc = "DERAT misses for 4K page",
		.pme_long_desc = "A data request (load or store) missed the ERAT for 4K page and resulted in an ERAT reload.",
		.pme_event_ids = { 351, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000040ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_COMPLETION 324
	[ POWER6_PME_PM_DPU_HELD_COMPLETION ] = {
		.pme_name = "PM_DPU_HELD_COMPLETION",
		.pme_short_desc = "DISP unit held due to completion holding dispatch ",
		.pme_long_desc = "DISP unit held due to completion holding dispatch ",
		.pme_event_ids = { 31, 39, 30, 38, -1, -1 },
		.pme_group_vector = {
			0x0000110000000000ULL,
			0x0000000000000000ULL,
			0x0300000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_STALL_ST 325
	[ POWER6_PME_PM_FPU_ISSUE_STALL_ST ] = {
		.pme_name = "PM_FPU_ISSUE_STALL_ST",
		.pme_short_desc = "FPU issue stalled due to store",
		.pme_long_desc = "FPU issue stalled due to store",
		.pme_event_ids = { 113, 121, 109, 118, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0060000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_DC_INV 326
	[ POWER6_PME_PM_L2SB_DC_INV ] = {
		.pme_name = "PM_L2SB_DC_INV",
		.pme_short_desc = "L2 slice B D cache invalidate",
		.pme_long_desc = "L2 slice B D cache invalidate",
		.pme_event_ids = { 173, 182, 173, 179, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L25_SHR 327
	[ POWER6_PME_PM_PTEG_FROM_L25_SHR ] = {
		.pme_name = "PM_PTEG_FROM_L25_SHR",
		.pme_short_desc = "PTEG loaded from L2.5 shared",
		.pme_long_desc = "PTEG loaded from L2.5 shared",
		.pme_event_ids = { -1, -1, -1, 290, -1, -1 },
		.pme_group_vector = {
			0x0000000008000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_DL2L3_MOD 328
	[ POWER6_PME_PM_PTEG_FROM_DL2L3_MOD ] = {
		.pme_name = "PM_PTEG_FROM_DL2L3_MOD",
		.pme_short_desc = "PTEG loaded from distant L2 or L3 modified",
		.pme_long_desc = "PTEG loaded from distant L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 289, -1, -1 },
		.pme_group_vector = {
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_CMD_RETRIED 329
	[ POWER6_PME_PM_FAB_CMD_RETRIED ] = {
		.pme_name = "PM_FAB_CMD_RETRIED",
		.pme_short_desc = "Fabric command retried",
		.pme_long_desc = "Fabric command retried",
		.pme_event_ids = { -1, 69, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000028000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_PRED_LSTACK 330
	[ POWER6_PME_PM_BR_PRED_LSTACK ] = {
		.pme_name = "PM_BR_PRED_LSTACK",
		.pme_short_desc = "A conditional branch was predicted",
		.pme_long_desc = " link stack",
		.pme_event_ids = { 11, 9, 9, 11, -1, -1 },
		.pme_group_vector = {
			0x0000000000000018ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GXO_DATA_CYC_BUSY 331
	[ POWER6_PME_PM_GXO_DATA_CYC_BUSY ] = {
		.pme_name = "PM_GXO_DATA_CYC_BUSY",
		.pme_short_desc = "Outbound GX Data utilization (# of cycles data out is valid)",
		.pme_long_desc = "Outbound GX Data utilization (# of cycles data out is valid)",
		.pme_event_ids = { 127, 134, 125, 133, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000200000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_SUBNORM 332
	[ POWER6_PME_PM_DFU_SUBNORM ] = {
		.pme_name = "PM_DFU_SUBNORM",
		.pme_short_desc = "DFU result is a subnormal",
		.pme_long_desc = "DFU result is a subnormal",
		.pme_event_ids = { 30, 37, 29, 37, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_OOO 333
	[ POWER6_PME_PM_FPU_ISSUE_OOO ] = {
		.pme_name = "PM_FPU_ISSUE_OOO",
		.pme_short_desc = "FPU issue out-of-order",
		.pme_long_desc = "FPU issue out-of-order",
		.pme_event_ids = { 111, 119, 107, 116, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0020000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_ULD_BOTH 334
	[ POWER6_PME_PM_LSU_REJECT_ULD_BOTH ] = {
		.pme_name = "PM_LSU_REJECT_ULD_BOTH",
		.pme_short_desc = "Unaligned load reject both units",
		.pme_long_desc = "Unaligned load reject both units",
		.pme_event_ids = { -1, 255, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x8000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_ST_MISS 335
	[ POWER6_PME_PM_L2SB_ST_MISS ] = {
		.pme_name = "PM_L2SB_ST_MISS",
		.pme_short_desc = "L2 slice B store misses",
		.pme_long_desc = "L2 slice B store misses",
		.pme_event_ids = { 183, 192, 183, 189, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000080000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L25_MOD_CYC 336
	[ POWER6_PME_PM_DATA_FROM_L25_MOD_CYC ] = {
		.pme_name = "PM_DATA_FROM_L25_MOD_CYC",
		.pme_short_desc = "Load latency from L2.5 modified",
		.pme_long_desc = "Load latency from L2.5 modified",
		.pme_event_ids = { -1, -1, -1, 17, -1, -1 },
		.pme_group_vector = {
			0x0000000000001000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_PTEG_1ST_HALF 337
	[ POWER6_PME_PM_INST_PTEG_1ST_HALF ] = {
		.pme_name = "PM_INST_PTEG_1ST_HALF",
		.pme_short_desc = "Instruction table walk matched in first half primary PTEG",
		.pme_long_desc = "Instruction table walk matched in first half primary PTEG",
		.pme_event_ids = { 148, 157, 148, 154, -1, -1 },
		.pme_group_vector = {
			0x0000000200000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_MISS_16M 338
	[ POWER6_PME_PM_DERAT_MISS_16M ] = {
		.pme_name = "PM_DERAT_MISS_16M",
		.pme_short_desc = "DERAT misses for 16M page",
		.pme_long_desc = "A data request (load or store) missed the ERAT for 16M page and resulted in an ERAT reload.",
		.pme_event_ids = { -1, -1, 343, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000040ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GX_DMA_WRITE 339
	[ POWER6_PME_PM_GX_DMA_WRITE ] = {
		.pme_name = "PM_GX_DMA_WRITE",
		.pme_short_desc = "All DMA Write Requests (including dma wrt lgcy)",
		.pme_long_desc = "All DMA Write Requests (including dma wrt lgcy)",
		.pme_event_ids = { 129, 136, 127, 135, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000800000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_DL2L3_MOD 340
	[ POWER6_PME_PM_MRK_PTEG_FROM_DL2L3_MOD ] = {
		.pme_name = "PM_MRK_PTEG_FROM_DL2L3_MOD",
		.pme_short_desc = "Marked PTEG loaded from distant L2 or L3 modified",
		.pme_long_desc = "Marked PTEG loaded from distant L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 275, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000008000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM1_DP_RQ_GLOB_LOC 341
	[ POWER6_PME_PM_MEM1_DP_RQ_GLOB_LOC ] = {
		.pme_name = "PM_MEM1_DP_RQ_GLOB_LOC",
		.pme_short_desc = "Memory read queue marking cache line double pump state from global to local side 1",
		.pme_long_desc = "Memory read queue marking cache line double pump state from global to local side 1",
		.pme_event_ids = { 254, 265, 248, 253, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_LD_REQ_DATA 342
	[ POWER6_PME_PM_L2SB_LD_REQ_DATA ] = {
		.pme_name = "PM_L2SB_LD_REQ_DATA",
		.pme_short_desc = "L2 slice B data load requests",
		.pme_long_desc = "L2 slice B data load requests",
		.pme_event_ids = { 179, 188, 179, 185, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_LD_MISS_INST 343
	[ POWER6_PME_PM_L2SA_LD_MISS_INST ] = {
		.pme_name = "PM_L2SA_LD_MISS_INST",
		.pme_short_desc = "L2 slice A instruction load misses",
		.pme_long_desc = "L2 slice A instruction load misses",
		.pme_event_ids = { 163, 172, 163, 169, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU0_REJECT_L2MISS 344
	[ POWER6_PME_PM_MRK_LSU0_REJECT_L2MISS ] = {
		.pme_name = "PM_MRK_LSU0_REJECT_L2MISS",
		.pme_short_desc = "LSU0 marked L2 miss reject",
		.pme_long_desc = "LSU0 marked L2 miss reject",
		.pme_event_ids = { 269, 281, 263, 264, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000800000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_IFU_FIN 345
	[ POWER6_PME_PM_MRK_IFU_FIN ] = {
		.pme_name = "PM_MRK_IFU_FIN",
		.pme_short_desc = "Marked instruction IFU processing finished",
		.pme_long_desc = "Marked instruction IFU processing finished",
		.pme_event_ids = { -1, 278, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000400000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L3 346
	[ POWER6_PME_PM_INST_FROM_L3 ] = {
		.pme_name = "PM_INST_FROM_L3",
		.pme_short_desc = "Instruction fetched from L3",
		.pme_long_desc = "An instruction fetch group was fetched from L3. Fetch Groups can contain up to 8 instructions",
		.pme_event_ids = { -1, -1, 145, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FXU1_FIN 347
	[ POWER6_PME_PM_FXU1_FIN ] = {
		.pme_name = "PM_FXU1_FIN",
		.pme_short_desc = "FXU1 produced a result",
		.pme_long_desc = "The Fixed Point unit 1 finished an instruction and produced a result",
		.pme_event_ids = { -1, -1, -1, 125, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x4000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_4_CYC 348
	[ POWER6_PME_PM_THRD_PRIO_4_CYC ] = {
		.pme_name = "PM_THRD_PRIO_4_CYC",
		.pme_short_desc = "Cycles thread running at priority level 4",
		.pme_long_desc = "Cycles thread running at priority level 4",
		.pme_event_ids = { -1, -1, -1, 308, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000008000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L35_MOD 349
	[ POWER6_PME_PM_MRK_DATA_FROM_L35_MOD ] = {
		.pme_name = "PM_MRK_DATA_FROM_L35_MOD",
		.pme_short_desc = "Marked data loaded from L3.5 modified",
		.pme_long_desc = "Marked data loaded from L3.5 modified",
		.pme_event_ids = { 261, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_SET_MPRED 350
	[ POWER6_PME_PM_LSU_REJECT_SET_MPRED ] = {
		.pme_name = "PM_LSU_REJECT_SET_MPRED",
		.pme_short_desc = "LSU reject due to mispredicted set",
		.pme_long_desc = "LSU reject due to mispredicted set",
		.pme_event_ids = { -1, 252, 238, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000001ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_MISS_16G 351
	[ POWER6_PME_PM_MRK_DERAT_MISS_16G ] = {
		.pme_name = "PM_MRK_DERAT_MISS_16G",
		.pme_short_desc = "Marked DERAT misses for 16G page",
		.pme_long_desc = "A marked data request (load or store) missed the ERAT for 16G page and resulted in an ERAT reload.",
		.pme_event_ids = { -1, -1, -1, 346, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000020ULL }
	},
#define POWER6_PME_PM_FPU0_FXDIV 352
	[ POWER6_PME_PM_FPU0_FXDIV ] = {
		.pme_name = "PM_FPU0_FXDIV",
		.pme_short_desc = "FPU0 executed fixed point division",
		.pme_long_desc = "FPU0 executed fixed point division",
		.pme_event_ids = { 81, 90, 79, 87, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0100000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU1_REJECT_UST 353
	[ POWER6_PME_PM_MRK_LSU1_REJECT_UST ] = {
		.pme_name = "PM_MRK_LSU1_REJECT_UST",
		.pme_short_desc = "LSU1 marked unaligned store reject",
		.pme_long_desc = "LSU1 marked unaligned store reject",
		.pme_event_ids = { 275, 287, 269, 270, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_DIV_SQRT_OVERLAP 354
	[ POWER6_PME_PM_FPU_ISSUE_DIV_SQRT_OVERLAP ] = {
		.pme_name = "PM_FPU_ISSUE_DIV_SQRT_OVERLAP",
		.pme_short_desc = "FPU divide/sqrt overlapped with other divide/sqrt",
		.pme_long_desc = "FPU divide/sqrt overlapped with other divide/sqrt",
		.pme_event_ids = { 110, 118, 106, 115, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0060000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L35_SHR 355
	[ POWER6_PME_PM_INST_FROM_L35_SHR ] = {
		.pme_name = "PM_INST_FROM_L35_SHR",
		.pme_short_desc = "Instruction fetched from L3.5 shared",
		.pme_long_desc = "Instruction fetched from L3.5 shared",
		.pme_event_ids = { -1, 155, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU_REJECT_LHS 356
	[ POWER6_PME_PM_MRK_LSU_REJECT_LHS ] = {
		.pme_name = "PM_MRK_LSU_REJECT_LHS",
		.pme_short_desc = "Marked load hit store reject",
		.pme_long_desc = "Marked load hit store reject",
		.pme_event_ids = { -1, -1, -1, 273, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000010000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_LMQ_FULL_CYC 357
	[ POWER6_PME_PM_LSU_LMQ_FULL_CYC ] = {
		.pme_name = "PM_LSU_LMQ_FULL_CYC",
		.pme_short_desc = "Cycles LMQ full",
		.pme_long_desc = "The LMQ was full",
		.pme_event_ids = { 238, 247, 233, 237, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0000008000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_SYNC_COUNT 358
	[ POWER6_PME_PM_SYNC_COUNT ] = {
		.pme_name = "PM_SYNC_COUNT",
		.pme_short_desc = "SYNC instructions completed",
		.pme_long_desc = "SYNC instructions completed",
		.pme_event_ids = { 342, 349, 336, 334, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0061800000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM0_DP_RQ_LOC_GLOB 359
	[ POWER6_PME_PM_MEM0_DP_RQ_LOC_GLOB ] = {
		.pme_name = "PM_MEM0_DP_RQ_LOC_GLOB",
		.pme_short_desc = "Memory read queue marking cache line double pump state from local to global side 0",
		.pme_long_desc = "Memory read queue marking cache line double pump state from local to global side 0",
		.pme_event_ids = { 251, 262, 245, 250, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_CASTOUT_MOD 360
	[ POWER6_PME_PM_L2SA_CASTOUT_MOD ] = {
		.pme_name = "PM_L2SA_CASTOUT_MOD",
		.pme_short_desc = "L2 slice A castouts - Modified",
		.pme_long_desc = "L2 slice A castouts - Modified",
		.pme_event_ids = { 157, 166, 157, 163, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_BOTH_COUNT 361
	[ POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_BOTH_COUNT ] = {
		.pme_name = "PM_LSU_LMQ_SRQ_EMPTY_BOTH_COUNT",
		.pme_short_desc = "Periods both threads LMQ and SRQ empty",
		.pme_long_desc = "Periods both threads LMQ and SRQ empty",
		.pme_event_ids = { -1, -1, 341, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0008008000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_MEM_DP 362
	[ POWER6_PME_PM_PTEG_FROM_MEM_DP ] = {
		.pme_name = "PM_PTEG_FROM_MEM_DP",
		.pme_short_desc = "PTEG loaded from double pump memory",
		.pme_long_desc = "PTEG loaded from double pump memory",
		.pme_event_ids = { 298, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_SLOW 363
	[ POWER6_PME_PM_LSU_REJECT_SLOW ] = {
		.pme_name = "PM_LSU_REJECT_SLOW",
		.pme_short_desc = "LSU slow reject",
		.pme_long_desc = "LSU slow reject",
		.pme_event_ids = { -1, 253, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L25_MOD 364
	[ POWER6_PME_PM_PTEG_FROM_L25_MOD ] = {
		.pme_name = "PM_PTEG_FROM_L25_MOD",
		.pme_short_desc = "PTEG loaded from L2.5 modified",
		.pme_long_desc = "PTEG loaded from L2.5 modified",
		.pme_event_ids = { -1, -1, 291, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000008000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_7_CYC 365
	[ POWER6_PME_PM_THRD_PRIO_7_CYC ] = {
		.pme_name = "PM_THRD_PRIO_7_CYC",
		.pme_short_desc = "Cycles thread running at priority level 7",
		.pme_long_desc = "Cycles thread running at priority level 7",
		.pme_event_ids = { 317, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000008000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_RL2L3_SHR 366
	[ POWER6_PME_PM_MRK_PTEG_FROM_RL2L3_SHR ] = {
		.pme_name = "PM_MRK_PTEG_FROM_RL2L3_SHR",
		.pme_short_desc = "Marked PTEG loaded from remote L2 or L3 shared",
		.pme_long_desc = "Marked PTEG loaded from remote L2 or L3 shared",
		.pme_event_ids = { -1, 292, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000080000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ST_REQ_L2 367
	[ POWER6_PME_PM_ST_REQ_L2 ] = {
		.pme_name = "PM_ST_REQ_L2",
		.pme_short_desc = "L2 store requests",
		.pme_long_desc = "L2 store requests",
		.pme_event_ids = { -1, 317, 301, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000010000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ST_REF_L1 368
	[ POWER6_PME_PM_ST_REF_L1 ] = {
		.pme_name = "PM_ST_REF_L1",
		.pme_short_desc = "L1 D cache store references",
		.pme_long_desc = "Total DL1 Store references",
		.pme_event_ids = { 310, 315, 300, 300, -1, -1 },
		.pme_group_vector = {
			0x0000c00000000000ULL,
			0x0000000000000000ULL,
			0x2000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_STALL_THRD 369
	[ POWER6_PME_PM_FPU_ISSUE_STALL_THRD ] = {
		.pme_name = "PM_FPU_ISSUE_STALL_THRD",
		.pme_short_desc = "FPU issue stalled due to thread resource conflict",
		.pme_long_desc = "FPU issue stalled due to thread resource conflict",
		.pme_event_ids = { 114, 122, 110, 119, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0040000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_RUN_COUNT 370
	[ POWER6_PME_PM_RUN_COUNT ] = {
		.pme_name = "PM_RUN_COUNT",
		.pme_short_desc = "Run Periods",
		.pme_long_desc = "Processor Periods gated by the run latch",
		.pme_event_ids = { 343, 350, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_RUN_CYC 371
	[ POWER6_PME_PM_RUN_CYC ] = {
		.pme_name = "PM_RUN_CYC",
		.pme_short_desc = "Run cycles",
		.pme_long_desc = "Processor Cycles gated by the run latch",
		.pme_event_ids = { 302, 309, -1, -1, -1, 0 },
		.pme_group_vector = {
			0xffffffffffffffffULL,
			0xffffffffffffffffULL,
			0xffffffffffffffffULL,
			0x000000000000003fULL }
	},
#define POWER6_PME_PM_PTEG_FROM_RMEM 372
	[ POWER6_PME_PM_PTEG_FROM_RMEM ] = {
		.pme_name = "PM_PTEG_FROM_RMEM",
		.pme_short_desc = "PTEG loaded from remote memory",
		.pme_long_desc = "PTEG loaded from remote memory",
		.pme_event_ids = { -1, -1, 294, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_LDF 373
	[ POWER6_PME_PM_LSU0_LDF ] = {
		.pme_name = "PM_LSU0_LDF",
		.pme_short_desc = "LSU0 executed Floating Point load instruction",
		.pme_long_desc = "A floating point load was executed from LSU unit 0",
		.pme_event_ids = { 205, 214, 200, 205, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_ST_MISS_L1 374
	[ POWER6_PME_PM_ST_MISS_L1 ] = {
		.pme_name = "PM_ST_MISS_L1",
		.pme_short_desc = "L1 D cache store misses",
		.pme_long_desc = "A store missed the dcache",
		.pme_event_ids = { 309, 314, 299, 299, -1, -1 },
		.pme_group_vector = {
			0x0000800000000000ULL,
			0x0000000000000000ULL,
			0x1080000000000000ULL,
			0x0000000000000004ULL }
	},
#define POWER6_PME_PM_INST_FROM_DL2L3_SHR 375
	[ POWER6_PME_PM_INST_FROM_DL2L3_SHR ] = {
		.pme_name = "PM_INST_FROM_DL2L3_SHR",
		.pme_short_desc = "Instruction fetched from distant L2 or L3 shared",
		.pme_long_desc = "Instruction fetched from distant L2 or L3 shared",
		.pme_event_ids = { -1, -1, 142, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000001000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_IC_INV 376
	[ POWER6_PME_PM_L2SA_IC_INV ] = {
		.pme_name = "PM_L2SA_IC_INV",
		.pme_short_desc = "L2 slice A I cache invalidate",
		.pme_long_desc = "L2 slice A I cache invalidate",
		.pme_event_ids = { 160, 169, 160, 166, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000400000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_ONE_RUN_CYC 377
	[ POWER6_PME_PM_THRD_ONE_RUN_CYC ] = {
		.pme_name = "PM_THRD_ONE_RUN_CYC",
		.pme_short_desc = "One of the threads in run cycles",
		.pme_long_desc = "One of the threads in run cycles",
		.pme_event_ids = { 315, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0020000000000002ULL,
			0x0000000000000000ULL,
			0x0001000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_LD_REQ_INST 378
	[ POWER6_PME_PM_L2SB_LD_REQ_INST ] = {
		.pme_name = "PM_L2SB_LD_REQ_INST",
		.pme_short_desc = "L2 slice B instruction load requests",
		.pme_long_desc = "L2 slice B instruction load requests",
		.pme_event_ids = { 180, 189, 180, 186, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L25_MOD 379
	[ POWER6_PME_PM_MRK_DATA_FROM_L25_MOD ] = {
		.pme_name = "PM_MRK_DATA_FROM_L25_MOD",
		.pme_short_desc = "Marked data loaded from L2.5 modified",
		.pme_long_desc = "DL1 was reloaded with modified (M) data from the L2 of a chip on this MCM due to a marked demand load",
		.pme_event_ids = { -1, -1, 253, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_XTHRD 380
	[ POWER6_PME_PM_DPU_HELD_XTHRD ] = {
		.pme_name = "PM_DPU_HELD_XTHRD",
		.pme_short_desc = "DISP unit held due to cross thread resource conflicts",
		.pme_long_desc = "DISP unit held due to cross thread resource conflicts",
		.pme_event_ids = { 55, 63, 53, 61, -1, -1 },
		.pme_group_vector = {
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_ST_REQ 381
	[ POWER6_PME_PM_L2SB_ST_REQ ] = {
		.pme_name = "PM_L2SB_ST_REQ",
		.pme_short_desc = "L2 slice B store requests",
		.pme_long_desc = "A store request as seen at the L2 directory has been made from the core. Stores are counted after gathering in the L2 store queues. The event is provided on each of the three slices A,B,and C.",
		.pme_event_ids = { 184, 193, 184, 190, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0001080000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L21 382
	[ POWER6_PME_PM_INST_FROM_L21 ] = {
		.pme_name = "PM_INST_FROM_L21",
		.pme_short_desc = "Instruction fetched from private L2 other core",
		.pme_long_desc = "Instruction fetched from private L2 other core",
		.pme_event_ids = { -1, 154, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000004400000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L3MISS 383
	[ POWER6_PME_PM_INST_FROM_L3MISS ] = {
		.pme_name = "PM_INST_FROM_L3MISS",
		.pme_short_desc = "Instruction fetched missed L3",
		.pme_long_desc = "Instruction fetched missed L3",
		.pme_event_ids = { -1, -1, 146, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000004000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000008ULL }
	},
#define POWER6_PME_PM_L3SB_HIT 384
	[ POWER6_PME_PM_L3SB_HIT ] = {
		.pme_name = "PM_L3SB_HIT",
		.pme_short_desc = "L3 slice B hits",
		.pme_long_desc = "L3 slice B hits",
		.pme_event_ids = { 194, 204, 192, 197, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0008000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_EE_OFF_EXT_INT 385
	[ POWER6_PME_PM_EE_OFF_EXT_INT ] = {
		.pme_name = "PM_EE_OFF_EXT_INT",
		.pme_short_desc = "Cycles MSR(EE) bit off and external interrupt pending",
		.pme_long_desc = "Cycles MSR(EE) bit off and external interrupt pending",
		.pme_event_ids = { 57, 66, 56, 64, -1, -1 },
		.pme_group_vector = {
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_DL2L3_MOD 386
	[ POWER6_PME_PM_INST_FROM_DL2L3_MOD ] = {
		.pme_name = "PM_INST_FROM_DL2L3_MOD",
		.pme_short_desc = "Instruction fetched from distant L2 or L3 modified",
		.pme_long_desc = "Instruction fetched from distant L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 148, -1, -1 },
		.pme_group_vector = {
			0x0000000001000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC6_OVERFLOW 387
	[ POWER6_PME_PM_PMC6_OVERFLOW ] = {
		.pme_name = "PM_PMC6_OVERFLOW",
		.pme_short_desc = "PMC6 Overflow",
		.pme_long_desc = "PMC6 Overflow",
		.pme_event_ids = { -1, -1, 289, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FLOP 388
	[ POWER6_PME_PM_FPU_FLOP ] = {
		.pme_name = "PM_FPU_FLOP",
		.pme_short_desc = "FPU executed 1FLOP",
		.pme_long_desc = " FMA",
		.pme_event_ids = { 104, -1, -1, 109, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FXU_BUSY 389
	[ POWER6_PME_PM_FXU_BUSY ] = {
		.pme_name = "PM_FXU_BUSY",
		.pme_short_desc = "FXU busy",
		.pme_long_desc = "FXU0 and FXU1 are both busy",
		.pme_event_ids = { -1, 125, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FLOP 390
	[ POWER6_PME_PM_FPU1_FLOP ] = {
		.pme_name = "PM_FPU1_FLOP",
		.pme_short_desc = "FPU1 executed 1FLOP",
		.pme_long_desc = " FMA",
		.pme_event_ids = { 91, 100, 89, 97, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_RELOAD_SHR 391
	[ POWER6_PME_PM_IC_RELOAD_SHR ] = {
		.pme_name = "PM_IC_RELOAD_SHR",
		.pme_short_desc = "I cache line reloading to be shared by threads",
		.pme_long_desc = "I cache line reloading to be shared by threads",
		.pme_event_ids = { 135, 144, 134, 141, -1, -1 },
		.pme_group_vector = {
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_TABLEWALK_CYC 392
	[ POWER6_PME_PM_INST_TABLEWALK_CYC ] = {
		.pme_name = "PM_INST_TABLEWALK_CYC",
		.pme_short_desc = "Cycles doing instruction tablewalks",
		.pme_long_desc = "Cycles doing instruction tablewalks",
		.pme_event_ids = { 151, 160, 151, 157, -1, -1 },
		.pme_group_vector = {
			0x0000000200000000ULL,
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_RL2L3_MOD_CYC 393
	[ POWER6_PME_PM_DATA_FROM_RL2L3_MOD_CYC ] = {
		.pme_name = "PM_DATA_FROM_RL2L3_MOD_CYC",
		.pme_short_desc = "Load latency from remote L2 or L3 modified",
		.pme_long_desc = "Load latency from remote L2 or L3 modified",
		.pme_event_ids = { -1, -1, -1, 22, -1, -1 },
		.pme_group_vector = {
			0x0000000000010000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_5or6_CYC 394
	[ POWER6_PME_PM_THRD_PRIO_DIFF_5or6_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_5or6_CYC",
		.pme_short_desc = "Cycles thread priority difference is 5 or 6",
		.pme_long_desc = "Cycles thread priority difference is 5 or 6",
		.pme_event_ids = { -1, -1, -1, 309, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000010000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IBUF_FULL_CYC 395
	[ POWER6_PME_PM_IBUF_FULL_CYC ] = {
		.pme_name = "PM_IBUF_FULL_CYC",
		.pme_short_desc = "Cycles instruction buffer full",
		.pme_long_desc = "Cycles instruction buffer full",
		.pme_event_ids = { 130, 138, 128, 136, -1, -1 },
		.pme_group_vector = {
			0x0001000000000000ULL,
			0x0000000000000000ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_LD_REQ 396
	[ POWER6_PME_PM_L2SA_LD_REQ ] = {
		.pme_name = "PM_L2SA_LD_REQ",
		.pme_short_desc = "L2 slice A load requests ",
		.pme_long_desc = "L2 slice A load requests ",
		.pme_event_ids = { 164, 173, 164, 170, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000800000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX1_LD_WRBACK 397
	[ POWER6_PME_PM_VMX1_LD_WRBACK ] = {
		.pme_name = "PM_VMX1_LD_WRBACK",
		.pme_short_desc = "VMX1 load writeback valid",
		.pme_long_desc = "VMX1 load writeback valid",
		.pme_event_ids = { 327, 334, 321, 319, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000400000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_FPU_FIN 398
	[ POWER6_PME_PM_MRK_FPU_FIN ] = {
		.pme_name = "PM_MRK_FPU_FIN",
		.pme_short_desc = "Marked instruction FPU processing finished",
		.pme_long_desc = "One of the Floating Point Units finished a marked instruction. Instructions that finish may not necessary complete",
		.pme_event_ids = { -1, 276, 261, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000800100000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_5_CYC 399
	[ POWER6_PME_PM_THRD_PRIO_5_CYC ] = {
		.pme_name = "PM_THRD_PRIO_5_CYC",
		.pme_short_desc = "Cycles thread running at priority level 5",
		.pme_long_desc = "Cycles thread running at priority level 5",
		.pme_event_ids = { -1, -1, 309, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000008000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_BACK2BACK 400
	[ POWER6_PME_PM_DFU_BACK2BACK ] = {
		.pme_name = "PM_DFU_BACK2BACK",
		.pme_short_desc = "DFU back to back operations executed",
		.pme_long_desc = "DFU back to back operations executed",
		.pme_event_ids = { 25, 32, 24, 32, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_LMEM 401
	[ POWER6_PME_PM_MRK_DATA_FROM_LMEM ] = {
		.pme_name = "PM_MRK_DATA_FROM_LMEM",
		.pme_short_desc = "Marked data loaded from local memory",
		.pme_long_desc = "Marked data loaded from local memory",
		.pme_event_ids = { -1, -1, -1, 258, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000004000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_LHS 402
	[ POWER6_PME_PM_LSU_REJECT_LHS ] = {
		.pme_name = "PM_LSU_REJECT_LHS",
		.pme_short_desc = "Load hit store reject",
		.pme_long_desc = "Load hit store reject",
		.pme_event_ids = { 240, -1, -1, 240, -1, -1 },
		.pme_group_vector = {
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_SPR 403
	[ POWER6_PME_PM_DPU_HELD_SPR ] = {
		.pme_name = "PM_DPU_HELD_SPR",
		.pme_short_desc = "DISP unit held due to MTSPR/MFSPR",
		.pme_long_desc = "DISP unit held due to MTSPR/MFSPR",
		.pme_event_ids = { 50, 59, 49, 57, -1, -1 },
		.pme_group_vector = {
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FREQ_DOWN 404
	[ POWER6_PME_PM_FREQ_DOWN ] = {
		.pme_name = "PM_FREQ_DOWN",
		.pme_short_desc = "Frequency is being slewed down due to Power Management",
		.pme_long_desc = "Frequency is being slewed down due to Power Management",
		.pme_event_ids = { -1, -1, 115, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000400000000ULL,
			0x0000000000000000ULL,
			0x0000020000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_ENC_BCD_DPD 405
	[ POWER6_PME_PM_DFU_ENC_BCD_DPD ] = {
		.pme_name = "PM_DFU_ENC_BCD_DPD",
		.pme_short_desc = "DFU Encode BCD to DPD",
		.pme_long_desc = "DFU Encode BCD to DPD",
		.pme_event_ids = { 27, 34, 26, 34, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_GPR 406
	[ POWER6_PME_PM_DPU_HELD_GPR ] = {
		.pme_name = "PM_DPU_HELD_GPR",
		.pme_short_desc = "DISP unit held due to GPR dependencies",
		.pme_long_desc = "DISP unit held due to GPR dependencies",
		.pme_event_ids = { 39, 47, 38, 46, -1, -1 },
		.pme_group_vector = {
			0x0000012000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_NCST 407
	[ POWER6_PME_PM_LSU0_NCST ] = {
		.pme_name = "PM_LSU0_NCST",
		.pme_short_desc = "LSU0 non-cachable stores",
		.pme_long_desc = "LSU0 non-cachable stores",
		.pme_event_ids = { 207, 216, 202, 207, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_INST_ISSUED 408
	[ POWER6_PME_PM_MRK_INST_ISSUED ] = {
		.pme_name = "PM_MRK_INST_ISSUED",
		.pme_short_desc = "Marked instruction issued",
		.pme_long_desc = "Marked instruction issued",
		.pme_event_ids = { 268, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_RL2L3_SHR 409
	[ POWER6_PME_PM_INST_FROM_RL2L3_SHR ] = {
		.pme_name = "PM_INST_FROM_RL2L3_SHR",
		.pme_short_desc = "Instruction fetched from remote L2 or L3 shared",
		.pme_long_desc = "Instruction fetched from remote L2 or L3 shared",
		.pme_event_ids = { -1, 156, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000001000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_DENORM 410
	[ POWER6_PME_PM_FPU_DENORM ] = {
		.pme_name = "PM_FPU_DENORM",
		.pme_short_desc = "FPU received denormalized data",
		.pme_long_desc = "This signal is active for one cycle when one of the operands is denormalized. Combined Unit 0 + Unit 1",
		.pme_event_ids = { -1, 110, 99, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_L3MISS 411
	[ POWER6_PME_PM_PTEG_FROM_L3MISS ] = {
		.pme_name = "PM_PTEG_FROM_L3MISS",
		.pme_short_desc = "PTEG loaded from L3 miss",
		.pme_long_desc = "PTEG loaded from L3 miss",
		.pme_event_ids = { -1, -1, 293, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000020000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_RUN_PURR 412
	[ POWER6_PME_PM_RUN_PURR ] = {
		.pme_name = "PM_RUN_PURR",
		.pme_short_desc = "Run PURR Event",
		.pme_long_desc = "Run PURR Event",
		.pme_event_ids = { -1, -1, -1, 347, -1, -1 },
		.pme_group_vector = {
			0x0000000000000002ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX0_LD_WRBACK 413
	[ POWER6_PME_PM_MRK_VMX0_LD_WRBACK ] = {
		.pme_name = "PM_MRK_VMX0_LD_WRBACK",
		.pme_short_desc = "Marked VMX0 load writeback valid",
		.pme_long_desc = "Marked VMX0 load writeback valid",
		.pme_event_ids = { 283, 295, 278, 280, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000200000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_MISS 414
	[ POWER6_PME_PM_L2_MISS ] = {
		.pme_name = "PM_L2_MISS",
		.pme_short_desc = "L2 cache misses",
		.pme_long_desc = "L2 cache misses",
		.pme_event_ids = { -1, 197, 185, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000104000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000008ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L3 415
	[ POWER6_PME_PM_MRK_DATA_FROM_L3 ] = {
		.pme_name = "PM_MRK_DATA_FROM_L3",
		.pme_short_desc = "Marked data loaded from L3",
		.pme_long_desc = "DL1 was reloaded from the local L3 due to a marked demand load",
		.pme_event_ids = { -1, -1, 254, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000001000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU1_REJECT_LHS 416
	[ POWER6_PME_PM_MRK_LSU1_REJECT_LHS ] = {
		.pme_name = "PM_MRK_LSU1_REJECT_LHS",
		.pme_short_desc = "LSU1 marked load hit store reject",
		.pme_long_desc = "LSU1 marked load hit store reject",
		.pme_event_ids = { 273, 285, 267, 268, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_LD_MISS_INST 417
	[ POWER6_PME_PM_L2SB_LD_MISS_INST ] = {
		.pme_name = "PM_L2SB_LD_MISS_INST",
		.pme_short_desc = "L2 slice B instruction load misses",
		.pme_long_desc = "L2 slice B instruction load misses",
		.pme_event_ids = { 177, 186, 177, 183, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PTEG_FROM_RL2L3_SHR 418
	[ POWER6_PME_PM_PTEG_FROM_RL2L3_SHR ] = {
		.pme_name = "PM_PTEG_FROM_RL2L3_SHR",
		.pme_short_desc = "PTEG loaded from remote L2 or L3 shared",
		.pme_long_desc = "PTEG loaded from remote L2 or L3 shared",
		.pme_event_ids = { -1, 307, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_MISS_64K 419
	[ POWER6_PME_PM_MRK_DERAT_MISS_64K ] = {
		.pme_name = "PM_MRK_DERAT_MISS_64K",
		.pme_short_desc = "Marked DERAT misses for 64K page",
		.pme_long_desc = "A marked data request (load or store) missed the ERAT for 64K page and resulted in an ERAT reload.",
		.pme_event_ids = { 354, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000020ULL }
	},
#define POWER6_PME_PM_LWSYNC 420
	[ POWER6_PME_PM_LWSYNC ] = {
		.pme_name = "PM_LWSYNC",
		.pme_short_desc = "Isync instruction completed",
		.pme_long_desc = "Isync instruction completed",
		.pme_event_ids = { 247, 258, 241, 246, -1, -1 },
		.pme_group_vector = {
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FXMULT 421
	[ POWER6_PME_PM_FPU1_FXMULT ] = {
		.pme_name = "PM_FPU1_FXMULT",
		.pme_short_desc = "FPU1 executed fixed point multiplication",
		.pme_long_desc = "FPU1 executed fixed point multiplication",
		.pme_event_ids = { 97, 106, 95, 103, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM0_DP_CL_WR_GLOB 422
	[ POWER6_PME_PM_MEM0_DP_CL_WR_GLOB ] = {
		.pme_name = "PM_MEM0_DP_CL_WR_GLOB",
		.pme_short_desc = "cacheline write setting dp to global side 0",
		.pme_long_desc = "cacheline write setting dp to global side 0",
		.pme_event_ids = { 248, 259, 242, 247, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000080000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_PARTIAL_SECTOR 423
	[ POWER6_PME_PM_LSU0_REJECT_PARTIAL_SECTOR ] = {
		.pme_name = "PM_LSU0_REJECT_PARTIAL_SECTOR",
		.pme_short_desc = "LSU0 reject due to partial sector valid",
		.pme_long_desc = "LSU0 reject due to partial sector valid",
		.pme_event_ids = { 215, 224, 210, 215, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000010ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_IMC_MATCH_CMPL 424
	[ POWER6_PME_PM_INST_IMC_MATCH_CMPL ] = {
		.pme_name = "PM_INST_IMC_MATCH_CMPL",
		.pme_short_desc = "IMC matched instructions completed",
		.pme_long_desc = "Number of instructions resulting from the marked instructions expansion that completed.",
		.pme_event_ids = { 147, -1, -1, 153, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_THERMAL 425
	[ POWER6_PME_PM_DPU_HELD_THERMAL ] = {
		.pme_name = "PM_DPU_HELD_THERMAL",
		.pme_short_desc = "DISP unit held due to thermal condition",
		.pme_long_desc = "DISP unit held due to thermal condition",
		.pme_event_ids = { 52, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000001400000000ULL,
			0x0000000000000000ULL,
			0x0004000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FRSP 426
	[ POWER6_PME_PM_FPU_FRSP ] = {
		.pme_name = "PM_FPU_FRSP",
		.pme_short_desc = "FPU executed FRSP instruction",
		.pme_long_desc = "FPU executed FRSP instruction",
		.pme_event_ids = { -1, 113, 101, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000005ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_INST_FIN 427
	[ POWER6_PME_PM_MRK_INST_FIN ] = {
		.pme_name = "PM_MRK_INST_FIN",
		.pme_short_desc = "Marked instruction finished",
		.pme_long_desc = "One of the execution units finished a marked instruction. Instructions that finish may not necessary complete",
		.pme_event_ids = { -1, -1, 262, 262, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_DL2L3_SHR 428
	[ POWER6_PME_PM_MRK_PTEG_FROM_DL2L3_SHR ] = {
		.pme_name = "PM_MRK_PTEG_FROM_DL2L3_SHR",
		.pme_short_desc = "Marked PTEG loaded from distant L2 or L3 shared",
		.pme_long_desc = "Marked PTEG loaded from distant L2 or L3 shared",
		.pme_event_ids = { -1, -1, 271, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DTLB_REF 429
	[ POWER6_PME_PM_MRK_DTLB_REF ] = {
		.pme_name = "PM_MRK_DTLB_REF",
		.pme_short_desc = "Marked Data TLB reference",
		.pme_long_desc = "Marked Data TLB reference",
		.pme_event_ids = { 264, 273, 258, 259, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000200000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L25_SHR 430
	[ POWER6_PME_PM_MRK_PTEG_FROM_L25_SHR ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L25_SHR",
		.pme_short_desc = "Marked PTEG loaded from L2.5 shared",
		.pme_long_desc = "Marked PTEG loaded from L2.5 shared",
		.pme_event_ids = { -1, -1, -1, 276, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_LSU 431
	[ POWER6_PME_PM_DPU_HELD_LSU ] = {
		.pme_name = "PM_DPU_HELD_LSU",
		.pme_short_desc = "DISP unit held due to LSU move or invalidate SLB and SR",
		.pme_long_desc = "DISP unit held due to LSU move or invalidate SLB and SR",
		.pme_event_ids = { 44, 52, 43, 51, -1, -1 },
		.pme_group_vector = {
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_FSQRT_FDIV 432
	[ POWER6_PME_PM_FPU_FSQRT_FDIV ] = {
		.pme_name = "PM_FPU_FSQRT_FDIV",
		.pme_short_desc = "FPU executed FSQRT or FDIV instruction",
		.pme_long_desc = "FPU executed FSQRT or FDIV instruction",
		.pme_event_ids = { -1, 114, 102, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0400000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_COUNT 433
	[ POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_COUNT ] = {
		.pme_name = "PM_LSU_LMQ_SRQ_EMPTY_COUNT",
		.pme_short_desc = "Periods LMQ and SRQ empty",
		.pme_long_desc = "Periods when both the LMQ and SRQ are empty (LSU is idle)",
		.pme_event_ids = { -1, 359, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0020008000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_PTEG_SECONDARY 434
	[ POWER6_PME_PM_DATA_PTEG_SECONDARY ] = {
		.pme_name = "PM_DATA_PTEG_SECONDARY",
		.pme_short_desc = "Data table walk matched in secondary PTEG",
		.pme_long_desc = "Data table walk matched in secondary PTEG",
		.pme_event_ids = { 19, 27, 19, 26, -1, -1 },
		.pme_group_vector = {
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FEST 435
	[ POWER6_PME_PM_FPU1_FEST ] = {
		.pme_name = "PM_FPU1_FEST",
		.pme_short_desc = "FPU1 executed FEST instruction",
		.pme_long_desc = "This signal is active for one cycle when fp1 is executing one of the estimate instructions. This could be fres* or frsqrte* where XYZ* means XYZ or XYZ. ",
		.pme_event_ids = { 89, 98, 87, 95, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x6000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SA_LD_HIT 436
	[ POWER6_PME_PM_L2SA_LD_HIT ] = {
		.pme_name = "PM_L2SA_LD_HIT",
		.pme_short_desc = "L2 slice A load hits",
		.pme_long_desc = "L2 slice A load hits",
		.pme_event_ids = { 161, 170, 161, 167, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000800000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_MEM_DP_CYC 437
	[ POWER6_PME_PM_DATA_FROM_MEM_DP_CYC ] = {
		.pme_name = "PM_DATA_FROM_MEM_DP_CYC",
		.pme_short_desc = "Load latency from double pump memory",
		.pme_long_desc = "Load latency from double pump memory",
		.pme_event_ids = { -1, -1, -1, 21, -1, -1 },
		.pme_group_vector = {
			0x0000000000020000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_MPRED_CCACHE 438
	[ POWER6_PME_PM_BR_MPRED_CCACHE ] = {
		.pme_name = "PM_BR_MPRED_CCACHE",
		.pme_short_desc = "Branch misprediction due to count cache prediction",
		.pme_long_desc = "Branch misprediction due to count cache prediction",
		.pme_event_ids = { 4, 2, 2, 4, -1, -1 },
		.pme_group_vector = {
			0x0000000000000028ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_COUNT 439
	[ POWER6_PME_PM_DPU_HELD_COUNT ] = {
		.pme_name = "PM_DPU_HELD_COUNT",
		.pme_short_desc = "Periods DISP unit held",
		.pme_long_desc = "Dispatch unit held",
		.pme_event_ids = { -1, 355, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0002000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_SET_MPRED 440
	[ POWER6_PME_PM_LSU1_REJECT_SET_MPRED ] = {
		.pme_name = "PM_LSU1_REJECT_SET_MPRED",
		.pme_short_desc = "LSU1 reject due to mispredicted set",
		.pme_long_desc = "LSU1 reject due to mispredicted set",
		.pme_event_ids = { 229, 238, 224, 229, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000001ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_2 441
	[ POWER6_PME_PM_FPU_ISSUE_2 ] = {
		.pme_name = "PM_FPU_ISSUE_2",
		.pme_short_desc = "FPU issue 2 per cycle",
		.pme_long_desc = "FPU issue 2 per cycle",
		.pme_event_ids = { 109, 117, 105, 114, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_L2_CORR 442
	[ POWER6_PME_PM_LSU1_REJECT_L2_CORR ] = {
		.pme_name = "PM_LSU1_REJECT_L2_CORR",
		.pme_short_desc = "LSU1 reject due to L2 correctable error",
		.pme_long_desc = "LSU1 reject due to L2 correctable error",
		.pme_event_ids = { 225, 234, 220, 225, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000008ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_DMEM 443
	[ POWER6_PME_PM_MRK_PTEG_FROM_DMEM ] = {
		.pme_name = "PM_MRK_PTEG_FROM_DMEM",
		.pme_short_desc = "Marked PTEG loaded from distant memory",
		.pme_long_desc = "Marked PTEG loaded from distant memory",
		.pme_event_ids = { -1, 289, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM1_DP_RQ_LOC_GLOB 444
	[ POWER6_PME_PM_MEM1_DP_RQ_LOC_GLOB ] = {
		.pme_name = "PM_MEM1_DP_RQ_LOC_GLOB",
		.pme_short_desc = "Memory read queue marking cache line double pump state from local to global side 1",
		.pme_long_desc = "Memory read queue marking cache line double pump state from local to global side 1",
		.pme_event_ids = { 255, 266, 249, 254, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_minus1or2_CYC 445
	[ POWER6_PME_PM_THRD_PRIO_DIFF_minus1or2_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_minus1or2_CYC",
		.pme_short_desc = "Cycles thread priority difference is -1 or -2",
		.pme_long_desc = "Cycles thread priority difference is -1 or -2",
		.pme_event_ids = { -1, 325, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_0_CYC 446
	[ POWER6_PME_PM_THRD_PRIO_0_CYC ] = {
		.pme_name = "PM_THRD_PRIO_0_CYC",
		.pme_short_desc = "Cycles thread running at priority level 0",
		.pme_long_desc = "Cycles thread running at priority level 0",
		.pme_event_ids = { 316, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000004000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FXU0_BUSY_FXU1_IDLE 447
	[ POWER6_PME_PM_FXU0_BUSY_FXU1_IDLE ] = {
		.pme_name = "PM_FXU0_BUSY_FXU1_IDLE",
		.pme_short_desc = "FXU0 busy FXU1 idle",
		.pme_long_desc = "FXU0 is busy while FXU1 was idle",
		.pme_event_ids = { -1, -1, 116, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000040000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_DERAT_MPRED 448
	[ POWER6_PME_PM_LSU1_REJECT_DERAT_MPRED ] = {
		.pme_name = "PM_LSU1_REJECT_DERAT_MPRED",
		.pme_short_desc = "LSU1 reject due to mispredicted DERAT",
		.pme_long_desc = "LSU1 reject due to mispredicted DERAT",
		.pme_event_ids = { 223, 232, 218, 223, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000080ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX1_LD_WRBACK 449
	[ POWER6_PME_PM_MRK_VMX1_LD_WRBACK ] = {
		.pme_name = "PM_MRK_VMX1_LD_WRBACK",
		.pme_short_desc = "Marked VMX1 load writeback valid",
		.pme_long_desc = "Marked VMX1 load writeback valid",
		.pme_event_ids = { 284, 296, 279, 281, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000200000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_RL2L3_SHR_CYC 450
	[ POWER6_PME_PM_DATA_FROM_RL2L3_SHR_CYC ] = {
		.pme_name = "PM_DATA_FROM_RL2L3_SHR_CYC",
		.pme_short_desc = "Load latency from remote L2 or L3 shared",
		.pme_long_desc = "Load latency from remote L2 or L3 shared",
		.pme_event_ids = { -1, 24, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000001000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IERAT_MISS_16M 451
	[ POWER6_PME_PM_IERAT_MISS_16M ] = {
		.pme_name = "PM_IERAT_MISS_16M",
		.pme_short_desc = "IERAT misses for 16M page",
		.pme_long_desc = "IERAT misses for 16M page",
		.pme_event_ids = { -1, 362, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_MEM_DP 452
	[ POWER6_PME_PM_MRK_DATA_FROM_MEM_DP ] = {
		.pme_name = "PM_MRK_DATA_FROM_MEM_DP",
		.pme_short_desc = "Marked data loaded from double pump memory",
		.pme_long_desc = "Marked data loaded from double pump memory",
		.pme_event_ids = { 262, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000004000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LARX_L1HIT 453
	[ POWER6_PME_PM_LARX_L1HIT ] = {
		.pme_name = "PM_LARX_L1HIT",
		.pme_short_desc = "larx hits in L1",
		.pme_long_desc = "larx hits in L1",
		.pme_event_ids = { 198, 208, 196, 201, -1, -1 },
		.pme_group_vector = {
			0x0010000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2_ST_MISS_DATA 454
	[ POWER6_PME_PM_L2_ST_MISS_DATA ] = {
		.pme_name = "PM_L2_ST_MISS_DATA",
		.pme_short_desc = "L2 data store misses",
		.pme_long_desc = "L2 data store misses",
		.pme_event_ids = { 190, -1, -1, 193, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000002000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_ST_FOLDED 455
	[ POWER6_PME_PM_FPU_ST_FOLDED ] = {
		.pme_name = "PM_FPU_ST_FOLDED",
		.pme_short_desc = "FPU folded store",
		.pme_long_desc = "FPU folded store",
		.pme_event_ids = { -1, -1, 114, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000004ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L35_SHR 456
	[ POWER6_PME_PM_MRK_DATA_FROM_L35_SHR ] = {
		.pme_name = "PM_MRK_DATA_FROM_L35_SHR",
		.pme_short_desc = "Marked data loaded from L3.5 shared",
		.pme_long_desc = "Marked data loaded from L3.5 shared",
		.pme_event_ids = { -1, 271, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000002000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_MULT_GPR 457
	[ POWER6_PME_PM_DPU_HELD_MULT_GPR ] = {
		.pme_name = "PM_DPU_HELD_MULT_GPR",
		.pme_short_desc = "DISP unit held due to multiple/divide multiply/divide GPR dependencies",
		.pme_long_desc = "DISP unit held due to multiple/divide multiply/divide GPR dependencies",
		.pme_event_ids = { 46, 54, 45, 53, -1, -1 },
		.pme_group_vector = {
			0x0000110000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_1FLOP 458
	[ POWER6_PME_PM_FPU0_1FLOP ] = {
		.pme_name = "PM_FPU0_1FLOP",
		.pme_short_desc = "FPU0 executed add",
		.pme_long_desc = " mult",
		.pme_event_ids = { 71, 80, 69, 77, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IERAT_MISS_16G 459
	[ POWER6_PME_PM_IERAT_MISS_16G ] = {
		.pme_name = "PM_IERAT_MISS_16G",
		.pme_short_desc = "IERAT misses for 16G page",
		.pme_long_desc = "IERAT misses for 16G page",
		.pme_event_ids = { 352, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000100ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_PREF_WRITE 460
	[ POWER6_PME_PM_IC_PREF_WRITE ] = {
		.pme_name = "PM_IC_PREF_WRITE",
		.pme_short_desc = "Instruction prefetch written into I cache",
		.pme_long_desc = "Instruction prefetch written into I cache",
		.pme_event_ids = { 134, 143, 133, 140, -1, -1 },
		.pme_group_vector = {
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_PRIO_DIFF_minus5or6_CYC 461
	[ POWER6_PME_PM_THRD_PRIO_DIFF_minus5or6_CYC ] = {
		.pme_name = "PM_THRD_PRIO_DIFF_minus5or6_CYC",
		.pme_short_desc = "Cycles thread priority difference is -5 or -6",
		.pme_long_desc = "Cycles thread priority difference is -5 or -6",
		.pme_event_ids = { -1, -1, -1, 310, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000020000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FIN 462
	[ POWER6_PME_PM_FPU0_FIN ] = {
		.pme_name = "PM_FPU0_FIN",
		.pme_short_desc = "FPU0 produced a result",
		.pme_long_desc = "fp0 finished, produced a result This only indicates finish, not completion. ",
		.pme_event_ids = { 75, 84, 73, 81, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0200000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L2_CYC 463
	[ POWER6_PME_PM_DATA_FROM_L2_CYC ] = {
		.pme_name = "PM_DATA_FROM_L2_CYC",
		.pme_short_desc = "Load latency from L2",
		.pme_long_desc = "Load latency from L2",
		.pme_event_ids = { -1, 18, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000040000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_REF_16G 464
	[ POWER6_PME_PM_DERAT_REF_16G ] = {
		.pme_name = "PM_DERAT_REF_16G",
		.pme_short_desc = "DERAT reference for 16G page",
		.pme_long_desc = "DERAT reference for 16G page",
		.pme_event_ids = { -1, -1, -1, 342, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000080ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_PRED 465
	[ POWER6_PME_PM_BR_PRED ] = {
		.pme_name = "PM_BR_PRED",
		.pme_short_desc = "A conditional branch was predicted",
		.pme_long_desc = "A conditional branch was predicted",
		.pme_event_ids = { 8, 6, 6, 8, -1, -1 },
		.pme_group_vector = {
			0x0000000000000054ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX1_LD_ISSUED 466
	[ POWER6_PME_PM_VMX1_LD_ISSUED ] = {
		.pme_name = "PM_VMX1_LD_ISSUED",
		.pme_short_desc = "VMX1 load issued",
		.pme_long_desc = "VMX1 load issued",
		.pme_event_ids = { 326, 333, 320, 318, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000600000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_CASTOUT_MOD 467
	[ POWER6_PME_PM_L2SB_CASTOUT_MOD ] = {
		.pme_name = "PM_L2SB_CASTOUT_MOD",
		.pme_short_desc = "L2 slice B castouts - Modified",
		.pme_long_desc = "L2 slice B castouts - Modified",
		.pme_event_ids = { 171, 180, 171, 177, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000200000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_DMEM 468
	[ POWER6_PME_PM_INST_FROM_DMEM ] = {
		.pme_name = "PM_INST_FROM_DMEM",
		.pme_short_desc = "Instruction fetched from distant memory",
		.pme_long_desc = "Instruction fetched from distant memory",
		.pme_event_ids = { -1, 152, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L35_SHR_CYC 469
	[ POWER6_PME_PM_DATA_FROM_L35_SHR_CYC ] = {
		.pme_name = "PM_DATA_FROM_L35_SHR_CYC",
		.pme_short_desc = "Load latency from L3.5 shared",
		.pme_long_desc = "Load latency from L3.5 shared",
		.pme_event_ids = { -1, 20, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000200000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_NCLD 470
	[ POWER6_PME_PM_LSU0_NCLD ] = {
		.pme_name = "PM_LSU0_NCLD",
		.pme_short_desc = "LSU0 non-cacheable loads",
		.pme_long_desc = "LSU0 non-cacheable loads",
		.pme_event_ids = { 206, 215, 201, 206, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_RETRY_NODE_PUMP 471
	[ POWER6_PME_PM_FAB_RETRY_NODE_PUMP ] = {
		.pme_name = "PM_FAB_RETRY_NODE_PUMP",
		.pme_short_desc = "Retry of a node pump",
		.pme_long_desc = " locally mastered",
		.pme_event_ids = { 64, 74, 63, 70, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX0_INST_ISSUED 472
	[ POWER6_PME_PM_VMX0_INST_ISSUED ] = {
		.pme_name = "PM_VMX0_INST_ISSUED",
		.pme_short_desc = "VMX0 instruction issued",
		.pme_long_desc = "VMX0 instruction issued",
		.pme_event_ids = { 321, 328, 315, 313, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000200000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L25_MOD 473
	[ POWER6_PME_PM_DATA_FROM_L25_MOD ] = {
		.pme_name = "PM_DATA_FROM_L25_MOD",
		.pme_short_desc = "Data loaded from L2.5 modified",
		.pme_long_desc = "DL1 was reloaded with modified (M) data from the L2 of a chip on this MCM due to a demand load",
		.pme_event_ids = { -1, -1, 12, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000020200ULL,
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_ITLB_ISLB 474
	[ POWER6_PME_PM_DPU_HELD_ITLB_ISLB ] = {
		.pme_name = "PM_DPU_HELD_ITLB_ISLB",
		.pme_short_desc = "DISP unit held due to SLB or TLB invalidates ",
		.pme_long_desc = "DISP unit held due to SLB or TLB invalidates ",
		.pme_event_ids = { 42, 50, 41, 49, -1, -1 },
		.pme_group_vector = {
			0x0000008000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_CYC 475
	[ POWER6_PME_PM_LSU_LMQ_SRQ_EMPTY_CYC ] = {
		.pme_name = "PM_LSU_LMQ_SRQ_EMPTY_CYC",
		.pme_short_desc = "Cycles LMQ and SRQ empty",
		.pme_long_desc = "Cycles when both the LMQ and SRQ are empty (LSU is idle)",
		.pme_event_ids = { -1, 248, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0040000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_CONC_RUN_INST 476
	[ POWER6_PME_PM_THRD_CONC_RUN_INST ] = {
		.pme_name = "PM_THRD_CONC_RUN_INST",
		.pme_short_desc = "Concurrent run instructions",
		.pme_long_desc = "Concurrent run instructions",
		.pme_event_ids = { -1, -1, 306, -1, -1, -1 },
		.pme_group_vector = {
			0x0020000000000002ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L2 477
	[ POWER6_PME_PM_MRK_PTEG_FROM_L2 ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L2",
		.pme_short_desc = "Marked PTEG loaded from L2.5 modified",
		.pme_long_desc = "Marked PTEG loaded from L2.5 modified",
		.pme_event_ids = { 277, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000004000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PURR 478
	[ POWER6_PME_PM_PURR ] = {
		.pme_name = "PM_PURR",
		.pme_short_desc = "PURR Event",
		.pme_long_desc = "PURR Event",
		.pme_event_ids = { 301, -1, -1, 293, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000008ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DERAT_MISS_64K 479
	[ POWER6_PME_PM_DERAT_MISS_64K ] = {
		.pme_name = "PM_DERAT_MISS_64K",
		.pme_short_desc = "DERAT misses for 64K page",
		.pme_long_desc = "A data request (load or store) missed the ERAT for 64K page and resulted in an ERAT reload.",
		.pme_event_ids = { -1, 361, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000040ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC2_REWIND 480
	[ POWER6_PME_PM_PMC2_REWIND ] = {
		.pme_name = "PM_PMC2_REWIND",
		.pme_short_desc = "PMC2 rewind event",
		.pme_long_desc = "PMC2 rewind event",
		.pme_event_ids = { -1, -1, 287, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L2 481
	[ POWER6_PME_PM_INST_FROM_L2 ] = {
		.pme_name = "PM_INST_FROM_L2",
		.pme_short_desc = "Instructions fetched from L2",
		.pme_long_desc = "An instruction fetch group was fetched from L2. Fetch Groups can contain up to 8 instructions",
		.pme_event_ids = { 143, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000004400000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_DISP 482
	[ POWER6_PME_PM_INST_DISP ] = {
		.pme_name = "PM_INST_DISP",
		.pme_short_desc = "Instructions dispatched",
		.pme_long_desc = "The ISU sends the number of instructions dispatched.",
		.pme_event_ids = { -1, 149, 139, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000140001ULL,
			0x0000000000001000ULL,
			0x2000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L25_SHR 483
	[ POWER6_PME_PM_DATA_FROM_L25_SHR ] = {
		.pme_name = "PM_DATA_FROM_L25_SHR",
		.pme_short_desc = "Data loaded from L2.5 shared",
		.pme_long_desc = "DL1 was reloaded with shared (T or SL) data from the L2 of a chip on this MCM due to a demand load",
		.pme_event_ids = { -1, -1, -1, 16, -1, -1 },
		.pme_group_vector = {
			0x0000000000000200ULL,
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L1_DCACHE_RELOAD_VALID 484
	[ POWER6_PME_PM_L1_DCACHE_RELOAD_VALID ] = {
		.pme_name = "PM_L1_DCACHE_RELOAD_VALID",
		.pme_short_desc = "L1 reload data source valid",
		.pme_long_desc = "The data source information is valid",
		.pme_event_ids = { -1, -1, 154, 160, -1, -1 },
		.pme_group_vector = {
			0x0000000000040000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_UST 485
	[ POWER6_PME_PM_LSU1_REJECT_UST ] = {
		.pme_name = "PM_LSU1_REJECT_UST",
		.pme_short_desc = "LSU1 unaligned store reject",
		.pme_long_desc = "LSU1 unaligned store reject",
		.pme_event_ids = { 232, 241, 227, 232, -1, -1 },
		.pme_group_vector = {
			0x4000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FAB_ADDR_COLLISION 486
	[ POWER6_PME_PM_FAB_ADDR_COLLISION ] = {
		.pme_name = "PM_FAB_ADDR_COLLISION",
		.pme_short_desc = "local node launch collision with off-node address   ",
		.pme_long_desc = "local node launch collision with off-node address   ",
		.pme_event_ids = { 58, 68, 58, 65, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000020000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_FXU_FIN 487
	[ POWER6_PME_PM_MRK_FXU_FIN ] = {
		.pme_name = "PM_MRK_FXU_FIN",
		.pme_short_desc = "Marked instruction FXU processing finished",
		.pme_long_desc = "The fixed point units (Unit 0 + Unit 1) finished a marked instruction. Instructions that finish may not necessary complete.",
		.pme_event_ids = { -1, 277, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000200000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_UST 488
	[ POWER6_PME_PM_LSU0_REJECT_UST ] = {
		.pme_name = "PM_LSU0_REJECT_UST",
		.pme_short_desc = "LSU0 unaligned store reject",
		.pme_long_desc = "LSU0 unaligned store reject",
		.pme_event_ids = { 219, 228, 214, 219, -1, -1 },
		.pme_group_vector = {
			0x4000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_PMC4_OVERFLOW 489
	[ POWER6_PME_PM_PMC4_OVERFLOW ] = {
		.pme_name = "PM_PMC4_OVERFLOW",
		.pme_short_desc = "PMC4 Overflow",
		.pme_long_desc = "PMC4 Overflow",
		.pme_event_ids = { 292, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L3 490
	[ POWER6_PME_PM_MRK_PTEG_FROM_L3 ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L3",
		.pme_short_desc = "Marked PTEG loaded from L3",
		.pme_long_desc = "Marked PTEG loaded from L3",
		.pme_event_ids = { -1, -1, 273, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000020000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L2MISS 491
	[ POWER6_PME_PM_INST_FROM_L2MISS ] = {
		.pme_name = "PM_INST_FROM_L2MISS",
		.pme_short_desc = "Instructions fetched missed L2",
		.pme_long_desc = "An instruction fetch group was fetched from beyond L2.",
		.pme_event_ids = { -1, -1, -1, 151, -1, -1 },
		.pme_group_vector = {
			0x0000000004400000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_ST_HIT 492
	[ POWER6_PME_PM_L2SB_ST_HIT ] = {
		.pme_name = "PM_L2SB_ST_HIT",
		.pme_short_desc = "L2 slice B store hits",
		.pme_long_desc = "A store request made from the core hit in the L2 directory.  This event is provided on each of the three L2 slices A,B, and C.",
		.pme_event_ids = { 182, 191, 182, 188, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0001000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_WT_IC_MISS_COUNT 493
	[ POWER6_PME_PM_DPU_WT_IC_MISS_COUNT ] = {
		.pme_name = "PM_DPU_WT_IC_MISS_COUNT",
		.pme_short_desc = "Periods DISP unit is stalled due to I cache miss",
		.pme_long_desc = "Periods DISP unit is stalled due to I cache miss",
		.pme_event_ids = { -1, 357, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0080040000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_DL2L3_SHR 494
	[ POWER6_PME_PM_MRK_DATA_FROM_DL2L3_SHR ] = {
		.pme_name = "PM_MRK_DATA_FROM_DL2L3_SHR",
		.pme_short_desc = "Marked data loaded from distant L2 or L3 shared",
		.pme_long_desc = "Marked data loaded from distant L2 or L3 shared",
		.pme_event_ids = { -1, -1, 252, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000400ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L35_MOD 495
	[ POWER6_PME_PM_MRK_PTEG_FROM_L35_MOD ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L35_MOD",
		.pme_short_desc = "Marked PTEG loaded from L3.5 modified",
		.pme_long_desc = "Marked PTEG loaded from L3.5 modified",
		.pme_event_ids = { 278, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000010000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_FPSCR 496
	[ POWER6_PME_PM_FPU1_FPSCR ] = {
		.pme_name = "PM_FPU1_FPSCR",
		.pme_short_desc = "FPU1 executed FPSCR instruction",
		.pme_long_desc = "FPU1 executed FPSCR instruction",
		.pme_event_ids = { 93, 102, 91, 99, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_UST 497
	[ POWER6_PME_PM_LSU_REJECT_UST ] = {
		.pme_name = "PM_LSU_REJECT_UST",
		.pme_short_desc = "Unaligned store reject",
		.pme_long_desc = "Unaligned store reject",
		.pme_event_ids = { -1, 256, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x4000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_DERAT_MISS 498
	[ POWER6_PME_PM_LSU0_DERAT_MISS ] = {
		.pme_name = "PM_LSU0_DERAT_MISS",
		.pme_short_desc = "LSU0 DERAT misses",
		.pme_long_desc = "A data request (load or store) from LSU Unit 0 missed the ERAT and resulted in an ERAT reload. Multiple instructions may miss the ERAT entry for the same 4K page, but only one reload will occur.",
		.pme_event_ids = { 204, 213, 199, 204, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x00000000000000a0ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_MEM_DP 499
	[ POWER6_PME_PM_MRK_PTEG_FROM_MEM_DP ] = {
		.pme_name = "PM_MRK_PTEG_FROM_MEM_DP",
		.pme_short_desc = "Marked PTEG loaded from double pump memory",
		.pme_long_desc = "Marked PTEG loaded from double pump memory",
		.pme_event_ids = { 279, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000020000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L2 500
	[ POWER6_PME_PM_MRK_DATA_FROM_L2 ] = {
		.pme_name = "PM_MRK_DATA_FROM_L2",
		.pme_short_desc = "Marked data loaded from L2",
		.pme_long_desc = "DL1 was reloaded from the local L2 due to a marked demand load",
		.pme_event_ids = { 259, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000800ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU0_FSQRT_FDIV 501
	[ POWER6_PME_PM_FPU0_FSQRT_FDIV ] = {
		.pme_name = "PM_FPU0_FSQRT_FDIV",
		.pme_short_desc = "FPU0 executed FSQRT or FDIV instruction",
		.pme_long_desc = "FPU0 executed FSQRT or FDIV instruction",
		.pme_event_ids = { 80, 89, 78, 86, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0080000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_FXU_SOPS 502
	[ POWER6_PME_PM_DPU_HELD_FXU_SOPS ] = {
		.pme_name = "PM_DPU_HELD_FXU_SOPS",
		.pme_short_desc = "DISP unit held due to FXU slow ops (mtmsr",
		.pme_long_desc = " scv",
		.pme_event_ids = { 38, 46, 37, 45, -1, -1 },
		.pme_group_vector = {
			0x0000040000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_FPU0_FIN 503
	[ POWER6_PME_PM_MRK_FPU0_FIN ] = {
		.pme_name = "PM_MRK_FPU0_FIN",
		.pme_short_desc = "Marked instruction FPU0 processing finished",
		.pme_long_desc = "Marked instruction FPU0 processing finished",
		.pme_event_ids = { 265, 274, 259, 260, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000800100000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L2SB_LD_MISS_DATA 504
	[ POWER6_PME_PM_L2SB_LD_MISS_DATA ] = {
		.pme_name = "PM_L2SB_LD_MISS_DATA",
		.pme_short_desc = "L2 slice B data load misses",
		.pme_long_desc = "L2 slice B data load misses",
		.pme_event_ids = { 176, 185, 176, 182, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000020000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_SRQ_EMPTY_CYC 505
	[ POWER6_PME_PM_LSU_SRQ_EMPTY_CYC ] = {
		.pme_name = "PM_LSU_SRQ_EMPTY_CYC",
		.pme_short_desc = "Cycles SRQ empty",
		.pme_long_desc = "The Store Request Queue is empty",
		.pme_event_ids = { -1, -1, -1, 244, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000001ULL,
			0x0010000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_1PLUS_PPC_DISP 506
	[ POWER6_PME_PM_1PLUS_PPC_DISP ] = {
		.pme_name = "PM_1PLUS_PPC_DISP",
		.pme_short_desc = "Cycles at least one instruction dispatched",
		.pme_long_desc = "Cycles at least one instruction dispatched",
		.pme_event_ids = { 2, -1, -1, 1, -1, -1 },
		.pme_group_vector = {
			0x0000000000100000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_VMX_ST_ISSUED 507
	[ POWER6_PME_PM_VMX_ST_ISSUED ] = {
		.pme_name = "PM_VMX_ST_ISSUED",
		.pme_short_desc = "VMX store issued",
		.pme_long_desc = "VMX store issued",
		.pme_event_ids = { 336, 343, 330, 328, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000001800000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L2MISS 508
	[ POWER6_PME_PM_DATA_FROM_L2MISS ] = {
		.pme_name = "PM_DATA_FROM_L2MISS",
		.pme_short_desc = "Data loaded missed L2",
		.pme_long_desc = "DL1 was reloaded from beyond L2.",
		.pme_event_ids = { -1, 17, 13, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000080ULL,
			0x0000100000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_ULD 509
	[ POWER6_PME_PM_LSU0_REJECT_ULD ] = {
		.pme_name = "PM_LSU0_REJECT_ULD",
		.pme_short_desc = "LSU0 unaligned load reject",
		.pme_long_desc = "LSU0 unaligned load reject",
		.pme_event_ids = { 218, 227, 213, 218, -1, -1 },
		.pme_group_vector = {
			0x8000000000000000ULL,
			0x0000000000000002ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_SUSPENDED 510
	[ POWER6_PME_PM_SUSPENDED ] = {
		.pme_name = "PM_SUSPENDED",
		.pme_short_desc = "Suspended",
		.pme_long_desc = "Suspended",
		.pme_event_ids = { 311, 318, 302, 302, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000010ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DFU_ADD_SHIFTED_BOTH 511
	[ POWER6_PME_PM_DFU_ADD_SHIFTED_BOTH ] = {
		.pme_name = "PM_DFU_ADD_SHIFTED_BOTH",
		.pme_short_desc = "DFU add type with both operands shifted",
		.pme_long_desc = "DFU add type with both operands shifted",
		.pme_event_ids = { 24, 31, 23, 31, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000002000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU_REJECT_NO_SCRATCH 512
	[ POWER6_PME_PM_LSU_REJECT_NO_SCRATCH ] = {
		.pme_name = "PM_LSU_REJECT_NO_SCRATCH",
		.pme_short_desc = "LSU reject due to scratch register not available",
		.pme_long_desc = "LSU reject due to scratch register not available",
		.pme_event_ids = { -1, 251, 237, -1, -1, -1 },
		.pme_group_vector = {
			0x2000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_STCX_FAIL 513
	[ POWER6_PME_PM_STCX_FAIL ] = {
		.pme_name = "PM_STCX_FAIL",
		.pme_short_desc = "STCX failed",
		.pme_long_desc = "A stcx (stwcx or stdcx) failed",
		.pme_event_ids = { 306, 312, 298, 297, -1, -1 },
		.pme_group_vector = {
			0x0018000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU1_DENORM 514
	[ POWER6_PME_PM_FPU1_DENORM ] = {
		.pme_name = "PM_FPU1_DENORM",
		.pme_short_desc = "FPU1 received denormalized data",
		.pme_long_desc = "This signal is active for one cycle when one of the operands is denormalized.",
		.pme_event_ids = { 87, 96, 85, 93, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x1000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GCT_NOSLOT_COUNT 515
	[ POWER6_PME_PM_GCT_NOSLOT_COUNT ] = {
		.pme_name = "PM_GCT_NOSLOT_COUNT",
		.pme_short_desc = "Periods no GCT slot allocated",
		.pme_long_desc = "Periods this thread does not have any slots allocated in the GCT.",
		.pme_event_ids = { 349, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0008010000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_DL2L3_SHR_CYC 516
	[ POWER6_PME_PM_DATA_FROM_DL2L3_SHR_CYC ] = {
		.pme_name = "PM_DATA_FROM_DL2L3_SHR_CYC",
		.pme_short_desc = "Load latency from distant L2 or L3 shared",
		.pme_long_desc = "Load latency from distant L2 or L3 shared",
		.pme_event_ids = { -1, 12, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000008000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L21 517
	[ POWER6_PME_PM_DATA_FROM_L21 ] = {
		.pme_name = "PM_DATA_FROM_L21",
		.pme_short_desc = "Data loaded from private L2 other core",
		.pme_long_desc = "Data loaded from private L2 other core",
		.pme_event_ids = { -1, 15, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000080080ULL,
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FPU_1FLOP 518
	[ POWER6_PME_PM_FPU_1FLOP ] = {
		.pme_name = "PM_FPU_1FLOP",
		.pme_short_desc = "FPU executed one flop instruction ",
		.pme_long_desc = "This event counts the number of one flop instructions. These could be fadd*, fmul*, fsub*, fneg+, fabs+, fnabs+, fres+, frsqrte+, fcmp**, or fsel where XYZ* means XYZ, XYZs, XYZ., XYZs., XYZ+ means XYZ, XYZ., and XYZ** means XYZu, XYZo.",
		.pme_event_ids = { 101, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x8000000000000000ULL,
			0x0400000000000000ULL,
			0x0000000000000002ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT 519
	[ POWER6_PME_PM_LSU1_REJECT ] = {
		.pme_name = "PM_LSU1_REJECT",
		.pme_short_desc = "LSU1 reject",
		.pme_long_desc = "LSU1 reject",
		.pme_event_ids = { 222, 231, 217, 222, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000044ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IC_REQ 520
	[ POWER6_PME_PM_IC_REQ ] = {
		.pme_name = "PM_IC_REQ",
		.pme_short_desc = "I cache demand of prefetch request",
		.pme_long_desc = "I cache demand of prefetch request",
		.pme_event_ids = { 136, 145, 135, 142, -1, -1 },
		.pme_group_vector = {
			0x0004000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DFU_FIN 521
	[ POWER6_PME_PM_MRK_DFU_FIN ] = {
		.pme_name = "PM_MRK_DFU_FIN",
		.pme_short_desc = "DFU marked instruction finish",
		.pme_long_desc = "DFU marked instruction finish",
		.pme_event_ids = { -1, -1, 257, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000200000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_NOT_LLA_CYC 522
	[ POWER6_PME_PM_NOT_LLA_CYC ] = {
		.pme_name = "PM_NOT_LLA_CYC",
		.pme_short_desc = "Load Look Ahead not Active",
		.pme_long_desc = "Load Look Ahead not Active",
		.pme_event_ids = { 346, 353, 338, 338, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_INST_FROM_L1 523
	[ POWER6_PME_PM_INST_FROM_L1 ] = {
		.pme_name = "PM_INST_FROM_L1",
		.pme_short_desc = "Instruction fetched from L1",
		.pme_long_desc = "An instruction fetch group was fetched from L1. Fetch Groups can contain up to 8 instructions",
		.pme_event_ids = { 142, 153, 143, 149, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX_COMPLEX_ISSUED 524
	[ POWER6_PME_PM_MRK_VMX_COMPLEX_ISSUED ] = {
		.pme_name = "PM_MRK_VMX_COMPLEX_ISSUED",
		.pme_short_desc = "Marked VMX instruction issued to complex",
		.pme_long_desc = "Marked VMX instruction issued to complex",
		.pme_event_ids = { 285, 297, 280, 282, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BRU_FIN 525
	[ POWER6_PME_PM_BRU_FIN ] = {
		.pme_name = "PM_BRU_FIN",
		.pme_short_desc = "BRU produced a result",
		.pme_long_desc = "BRU produced a result",
		.pme_event_ids = { 3, 1, 1, 2, -1, -1 },
		.pme_group_vector = {
			0x0000000000000040ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_REJECT_EXTERN 526
	[ POWER6_PME_PM_LSU1_REJECT_EXTERN ] = {
		.pme_name = "PM_LSU1_REJECT_EXTERN",
		.pme_short_desc = "LSU1 external reject request ",
		.pme_long_desc = "LSU1 external reject request ",
		.pme_event_ids = { 224, 233, 219, 224, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000008ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_L21_CYC 527
	[ POWER6_PME_PM_DATA_FROM_L21_CYC ] = {
		.pme_name = "PM_DATA_FROM_L21_CYC",
		.pme_short_desc = "Load latency from private L2 other core",
		.pme_long_desc = "Load latency from private L2 other core",
		.pme_event_ids = { -1, -1, -1, 15, -1, -1 },
		.pme_group_vector = {
			0x0000000000080000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GXI_CYC_BUSY 528
	[ POWER6_PME_PM_GXI_CYC_BUSY ] = {
		.pme_name = "PM_GXI_CYC_BUSY",
		.pme_short_desc = "Inbound GX bus utilizations (# of cycles in use)",
		.pme_long_desc = "Inbound GX bus utilizations (# of cycles in use)",
		.pme_event_ids = { 123, 130, 121, 129, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000e00000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LD_MISS_L1 529
	[ POWER6_PME_PM_MRK_LD_MISS_L1 ] = {
		.pme_name = "PM_MRK_LD_MISS_L1",
		.pme_short_desc = "Marked L1 D cache load misses",
		.pme_long_desc = "Marked L1 D cache load misses",
		.pme_event_ids = { -1, 280, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000200ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_L1_WRITE_CYC 530
	[ POWER6_PME_PM_L1_WRITE_CYC ] = {
		.pme_name = "PM_L1_WRITE_CYC",
		.pme_short_desc = "Cycles writing to instruction L1",
		.pme_long_desc = "This signal is asserted each cycle a cache write is active.",
		.pme_event_ids = { 156, 165, 156, 162, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LLA_CYC 531
	[ POWER6_PME_PM_LLA_CYC ] = {
		.pme_name = "PM_LLA_CYC",
		.pme_short_desc = "Load Look Ahead Active",
		.pme_long_desc = "Load Look Ahead Active",
		.pme_event_ids = { 345, 352, 337, 337, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000080000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_L2MISS 532
	[ POWER6_PME_PM_MRK_DATA_FROM_L2MISS ] = {
		.pme_name = "PM_MRK_DATA_FROM_L2MISS",
		.pme_short_desc = "Marked data loaded missed L2",
		.pme_long_desc = "DL1 was reloaded from beyond L2 due to a marked demand load.",
		.pme_event_ids = { 260, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000001000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GCT_FULL_COUNT 533
	[ POWER6_PME_PM_GCT_FULL_COUNT ] = {
		.pme_name = "PM_GCT_FULL_COUNT",
		.pme_short_desc = "Periods GCT full",
		.pme_long_desc = "The ISU sends a signal indicating the gct is full.",
		.pme_event_ids = { 339, 346, 333, 331, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000410000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MEM_DP_RQ_LOC_GLOB 534
	[ POWER6_PME_PM_MEM_DP_RQ_LOC_GLOB ] = {
		.pme_name = "PM_MEM_DP_RQ_LOC_GLOB",
		.pme_short_desc = "Memory read queue marking cache line double pump state from local to global",
		.pme_long_desc = "Memory read queue marking cache line double pump state from local to global",
		.pme_event_ids = { -1, 268, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000040000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DATA_FROM_RL2L3_SHR 535
	[ POWER6_PME_PM_DATA_FROM_RL2L3_SHR ] = {
		.pme_name = "PM_DATA_FROM_RL2L3_SHR",
		.pme_short_desc = "Data loaded from remote L2 or L3 shared",
		.pme_long_desc = "Data loaded from remote L2 or L3 shared",
		.pme_event_ids = { -1, 23, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000400ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU_REJECT_UST 536
	[ POWER6_PME_PM_MRK_LSU_REJECT_UST ] = {
		.pme_name = "PM_MRK_LSU_REJECT_UST",
		.pme_short_desc = "Marked unaligned store reject",
		.pme_long_desc = "Marked unaligned store reject",
		.pme_event_ids = { -1, 288, 270, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000010000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_VMX_PERMUTE_ISSUED 537
	[ POWER6_PME_PM_MRK_VMX_PERMUTE_ISSUED ] = {
		.pme_name = "PM_MRK_VMX_PERMUTE_ISSUED",
		.pme_short_desc = "Marked VMX instruction issued to permute",
		.pme_long_desc = "Marked VMX instruction issued to permute",
		.pme_event_ids = { 287, 299, 282, 284, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000100000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_PTEG_FROM_L21 538
	[ POWER6_PME_PM_MRK_PTEG_FROM_L21 ] = {
		.pme_name = "PM_MRK_PTEG_FROM_L21",
		.pme_short_desc = "Marked PTEG loaded from private L2 other core",
		.pme_long_desc = "Marked PTEG loaded from private L2 other core",
		.pme_event_ids = { -1, 290, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000008000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_THRD_GRP_CMPL_BOTH_CYC 539
	[ POWER6_PME_PM_THRD_GRP_CMPL_BOTH_CYC ] = {
		.pme_name = "PM_THRD_GRP_CMPL_BOTH_CYC",
		.pme_short_desc = "Cycles group completed by both threads",
		.pme_long_desc = "Cycles group completed by both threads",
		.pme_event_ids = { -1, 320, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0020000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_BR_MPRED 540
	[ POWER6_PME_PM_BR_MPRED ] = {
		.pme_name = "PM_BR_MPRED",
		.pme_short_desc = "Branches incorrectly predicted",
		.pme_long_desc = "Branches incorrectly predicted",
		.pme_event_ids = { -1, -1, -1, 3, -1, -1 },
		.pme_group_vector = {
			0x0000000000000040ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LD_REQ_L2 541
	[ POWER6_PME_PM_LD_REQ_L2 ] = {
		.pme_name = "PM_LD_REQ_L2",
		.pme_short_desc = "L2 load requests ",
		.pme_long_desc = "L2 load requests ",
		.pme_event_ids = { 203, -1, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000010000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_FLUSH_ASYNC 542
	[ POWER6_PME_PM_FLUSH_ASYNC ] = {
		.pme_name = "PM_FLUSH_ASYNC",
		.pme_short_desc = "Flush caused by asynchronous exception",
		.pme_long_desc = "Flush caused by asynchronous exception",
		.pme_event_ids = { 68, 77, 66, 74, -1, -1 },
		.pme_group_vector = {
			0x0002000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_HV_CYC 543
	[ POWER6_PME_PM_HV_CYC ] = {
		.pme_name = "PM_HV_CYC",
		.pme_short_desc = "Hypervisor Cycles",
		.pme_long_desc = "Cycles when the processor is executing in Hypervisor (MSR[HV] = 1 and MSR[PR]=0)",
		.pme_event_ids = { -1, 137, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0040000000000000ULL,
			0x0000000000000000ULL,
			0x0001000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU1_DERAT_MISS 544
	[ POWER6_PME_PM_LSU1_DERAT_MISS ] = {
		.pme_name = "PM_LSU1_DERAT_MISS",
		.pme_short_desc = "LSU1 DERAT misses",
		.pme_long_desc = "A data request (load or store) from LSU Unit 1 missed the ERAT and resulted in an ERAT reload. Multiple instructions may miss the ERAT entry for the same 4K page, but only one reload will occur.",
		.pme_event_ids = { 220, 229, 215, 220, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x00000000000000a0ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_DPU_HELD_SMT 545
	[ POWER6_PME_PM_DPU_HELD_SMT ] = {
		.pme_name = "PM_DPU_HELD_SMT",
		.pme_short_desc = "DISP unit held due to SMT conflicts ",
		.pme_long_desc = "DISP unit held due to SMT conflicts ",
		.pme_event_ids = { 49, 58, 48, 56, -1, -1 },
		.pme_group_vector = {
			0x0000001000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_LSU_FIN 546
	[ POWER6_PME_PM_MRK_LSU_FIN ] = {
		.pme_name = "PM_MRK_LSU_FIN",
		.pme_short_desc = "Marked instruction LSU processing finished",
		.pme_long_desc = "One of the Load/Store Units finished a marked instruction. Instructions that finish may not necessary complete",
		.pme_event_ids = { -1, -1, -1, 272, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000000001000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DATA_FROM_RL2L3_SHR 547
	[ POWER6_PME_PM_MRK_DATA_FROM_RL2L3_SHR ] = {
		.pme_name = "PM_MRK_DATA_FROM_RL2L3_SHR",
		.pme_short_desc = "Marked data loaded from remote L2 or L3 shared",
		.pme_long_desc = "Marked data loaded from remote L2 or L3 shared",
		.pme_event_ids = { -1, 272, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x000000000000c000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_LSU0_REJECT_STQ_FULL 548
	[ POWER6_PME_PM_LSU0_REJECT_STQ_FULL ] = {
		.pme_name = "PM_LSU0_REJECT_STQ_FULL",
		.pme_short_desc = "LSU0 reject due to store queue full",
		.pme_long_desc = "LSU0 reject due to store queue full",
		.pme_event_ids = { 217, 226, 212, 217, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000040ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_MRK_DERAT_REF_4K 549
	[ POWER6_PME_PM_MRK_DERAT_REF_4K ] = {
		.pme_name = "PM_MRK_DERAT_REF_4K",
		.pme_short_desc = "Marked DERAT reference for 4K page",
		.pme_long_desc = "Marked DERAT reference for 4K page",
		.pme_event_ids = { -1, 363, -1, -1, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000000000ULL,
			0x0000001000000000ULL,
			0x0000000000000010ULL }
	},
#define POWER6_PME_PM_FPU_ISSUE_STALL_FPR 550
	[ POWER6_PME_PM_FPU_ISSUE_STALL_FPR ] = {
		.pme_name = "PM_FPU_ISSUE_STALL_FPR",
		.pme_short_desc = "FPU issue stalled due to FPR dependencies",
		.pme_long_desc = "FPU issue stalled due to FPR dependencies",
		.pme_event_ids = { 112, 120, 108, 117, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0040000000000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_IFU_FIN 551
	[ POWER6_PME_PM_IFU_FIN ] = {
		.pme_name = "PM_IFU_FIN",
		.pme_short_desc = "IFU finished an instruction",
		.pme_long_desc = "IFU finished an instruction",
		.pme_event_ids = { 138, 147, 137, 144, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000000080000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	},
#define POWER6_PME_PM_GXO_CYC_BUSY 552
	[ POWER6_PME_PM_GXO_CYC_BUSY ] = {
		.pme_name = "PM_GXO_CYC_BUSY",
		.pme_short_desc = "Outbound GX bus utilizations (# of cycles in use)",
		.pme_long_desc = "Outbound GX bus utilizations (# of cycles in use)",
		.pme_event_ids = { 126, 133, 124, 132, -1, -1 },
		.pme_group_vector = {
			0x0000000000000000ULL,
			0x0000000e00000000ULL,
			0x0000000000000000ULL,
			0x0000000000000000ULL }
	}
};
#define POWER6_PME_EVENT_COUNT 553

static pmg_power6_group_t power6_groups[] = {
	[ 0 ] = {
		.pmg_name = "pm_utilization",
		.pmg_desc = "CPI and utilization data",
		.pmg_event_ids = { 302, 148, 139, 12, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000000a02121eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 1 ] = {
		.pmg_name = "pm_utilization_capacity",
		.pmg_desc = "CPU utilization and capacity",
		.pmg_event_ids = { 315, 11, 306, 347, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000fa1ef4f4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 2 ] = {
		.pmg_name = "pm_branch",
		.pmg_desc = "Branch operations",
		.pmg_event_ids = { 10, 4, 6, 5, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x04000000a2a8808aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 3 ] = {
		.pmg_name = "pm_branch2",
		.pmg_desc = "Branch operations",
		.pmg_event_ids = { 9, 9, 2, 7, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x04000000a4a68e8cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 4 ] = {
		.pmg_name = "pm_branch3",
		.pmg_desc = "Branch operations",
		.pmg_event_ids = { 8, 8, 7, 11, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x04000000a0a28486ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 5 ] = {
		.pmg_name = "pm_branch4",
		.pmg_desc = "Branch operations",
		.pmg_event_ids = { 6, 3, 5, 4, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x04000000a8aa8c8eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 6 ] = {
		.pmg_name = "pm_branch5",
		.pmg_desc = "Branch operations",
		.pmg_event_ids = { 8, 10, 1, 3, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x04040000a052c652ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 7 ] = {
		.pmg_name = "pm_dsource",
		.pmg_desc = "Data source",
		.pmg_event_ids = { 13, 15, 13, 19, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000058585656ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 8 ] = {
		.pmg_name = "pm_dsource2",
		.pmg_desc = "Data sources",
		.pmg_event_ids = { 14, 19, 14, 19, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005a5a5856ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 9 ] = {
		.pmg_name = "pm_dsource3",
		.pmg_desc = "Data sources",
		.pmg_event_ids = { 14, 19, 12, 16, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005a5a5a5aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 10 ] = {
		.pmg_name = "pm_dsource4",
		.pmg_desc = "Data sources",
		.pmg_event_ids = { 16, 23, 11, 13, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005c5c5c5cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 11 ] = {
		.pmg_name = "pm_dsource5",
		.pmg_desc = "Data sources",
		.pmg_event_ids = { 15, 13, 16, 20, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005e5e5e5eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 12 ] = {
		.pmg_name = "pm_dlatencies",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 200, 24, 10, 17, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000000c281e24ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 13 ] = {
		.pmg_name = "pm_dlatencies2",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 139, 22, 10, 14, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000022c1e2aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 14 ] = {
		.pmg_name = "pm_dlatencies3",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 139, 14, 16, 23, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000022e5e2cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 15 ] = {
		.pmg_name = "pm_dlatencies4",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 14, 12, 11, 18, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005a2a5c26ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 16 ] = {
		.pmg_name = "pm_dlatencies5",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 16, 21, 14, 22, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005c225828ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 17 ] = {
		.pmg_name = "pm_dlatencies6",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 15, 16, 12, 21, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005e245a2eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 18 ] = {
		.pmg_name = "pm_dlatencies7",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 13, 18, 139, 160, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005820120eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 19 ] = {
		.pmg_name = "pm_dlatencies8",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 67, 15, 10, 15, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000010581e20ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 20 ] = {
		.pmg_name = "pm_dlatencies9",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 2, 22, 139, 20, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000122c125eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 21 ] = {
		.pmg_name = "pm_dlatencies10",
		.pmg_desc = "Data latencies",
		.pmg_event_ids = { 14, 20, 10, 18, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005a261e26ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 22 ] = {
		.pmg_name = "pm_isource",
		.pmg_desc = "Instruction sources",
		.pmg_event_ids = { 143, 154, 144, 151, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0040000040404654ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 23 ] = {
		.pmg_name = "pm_isource2",
		.pmg_desc = "Instruction sources",
		.pmg_event_ids = { 144, 155, 145, 150, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0040000046464046ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 24 ] = {
		.pmg_name = "pm_isource3",
		.pmg_desc = "Instruction sources",
		.pmg_event_ids = { 146, 156, 142, 148, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0040000044444444ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 25 ] = {
		.pmg_name = "pm_isource4",
		.pmg_desc = "Instruction sources",
		.pmg_event_ids = { 145, 152, 147, 152, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0040000042424242ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 26 ] = {
		.pmg_name = "pm_isource5",
		.pmg_desc = "Instruction sources",
		.pmg_event_ids = { 143, 154, 146, 151, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0040000040405454ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 27 ] = {
		.pmg_name = "pm_pteg",
		.pmg_desc = "PTEG sources",
		.pmg_event_ids = { 295, 305, 291, 290, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0001000048484e4eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 28 ] = {
		.pmg_name = "pm_pteg2",
		.pmg_desc = "PTEG sources",
		.pmg_event_ids = { 296, 305, 292, 289, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000100002848484cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 29 ] = {
		.pmg_name = "pm_pteg3",
		.pmg_desc = "PTEG sources",
		.pmg_event_ids = { 297, 306, 293, 291, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000100004e4e284aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 30 ] = {
		.pmg_name = "pm_pteg4",
		.pmg_desc = "PTEG sources",
		.pmg_event_ids = { 298, 304, 294, 291, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000100004a4a4a4aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 31 ] = {
		.pmg_name = "pm_pteg5",
		.pmg_desc = "PTEG sources",
		.pmg_event_ids = { 299, 307, 290, 292, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000100004c4c4cc8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 32 ] = {
		.pmg_name = "pm_data_tablewalk",
		.pmg_desc = "Data tablewalks",
		.pmg_event_ids = { 17, 26, 19, 312, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x09900000a0a284e8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 33 ] = {
		.pmg_name = "pm_inst_tablewalk",
		.pmg_desc = "Instruction tablewalks",
		.pmg_event_ids = { 148, 158, 150, 157, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x09900000a8aa8ceaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 34 ] = {
		.pmg_name = "pm_freq",
		.pmg_desc = "Frequency events",
		.pmg_event_ids = { 52, 55, 115, 123, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000002a3c3c3cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 35 ] = {
		.pmg_name = "pm_disp_wait",
		.pmg_desc = "Dispatch stalls",
		.pmg_event_ids = { 154, 64, 54, 62, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000560c040cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 36 ] = {
		.pmg_name = "pm_disp_held",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 52, 55, 305, 56, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x200000002a3c2aa2ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 37 ] = {
		.pmg_name = "pm_disp_held2",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 39, 38, 32, 41, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x200000008004a4a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 38 ] = {
		.pmg_name = "pm_disp_held3",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 54, 49, 50, 55, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x20000000888aacaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 39 ] = {
		.pmg_name = "pm_disp_held4",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 35, 52, 41, 44, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x02000000a0a28486ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 40 ] = {
		.pmg_name = "pm_disp_held5",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 36, 54, 30, 46, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x22000000a8aa8ca0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 41 ] = {
		.pmg_name = "pm_disp_held6",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 40, 63, 42, 54, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x33000000a882a4a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 42 ] = {
		.pmg_name = "pm_disp_held7",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 38, 61, 49, 39, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x30000000888aacaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 43 ] = {
		.pmg_name = "pm_disp_held8",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 41, 60, 47, 42, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x220000008a8cae80ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 44 ] = {
		.pmg_name = "pm_disp_held9",
		.pmg_desc = "Dispatch held conditions",
		.pmg_event_ids = { 41, 43, 45, 38, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x220000008aa08a8cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 45 ] = {
		.pmg_name = "pm_sync",
		.pmg_desc = "Sync events",
		.pmg_event_ids = { 247, 11, 303, 52, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x38900000ae1eeca0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 46 ] = {
		.pmg_name = "pm_L1_ref",
		.pmg_desc = "L1 references",
		.pmg_event_ids = { 202, 212, 300, 301, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x80000000368aa63aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 47 ] = {
		.pmg_name = "pm_L1_ldst",
		.pmg_desc = "L1 load/store ref/miss",
		.pmg_event_ids = { 310, 212, 299, 202, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x800000003230a8a0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 48 ] = {
		.pmg_name = "pm_streams",
		.pmg_desc = "Streams",
		.pmg_event_ids = { 21, 29, 155, 136, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x48000000a0a284a4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 49 ] = {
		.pmg_name = "pm_flush",
		.pmg_desc = "Flushes",
		.pmg_event_ids = { 67, 77, 67, 76, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0022000010cacccaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 50 ] = {
		.pmg_name = "pm_prefetch",
		.pmg_desc = "I cache Prefetches",
		.pmg_event_ids = { 136, 142, 134, 140, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x400400008a8caec0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 51 ] = {
		.pmg_name = "pm_stcx",
		.pmg_desc = "STCX",
		.pmg_event_ids = { 304, 311, 298, 200, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00080000e6eccecaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 52 ] = {
		.pmg_name = "pm_larx",
		.pmg_desc = "LARX",
		.pmg_event_ids = { 197, 208, 296, 297, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00080000eae2c6ceULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 53 ] = {
		.pmg_name = "pm_thread_cyc",
		.pmg_desc = "Thread cycles",
		.pmg_event_ids = { 315, 320, 306, 304, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000016182604ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 54 ] = {
		.pmg_name = "pm_misc",
		.pmg_desc = "Misc",
		.pmg_event_ids = { 1, 137, 313, 306, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000004161808ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 55 ] = {
		.pmg_name = "pm_misc2",
		.pmg_desc = "Misc",
		.pmg_event_ids = { 57, 67, 304, 0, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x40020000eef8f8a0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 56 ] = {
		.pmg_name = "pm_misc3",
		.pmg_desc = "Misc",
		.pmg_event_ids = { 307, 321, 10, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0300000054a01e02ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 57 ] = {
		.pmg_name = "pm_tlb_slb",
		.pmg_desc = "TLB and SLB events",
		.pmg_event_ids = { 152, 65, 314, 159, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00980000e0e8e8e2ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 58 ] = {
		.pmg_name = "pm_slb_miss",
		.pmg_desc = "SLB Misses",
		.pmg_event_ids = { 152, 65, 136, 294, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00480001e0e8ee32ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 59 ] = {
		.pmg_name = "pm_rejects",
		.pmg_desc = "Reject events",
		.pmg_event_ids = { 239, 249, 236, 238, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xaa00000034303e30ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 60 ] = {
		.pmg_name = "pm_rejects2",
		.pmg_desc = "Reject events",
		.pmg_event_ids = { 240, 250, 235, 243, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x9a000000323830acULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 61 ] = {
		.pmg_name = "pm_rejects3",
		.pmg_desc = "Reject events",
		.pmg_event_ids = { 243, 253, 237, 242, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xaa000000303e3234ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 62 ] = {
		.pmg_name = "pm_rejects4",
		.pmg_desc = "Unaligned store rejects",
		.pmg_event_ids = { 245, 256, 214, 232, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x900000003630a2aaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 63 ] = {
		.pmg_name = "pm_rejects5",
		.pmg_desc = "Unaligned load rejects",
		.pmg_event_ids = { 244, 255, 213, 231, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x900000003036a0a8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 64 ] = {
		.pmg_name = "pm_rejects6",
		.pmg_desc = "Set mispredictions rejects",
		.pmg_event_ids = { 216, 238, 238, 244, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xa0000000848c341cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 65 ] = {
		.pmg_name = "pm_rejects_unit",
		.pmg_desc = "Unaligned reject events by unit",
		.pmg_event_ids = { 218, 241, 214, 231, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x90000000808aa2a8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 66 ] = {
		.pmg_name = "pm_rejects_unit2",
		.pmg_desc = "Reject events by unit",
		.pmg_event_ids = { 208, 218, 217, 227, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xaa000000a6828e8aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 67 ] = {
		.pmg_name = "pm_rejects_unit3",
		.pmg_desc = "Reject events by unit",
		.pmg_event_ids = { 210, 221, 219, 225, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0a000000a4a08c88ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 68 ] = {
		.pmg_name = "pm_rejects_unit4",
		.pmg_desc = "Reject events by unit",
		.pmg_event_ids = { 214, 224, 222, 228, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xaa000000a2868aaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 69 ] = {
		.pmg_name = "pm_rejects_unit5",
		.pmg_desc = "Reject events by unit",
		.pmg_event_ids = { 213, 213, 221, 220, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x9900000086a6ae8eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 70 ] = {
		.pmg_name = "pm_rejects_unit6",
		.pmg_desc = "Reject events by unit",
		.pmg_event_ids = { 217, 217, 225, 222, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xaa00000080a6a88eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 71 ] = {
		.pmg_name = "pm_rejects_unit7",
		.pmg_desc = "Reject events by unit",
		.pmg_event_ids = { 209, 213, 218, 220, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xa900000082a6aa8eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 72 ] = {
		.pmg_name = "pm_ldf",
		.pmg_desc = "Floating Point loads",
		.pmg_event_ids = { 237, 246, 200, 221, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x800000003832a4acULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 73 ] = {
		.pmg_name = "pm_lsu_misc",
		.pmg_desc = "LSU events",
		.pmg_event_ids = { 206, 216, 240, 233, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x08800000caccee8aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 74 ] = {
		.pmg_name = "pm_lsu_lmq",
		.pmg_desc = "LSU LMQ events",
		.pmg_event_ids = { 238, 248, 234, 211, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x98000000ac1c1ca4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 75 ] = {
		.pmg_name = "pm_lsu_flush_derat_miss",
		.pmg_desc = "LSU flush and DERAT misses",
		.pmg_event_ids = { 234, 243, 229, 236, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00200000fc0eeceeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 76 ] = {
		.pmg_name = "pm_lla",
		.pmg_desc = "Look Load Ahead events",
		.pmg_event_ids = { 140, 51, 139, 306, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x33000000a2841208ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 77 ] = {
		.pmg_name = "pm_gct",
		.pmg_desc = "GCT events",
		.pmg_event_ids = { 121, 127, 119, 147, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x404000000808a6e8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 78 ] = {
		.pmg_name = "pm_smt_priorities",
		.pmg_desc = "Thread priority events",
		.pmg_event_ids = { 316, 322, 308, 307, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0020000040404040ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 79 ] = {
		.pmg_name = "pm_smt_priorities2",
		.pmg_desc = "Thread priority events",
		.pmg_event_ids = { 317, 323, 309, 308, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0020000046464646ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 80 ] = {
		.pmg_name = "pm_smt_priorities3",
		.pmg_desc = "Thread priority differences events",
		.pmg_event_ids = { 318, 324, 310, 309, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0002000040404040ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 81 ] = {
		.pmg_name = "pm_smt_priorities4",
		.pmg_desc = "Thread priority differences events",
		.pmg_event_ids = { 319, 325, 311, 310, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x03020000a6464646ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 82 ] = {
		.pmg_name = "pm_fxu",
		.pmg_desc = "FXU events",
		.pmg_event_ids = { 117, 125, 116, 124, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000050505050ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 83 ] = {
		.pmg_name = "pm_fxu2",
		.pmg_desc = "FXU events",
		.pmg_event_ids = { 118, 147, 117, 125, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x02040000aee41616ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 84 ] = {
		.pmg_name = "pm_vmx",
		.pmg_desc = "VMX events",
		.pmg_event_ids = { 329, 337, 329, 324, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x700000008480a2a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 85 ] = {
		.pmg_name = "pm_vmx2",
		.pmg_desc = "VMX events",
		.pmg_event_ids = { 321, 332, 316, 318, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x600000008088a2aaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 86 ] = {
		.pmg_name = "pm_vmx3",
		.pmg_desc = "VMX events",
		.pmg_event_ids = { 322, 330, 320, 319, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x600000008284aaacULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 87 ] = {
		.pmg_name = "pm_vmx4",
		.pmg_desc = "VMX events",
		.pmg_event_ids = { 331, 340, 328, 328, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xb0000000828ea6a0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 88 ] = {
		.pmg_name = "pm_vmx5",
		.pmg_desc = "VMX events",
		.pmg_event_ids = { 336, 331, 322, 323, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xb00000008084aca2ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 89 ] = {
		.pmg_name = "pm_dfu",
		.pmg_desc = "DFU events",
		.pmg_event_ids = { 23, 31, 24, 33, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xe00000008c88a2aeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 90 ] = {
		.pmg_name = "pm_dfu2",
		.pmg_desc = "DFU events",
		.pmg_event_ids = { 27, 35, 28, 37, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xe00000008a84a0a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 91 ] = {
		.pmg_name = "pm_fab",
		.pmg_desc = "Fabric events",
		.pmg_event_ids = { 59, 69, 59, 67, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500020003030a4acULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 92 ] = {
		.pmg_name = "pm_fab2",
		.pmg_desc = "Fabric events",
		.pmg_event_ids = { 63, 74, 64, 72, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x50002000888aa2a0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 93 ] = {
		.pmg_name = "pm_fab3",
		.pmg_desc = "Fabric events",
		.pmg_event_ids = { 59, 69, 58, 68, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500020003030aea6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 94 ] = {
		.pmg_name = "pm_mem_dblpump",
		.pmg_desc = "Double pump",
		.pmg_event_ids = { 257, 268, 250, 255, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000400030303434ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 95 ] = {
		.pmg_name = "pm_mem0_dblpump",
		.pmg_desc = "MCS0 Double pump",
		.pmg_event_ids = { 250, 262, 242, 248, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500040008082a4a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 96 ] = {
		.pmg_name = "pm_mem1_dblpump",
		.pmg_desc = "MCS1 Double pump",
		.pmg_event_ids = { 254, 266, 246, 252, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x50004000888aacaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 97 ] = {
		.pmg_name = "pm_gxo",
		.pmg_desc = "GX outbound",
		.pmg_event_ids = { 126, 132, 125, 129, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500060008082a4a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 98 ] = {
		.pmg_name = "pm_gxi",
		.pmg_desc = "GX inbound",
		.pmg_event_ids = { 123, 129, 122, 132, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500060008688aaa0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 99 ] = {
		.pmg_name = "pm_gx_dma",
		.pmg_desc = "DMA events",
		.pmg_event_ids = { 126, 130, 126, 135, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500060008086acaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 100 ] = {
		.pmg_name = "pm_L1_misc",
		.pmg_desc = "L1 misc events",
		.pmg_event_ids = { 142, 165, 285, 153, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x4004000082e2a80aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 101 ] = {
		.pmg_name = "pm_L2_data",
		.pmg_desc = "L2 load and store data",
		.pmg_event_ids = { 186, 195, 188, 193, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000800030303434ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 102 ] = {
		.pmg_name = "pm_L2_ld_inst",
		.pmg_desc = "L2 Load instructions",
		.pmg_event_ids = { 187, 196, 185, 191, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5800a00030303486ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 103 ] = {
		.pmg_name = "pm_L2_castout_invalidate",
		.pmg_desc = "L2 castout and invalidate events",
		.pmg_event_ids = { 185, 194, 131, 27, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000c00030303434ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 104 ] = {
		.pmg_name = "pm_L2_ldst_reqhit",
		.pmg_desc = "L2 load and store requests and hits",
		.pmg_event_ids = { 203, 209, 301, 298, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000e00030303434ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 105 ] = {
		.pmg_name = "pm_L2_ld_data_slice",
		.pmg_desc = "L2 data loads by slice",
		.pmg_event_ids = { 165, 171, 179, 182, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500080008082a8aaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 106 ] = {
		.pmg_name = "pm_L2_ld_inst_slice",
		.pmg_desc = "L2 instruction loads by slice",
		.pmg_event_ids = { 166, 172, 180, 183, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000a0008082a8aaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 107 ] = {
		.pmg_name = "pm_L2_st_slice",
		.pmg_desc = "L2 slice stores by slice",
		.pmg_event_ids = { 170, 178, 184, 189, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x500080008486acaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 108 ] = {
		.pmg_name = "pm_L2miss_slice",
		.pmg_desc = "L2 misses by slice",
		.pmg_event_ids = { 167, 197, 13, 187, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000a000843256acULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 109 ] = {
		.pmg_name = "pm_L2_castout_slice",
		.pmg_desc = "L2 castouts by slice",
		.pmg_event_ids = { 157, 167, 171, 178, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000c0008082a8aaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 110 ] = {
		.pmg_name = "pm_L2_invalidate_slice",
		.pmg_desc = "L2 invalidate by slice",
		.pmg_event_ids = { 160, 168, 174, 179, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000c0008486acaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 111 ] = {
		.pmg_name = "pm_L2_ld_reqhit_slice",
		.pmg_desc = "L2 load requests and hist by slice",
		.pmg_event_ids = { 164, 170, 178, 181, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000e0008082a8aaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 112 ] = {
		.pmg_name = "pm_L2_st_reqhit_slice",
		.pmg_desc = "L2 store requests and hist by slice",
		.pmg_event_ids = { 170, 177, 184, 188, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5000e0008486acaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 113 ] = {
		.pmg_name = "pm_L2_redir_pref",
		.pmg_desc = "L2 redirect and prefetch",
		.pmg_event_ids = { 131, 140, 187, 191, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x08400000cacc8886ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 114 ] = {
		.pmg_name = "pm_L3_SliceA",
		.pmg_desc = "L3 slice A events",
		.pmg_event_ids = { 193, 201, 14, 195, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x50000000303058a4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 115 ] = {
		.pmg_name = "pm_L3_SliceB",
		.pmg_desc = "L3 slice B events",
		.pmg_event_ids = { 196, 204, 14, 198, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x50000000888a58acULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 116 ] = {
		.pmg_name = "pm_fpu_issue",
		.pmg_desc = "FPU issue events",
		.pmg_event_ids = { 107, 116, 105, 120, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00300000c6c8eae4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 117 ] = {
		.pmg_name = "pm_fpu_issue2",
		.pmg_desc = "FPU issue events",
		.pmg_event_ids = { 111, 124, 106, 118, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00300000c0c2eceeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 118 ] = {
		.pmg_name = "pm_fpu_issue3",
		.pmg_desc = "FPU issue events",
		.pmg_event_ids = { 114, 120, 106, 118, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00330000e0e2eceeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 119 ] = {
		.pmg_name = "pm_fpu0_flop",
		.pmg_desc = "FPU0 flop events",
		.pmg_event_ids = { 71, 86, 78, 90, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xcc0000008082a484ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 120 ] = {
		.pmg_name = "pm_fpu0_misc",
		.pmg_desc = "FPU0 events",
		.pmg_event_ids = { 76, 90, 70, 89, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xcc00000086a08286ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 121 ] = {
		.pmg_name = "pm_fpu0_misc2",
		.pmg_desc = "FPU0 events",
		.pmg_event_ids = { 75, 83, 76, 88, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xdd00000080a6a4a6ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 122 ] = {
		.pmg_name = "pm_fpu0_misc3",
		.pmg_desc = "FPU0 events",
		.pmg_event_ids = { 73, 88, 83, 80, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0d000000a0a28486ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 123 ] = {
		.pmg_name = "pm_fpu1_flop",
		.pmg_desc = "FPU1 flop events",
		.pmg_event_ids = { 86, 101, 93, 105, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xcc000000888aac8cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 124 ] = {
		.pmg_name = "pm_fpu1_misc",
		.pmg_desc = "FPU1 events",
		.pmg_event_ids = { 91, 105, 85, 104, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xcc0000008ea88a8eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 125 ] = {
		.pmg_name = "pm_fpu1_misc2",
		.pmg_desc = "FPU1 events",
		.pmg_event_ids = { 90, 98, 91, 103, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xdd00000088aeacaeULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 126 ] = {
		.pmg_name = "pm_fpu1_misc3",
		.pmg_desc = "FPU1 events",
		.pmg_event_ids = { 88, 103, 98, 95, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0d000000a8aa8c8eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 127 ] = {
		.pmg_name = "pm_fpu_flop",
		.pmg_desc = "FPU flop events",
		.pmg_event_ids = { 101, 111, 102, 109, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xc000000030303434ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 128 ] = {
		.pmg_name = "pm_fpu_misc",
		.pmg_desc = "FPU events",
		.pmg_event_ids = { 103, 113, 100, 111, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xdd00000030343434ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 129 ] = {
		.pmg_name = "pm_fpu_misc2",
		.pmg_desc = "FPU events",
		.pmg_event_ids = { 105, 110, 113, 122, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0c00000034343030ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 130 ] = {
		.pmg_name = "pm_fpu_misc3",
		.pmg_desc = "FPU events",
		.pmg_event_ids = { 102, 113, 114, 108, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0d00000034343030ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 131 ] = {
		.pmg_name = "pm_purr",
		.pmg_desc = "PURR events",
		.pmg_event_ids = { 301, 309, 10, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000000ef41e02ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 132 ] = {
		.pmg_name = "pm_suspend",
		.pmg_desc = "SUSPENDED events",
		.pmg_event_ids = { 311, 11, 303, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00900000001eec02ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 133 ] = {
		.pmg_name = "pm_dcache",
		.pmg_desc = "D cache",
		.pmg_event_ids = { 200, 243, 197, 234, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000000c0e0c06ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 134 ] = {
		.pmg_name = "pm_derat_miss",
		.pmg_desc = "DERAT miss",
		.pmg_event_ids = { 351, 361, 343, 343, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0090000f40404040ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 135 ] = {
		.pmg_name = "pm_derat_ref",
		.pmg_desc = "DERAT ref",
		.pmg_event_ids = { 350, 360, 342, 342, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0080000f40404040ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 136 ] = {
		.pmg_name = "pm_ierat_miss",
		.pmg_desc = "IERAT miss",
		.pmg_event_ids = { 352, 362, 344, 344, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0090000f46464646ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 137 ] = {
		.pmg_name = "pm_mrk_br",
		.pmg_desc = "Marked Branch events",
		.pmg_event_ids = { 258, 280, 251, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000052565202ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 138 ] = {
		.pmg_name = "pm_mrk_dsource",
		.pmg_desc = "Marked data sources",
		.pmg_event_ids = { 139, 269, 252, 256, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000024a4c4cULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 139 ] = {
		.pmg_name = "pm_mrk_dsource2",
		.pmg_desc = "Marked data sources",
		.pmg_event_ids = { 259, 270, 253, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000048484e02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 140 ] = {
		.pmg_name = "pm_mrk_dsource3",
		.pmg_desc = "Marked data sources",
		.pmg_event_ids = { 260, 148, 254, 257, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000002802484eULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 141 ] = {
		.pmg_name = "pm_mrk_dsource4",
		.pmg_desc = "Marked data sources",
		.pmg_event_ids = { 261, 271, 255, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000004e4e2802ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 142 ] = {
		.pmg_name = "pm_mrk_dsource5",
		.pmg_desc = "Marked data sources",
		.pmg_event_ids = { 262, 272, 138, 258, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000004a4c024aULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 143 ] = {
		.pmg_name = "pm_mrk_dsource6",
		.pmg_desc = "Marked data sources",
		.pmg_event_ids = { 263, 272, 256, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000004c4c4a02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 144 ] = {
		.pmg_name = "pm_mrk_rejects",
		.pmg_desc = "Marked rejects",
		.pmg_event_ids = { 276, 288, 138, 273, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0009000d34340230ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 145 ] = {
		.pmg_name = "pm_mrk_rejects2",
		.pmg_desc = "Marked rejects LSU0",
		.pmg_event_ids = { 270, 283, 266, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00090000e6e0c202ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 146 ] = {
		.pmg_name = "pm_mrk_rejects3",
		.pmg_desc = "Marked rejects LSU1",
		.pmg_event_ids = { 273, 286, 269, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00090000eee8ca02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 147 ] = {
		.pmg_name = "pm_mrk_inst",
		.pmg_desc = "Marked instruction events",
		.pmg_event_ids = { 268, 279, 262, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000001c100a02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 148 ] = {
		.pmg_name = "pm_mrk_fpu_fin",
		.pmg_desc = "Marked Floating Point instructions finished",
		.pmg_event_ids = { 265, 275, 261, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xd0000000828a1a02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 149 ] = {
		.pmg_name = "pm_mrk_misc",
		.pmg_desc = "Marked misc events",
		.pmg_event_ids = { 276, 277, 257, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00090008341a0802ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 150 ] = {
		.pmg_name = "pm_mrk_misc2",
		.pmg_desc = "Marked misc events",
		.pmg_event_ids = { 281, 278, 138, 263, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00080000e40a023eULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 151 ] = {
		.pmg_name = "pm_mrk_misc3",
		.pmg_desc = "Marked misc events",
		.pmg_event_ids = { 289, 281, 138, 271, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xb009000088e40212ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 152 ] = {
		.pmg_name = "pm_mrk_misc4",
		.pmg_desc = "Marked misc events",
		.pmg_event_ids = { 12, 11, 138, 272, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000001e1e021aULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 153 ] = {
		.pmg_name = "pm_mrk_st",
		.pmg_desc = "Marked stores events",
		.pmg_event_ids = { 282, 294, 277, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000006060602ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 154 ] = {
		.pmg_name = "pm_mrk_pteg",
		.pmg_desc = "Marked PTEG",
		.pmg_event_ids = { 277, 289, 271, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0010000040424402ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 155 ] = {
		.pmg_name = "pm_mrk_pteg2",
		.pmg_desc = "Marked PTEG",
		.pmg_event_ids = { 139, 290, 272, 275, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0010000002404644ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 156 ] = {
		.pmg_name = "pm_mrk_pteg3",
		.pmg_desc = "Marked PTEG",
		.pmg_event_ids = { 278, 291, 138, 276, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0010000046460246ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 157 ] = {
		.pmg_name = "pm_mrk_pteg4",
		.pmg_desc = "Marked PTEG",
		.pmg_event_ids = { 279, 148, 273, 277, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0010000042024054ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 158 ] = {
		.pmg_name = "pm_mrk_pteg5",
		.pmg_desc = "Marked PTEG",
		.pmg_event_ids = { 280, 148, 274, 278, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0010000044025442ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 159 ] = {
		.pmg_name = "pm_mrk_pteg6",
		.pmg_desc = "Marked PTEG",
		.pmg_event_ids = { 12, 292, 275, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x001000001e444202ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 160 ] = {
		.pmg_name = "pm_mrk_vmx",
		.pmg_desc = "Marked VMX",
		.pmg_event_ids = { 285, 298, 282, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x700000008c88ae02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 161 ] = {
		.pmg_name = "pm_mrk_vmx2",
		.pmg_desc = "Marked VMX",
		.pmg_event_ids = { 283, 296, 258, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x60900000868ee002ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 162 ] = {
		.pmg_name = "pm_mrk_vmx3",
		.pmg_desc = "Marked VMX",
		.pmg_event_ids = { 288, 342, 10, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x700000008a821e02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 163 ] = {
		.pmg_name = "pm_mrk_fp",
		.pmg_desc = "Marked FP events",
		.pmg_event_ids = { 265, 276, 260, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xd00000008230aa02ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 164 ] = {
		.pmg_name = "pm_mrk_derat_ref",
		.pmg_desc = "Marked DERAT ref",
		.pmg_event_ids = { 353, 363, 345, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0080000044444402ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 165 ] = {
		.pmg_name = "pm_mrk_derat_miss",
		.pmg_desc = "Marked DERAT miss",
		.pmg_event_ids = { 354, 364, 346, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0090000044444402ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 166 ] = {
		.pmg_name = "pm_dcache_edge",
		.pmg_desc = "D cache - edge",
		.pmg_event_ids = { 199, 243, 197, 335, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000000d0e0c07ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 167 ] = {
		.pmg_name = "pm_lsu_lmq_edge",
		.pmg_desc = "LSU LMQ events - edge",
		.pmg_event_ids = { 238, 359, 341, 211, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x98000000ac1d1da4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 168 ] = {
		.pmg_name = "pm_gct_edge",
		.pmg_desc = "GCT events - edge",
		.pmg_event_ids = { 349, 358, 333, 147, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x404000000909a7e8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 169 ] = {
		.pmg_name = "pm_freq_edge",
		.pmg_desc = "Frequency events - edge",
		.pmg_event_ids = { 348, 356, 115, 123, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000002b3d3c3cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 170 ] = {
		.pmg_name = "pm_disp_wait_edge",
		.pmg_desc = "Dispatch stalls - edge",
		.pmg_event_ids = { 154, 357, 340, 340, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00000000560d050dULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 171 ] = {
		.pmg_name = "pm_edge1",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 199, 64, 339, 337, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000006300d0c1f1eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 172 ] = {
		.pmg_name = "pm_edge2",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 337, 0, 332, 136, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x400000008180a5a4ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 173 ] = {
		.pmg_name = "pm_edge3",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 343, 309, 335, 157, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x009000000bf4ebeaULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 174 ] = {
		.pmg_name = "pm_edge4",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 339, 128, 334, 287, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x400000008786a9a8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 175 ] = {
		.pmg_name = "pm_edge5",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 344, 351, 336, 303, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00900000fb17edecULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 176 ] = {
		.pmg_name = "pm_noedge5",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 315, 137, 336, 303, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00900000fa16edecULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 177 ] = {
		.pmg_name = "pm_edge6",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 348, 355, 340, 340, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000002b05050dULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 178 ] = {
		.pmg_name = "pm_noedge6",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 52, 38, 54, 62, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000002a04040cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 179 ] = {
		.pmg_name = "pm_edge7",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 349, 358, 341, 341, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000009091d1dULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 180 ] = {
		.pmg_name = "pm_noedge7",
		.pmg_desc = "NOEDGE event group",
		.pmg_event_ids = { 121, 127, 234, 244, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000008081c1cULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 181 ] = {
		.pmg_name = "pm_edge8",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 342, 359, 303, 335, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00900000cd1dec07ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 182 ] = {
		.pmg_name = "pm_noedge8",
		.pmg_desc = "NOEDGE event group",
		.pmg_event_ids = { 312, 248, 336, 234, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x00900000cc1ced06ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 183 ] = {
		.pmg_name = "pm_edge9",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 309, 357, 197, 203, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x80000000880d0ca2ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 184 ] = {
		.pmg_name = "pm_edge10",
		.pmg_desc = "EDGE event group",
		.pmg_event_ids = { 31, 356, 31, 336, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x32000000ac3dae05ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 185 ] = {
		.pmg_name = "pm_noedge10",
		.pmg_desc = "NOEDGE event group",
		.pmg_event_ids = { 31, 55, 31, 304, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x32000000ac3cae04ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 186 ] = {
		.pmg_name = "pm_hpm1",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 101, 111, 102, 12, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xc00000003030341eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 187 ] = {
		.pmg_name = "pm_hpm2",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 139, 246, 113, 12, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x8c0000000232301eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 188 ] = {
		.pmg_name = "pm_hpm3",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 12, 210, 299, 145, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x800000001e80f002ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 189 ] = {
		.pmg_name = "pm_hpm4",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 139, 149, 198, 300, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x800000000212a234ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 190 ] = {
		.pmg_name = "pm_hpm5",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 103, 11, 117, 125, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xd0000000301e1616ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 191 ] = {
		.pmg_name = "pm_hpm6",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 13, 15, 12, 16, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0000000058585a5aULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 192 ] = {
		.pmg_name = "pm_hpm7",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 14, 19, 14, 12, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x000000005a5a581eULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 193 ] = {
		.pmg_name = "pm_hpm8",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 101, 111, 113, 202, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0xcc000000303030f0ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 194 ] = {
		.pmg_name = "pm_hpm9",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 199, 11, 231, 299, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x80000000801e34a8ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 195 ] = {
		.pmg_name = "pm_hpm10",
		.pmg_desc = "HPM group",
		.pmg_event_ids = { 139, 197, 146, 19, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x5040a00002325456ULL,
		.pmg_mmcra = 0x0000000000000000ULL
	},
	[ 196 ] = {
		.pmg_name = "pm_mrk_derat_ref2",
		.pmg_desc = "Marked DERAT ref",
		.pmg_event_ids = { 353, 363, 138, 345, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0080000044440244ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	},
	[ 197 ] = {
		.pmg_name = "pm_mrk_derat_miss2",
		.pmg_desc = "Marked DERAT miss",
		.pmg_event_ids = { 354, 364, 138, 346, 0, 0 },
		.pmg_mmcr0 = 0x0000000000000000ULL,
		.pmg_mmcr1 = 0x0090000044440244ULL,
		.pmg_mmcra = 0x0000000000000001ULL
	}
};
#endif

