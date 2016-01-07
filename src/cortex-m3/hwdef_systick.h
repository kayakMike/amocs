#ifndef __HWDEF_SYSTICK_H
#define __HWDEF_SYSTICK_H
#include "micro_types.h"

//SYSTIC STUFF
// Should be common for all ARM cortex-m3 cores, right?
typedef union{
    uint32_t val;
    struct {
        unsigned enableCounter     : 1;
        unsigned enableIrq         : 1;
        unsigned selectClockSource : 1; //0 is external, 1 is processor clock
        unsigned                   : 13;
        unsigned countFlag         : 1;
    }bits;
}SysTickControl;

#define SYSTICK_CONTROL  (*(volatile SysTickControl *)(0xE000E010))


typedef union{
    uint32_t val;
    struct {
        unsigned counterValue : 24;
        unsigned              :  8;
    }bits;
}SysTickCounterValue;

#define SYSTICK_RELOAD_VALUE  (*(volatile SysTickCounterValue *)(0xE000E014))
#define SYSTICK_CURRENT_VALUE (*(volatile SysTickCounterValue *)(0xE000E018))

typedef union{
    uint32_t val;
    struct {
        unsigned tenMillisec     : 24;  //value has counter number for 10 milliseconds
        unsigned                 :  6;
        unsigned isExact         :  1;
        unsigned noReference     :  1;  //if the systick is exact
    }bits;
}SysTickCalibration;

#define SYSTICK_CALIBRATION   (*(volatile SysTickCalibration *)(0xE000E018))
//END SYSTICK STUFF

#endif //__HDEF_SYSTICK_H
