#ifndef __hwdef_systick_h
#define __hwdef_systick_h

/**
 * @brief System tick control register bit fields
 */
struct SysTickControl{
    unsigned counterEnable     : 1;
    unsigned interruptEnable   : 1;
    unsigned clockSelect       : 1;     //!< 0 is external, 1 is processor clock
    unsigned                   : 13;
    unsigned countFlag         : 1;
};

#define SYSTICK_CONTROL  (*(volatile struct SysTickControl *)(0xE000E010))

/**
 * @brief System tick counter register bit fields
 *
 */
struct SysTickCounterValue{
    unsigned counterValue : 24;         //!< value of the counter
    unsigned              :  8;
};
#define SYSTICK_RELOAD  (*(volatile struct SysTickCounterValue *)(0xE000E014))
#define SYSTICK_CURRENT (*(volatile struct SysTickCounterValue *)(0xE000E018))

/**
 * @brief System tick calibration register bit fields
 * look up more info
 *
 */
struct SysTickCalibration{
    unsigned tenMillisec     : 24;  //!< value has counter number for 10 milliseconds
    unsigned                 :  6;
    unsigned isExact         :  1;  //!< true if the value is exact
    unsigned noReference     :  1;  //!< if the systick there is no reference
};

#define SYSTICK_CALIBRATION   (*(volatile struct SysTickCalibration *)(0xE000E018))


#endif //__HWDEF_SYSTICK_H
