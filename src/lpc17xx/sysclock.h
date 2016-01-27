#ifndef __SYSCLOCK_H
#define __SYSCLOCK_H

#include "micro_types.h"


// this is characteristic of the chip
#define IRC_OSCILLATOR  4000000
// this is characteristic of the board
#define MAIN_OSCILLATOR 12000000
#define RTC_OSCILLATOR  32768


void     sysclock_setMainClock120MHZ(void);
uint32_t sysclock_computeMainClock(void);




#endif //__SYSCLOCK_H
