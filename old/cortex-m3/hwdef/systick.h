#ifndef __SYSTICK_H
#define __SYSTICK_H
#include "micro_types.h"

//SYSTIC STUFF
// Should be common for all ARM cortex-m3 cores.
// Some vendors don't provide information related to SysTick Calibration

typedef struct SysTickControl{
    unsigned counter_enable      : 1;  // bit00
    unsigned interrupt_enable    : 1;  // bit01
    unsigned clock_source_select : 1;  // bit02 0 is external, 1 is processor clock
    unsigned                     :13;  // reserved
    unsigned count_status        : 1;  // bit16 indicates that the counter rolled over since last read
}SysTickControl;
#define SYSTICK_CONTROL       (*(volatile SysTickControl *)(0xE000E010))

typedef struct SysTickCounter{
    unsigned counter_value       : 24;
    unsigned                     :  8;
}SysTickCounter;
#define SYSTICK_RELOAD_VALUE  (*(volatile SysTickCounter *)(0xE000E014))
#define SYSTICK_CURRENT_VALUE (*(volatile SysTickCounter *)(0xE000E018))

typedef struct SysTickCalibration{
    unsigned ten_ms              : 24;  //value has counter number for 10 milliseconds
    unsigned                     :  6;  //reserved
    unsigned clock_skew          :  1;  //if the systick is skewed
    unsigned clock_not_exist     :  1;  //if the device provides a reference clock, this will be 1
}SysTickCalibration;
#define SYSTICK_CALIBRATION   (*(volatile SysTickCalibration *)(0xE000E018))
#endif //__SYSTICK_H
