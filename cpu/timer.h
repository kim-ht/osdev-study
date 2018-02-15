#ifndef _CPU_TIMER_H_
#define _CPU_TIMER_H_

#include "./types.h"

#define TIMER_CHANNEL0_DATA 0x40
#define TIMER_CHANNEL1_DATA 0x41
#define TIMER_CHANNEL2_DATA 0x42
#define TIMER_MODE_COMMAND 0x43

void init_timer(u32 freq);

#endif

