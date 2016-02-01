#ifndef __timer_defs_h
#define __timer_defs_h

#include "system_types.h"
/**
 * @brief table 783
 * timer interupt control
 */
struct TimerInterruptControl{
    unsigned match0    : 1;
    unsigned match1    : 1;
    unsigned match2    : 1;
    unsigned match3    : 1;
    unsigned capture0  : 1;
    unsigned capture1  : 1;
    unsigned capture2  : 1;
    unsigned capture3  : 1;
    unsigned           :24; //reserved
};

#define TIMER0_INTERRUPT_CONTROL (*(volatile struct TimerInterruptControl *)(0x40084000))
#define TIMER1_INTERRUPT_CONTROL (*(volatile struct TimerInterruptControl *)(0x40085000))
#define TIMER3_INTERRUPT_CONTROL (*(volatile struct TimerInterruptControl *)(0x400C3000))
#define TIMER4_INTERRUPT_CONTROL (*(volatile struct TimerInterruptControl *)(0x400C4000))


/**
 * @brief Table 784
 * Timer Control
 */
struct TimerCounterControl{
    unsigned counterEnable  : 1;
    unsigned counterReset   : 1;
    unsigned                :30; //reserved
};
#define TIMER0_COUNTER_CONTROL (*(volatile struct TimerCounterControl *)(0x40084004))
#define TIMER1_COUNTER_CONTROL (*(volatile struct TimerCounterControl *)(0x40085004))
#define TIMER3_COUNTER_CONTROL (*(volatile struct TimerCounterControl *)(0x400C3004))
#define TIMER4_COUNTER_CONTROL (*(volatile struct TimerCounterControl *)(0x400C4004))

/**
 * @brief Table 785 
 * timer counter value
*/
#define TIMER0_COUNTER (*(volatile uint32_t *)(0x40084008))
#define TIMER1_COUNTER (*(volatile uint32_t *)(0x40085008))
#define TIMER2_COUNTER (*(volatile uint32_t *)(0x400C3008))
#define TIMER3_COUNTER (*(volatile uint32_t *)(0x400C4008))

/**
 * @brief Table 786
 * timer prescale maximum value
 */
#define TIMER0_PRESCALE (*(volatile uint32_t *)(0x4008400C))
#define TIMER1_PRESCALE (*(volatile uint32_t *)(0x4008500C))
#define TIMER2_PRESCALE (*(volatile uint32_t *)(0x400C300C))
#define TIMER3_PRESCALE (*(volatile uint32_t *)(0x400C400C))

/**
 * @brief Table 787
 * timer prescale count value
 */
#define TIMER0_PRESCALE_COUNT (*(volatile uint32_t *)(0x40084010))
#define TIMER1_PRESCALE_COUNT (*(volatile uint32_t *)(0x40085010))
#define TIMER2_PRESCALE_COUNT (*(volatile uint32_t *)(0x400C3010))
#define TIMER3_PRESCALE_COUNT (*(volatile uint32_t *)(0x400C4010))


/**
 * @brief Table 788
 * Timer Match Control
 */
struct TimerMatchControl{
    unsigned match0_interruptEnable      : 1;
    unsigned match0_resetEnable          : 1;
    unsigned match0_stopEnable           : 1;
    unsigned match1_interruptEnable      : 1;
    unsigned match1_resetEnable          : 1;
    unsigned match1_stopEnable           : 1;
    unsigned match2_interruptEnable      : 1;
    unsigned match2_resetEnable          : 1;
    unsigned match2_stopEnable           : 1;
    unsigned match3_interruptEnable      : 1;
    unsigned match3_resetEnable          : 1;
    unsigned match3_stopEnable           : 1;
    unsigned                             :20;
};

#define TIMER0_MATCH_CONTROL (*(volatile struct TimerMatchControl *)(0x40084014))
#define TIMER1_MATCH_CONTROL (*(volatile struct TimerMatchControl *)(0x40085014))
#define TIMER2_MATCH_CONTROL (*(volatile struct TimerMatchControl *)(0x400C3014))
#define TIMER3_MATCH_CONTROL (*(volatile struct TimerMatchControl *)(0x400C4014))

/* Table 789
 * Match Registers
 */
#define TIMER0_MATCH0 (*(volatile uint32_t *)(0x40084018))
#define TIMER1_MATCH0 (*(volatile uint32_t *)(0x40085018))
#define TIMER2_MATCH0 (*(volatile uint32_t *)(0x400C3018))
#define TIMER3_MATCH0 (*(volatile uint32_t *)(0x400C4018))

#define TIMER0_MATCH1 (*(volatile uint32_t *)(0x4008401C))
#define TIMER1_MATCH1 (*(volatile uint32_t *)(0x4008501C))
#define TIMER2_MATCH1 (*(volatile uint32_t *)(0x400C301C))
#define TIMER3_MATCH1 (*(volatile uint32_t *)(0x400C401C))

#define TIMER0_MATCH2 (*(volatile uint32_t *)(0x40084020))
#define TIMER1_MATCH2 (*(volatile uint32_t *)(0x40085020))
#define TIMER2_MATCH2 (*(volatile uint32_t *)(0x400C3020))
#define TIMER3_MATCH2 (*(volatile uint32_t *)(0x400C4020))

#define TIMER0_MATCH3 (*(volatile uint32_t *)(0x40084024))
#define TIMER1_MATCH3 (*(volatile uint32_t *)(0x40085024))
#define TIMER2_MATCH3 (*(volatile uint32_t *)(0x400C3024))
#define TIMER3_MATCH3 (*(volatile uint32_t *)(0x400C4024))


/**
 * @brief Table 790
 * Timer Capture Control
 *
 */
struct TimerCaptureControl{
    unsigned cap0_RiseEnable       : 1;
    unsigned cap0_FallEnable       : 1;
    unsigned cap0_InterruptEnable  : 1;
    unsigned cap1_RiseEnable       : 1;
    unsigned cap1_FallEnable       : 1;
    unsigned cap1_InterruptEnable  : 1;
    unsigned cap2_RiseEnable       : 1;
    unsigned cap2_FallEnable       : 1;
    unsigned cap2_InterruptEnable2  : 1;
    unsigned cap3_RiseEnable3       : 1;
    unsigned cap3_FallEnable3       : 1;
    unsigned cap3_InterruptEnable3  : 1;
};


#define TIMER0_CAPTURE_CONTROL (*(volatile struct TimerCaptureControl)(0x40084028))
#define TIMER1_CAPTURE_CONTROL (*(volatile struct TimerCaptureControl)(0x40085028))
#define TIMER2_CAPTURE_CONTROL (*(volatile struct TimerCaptureControl)(0x400C3028))
#define TIMER3_CAPTURE_CONTROL (*(volatile struct TimerCaptureControl)(0x400C4028))


/**
 * @brief Table 791
 * Timer Capture 
 * 
 */
#define TIMER0_CAPTURE0 (*(volatile uint32_t *)(0x4008402C))
#define TIMER1_CAPTURE0 (*(volatile uint32_t *)(0x4008502C))
#define TIMER2_CAPTURE0 (*(volatile uint32_t *)(0x400C302C))
#define TIMER3_CAPTURE0 (*(volatile uint32_t *)(0x400C402C))

#define TIMER0_CAPTURE1 (*(volatile uint32_t *)(0x40084030))
#define TIMER1_CAPTURE1 (*(volatile uint32_t *)(0x40085030))
#define TIMER2_CAPTURE1 (*(volatile uint32_t *)(0x400C3030))
#define TIMER3_CAPTURE1 (*(volatile uint32_t *)(0x400C4030))

#define TIMER0_CAPTURE2 (*(volatile uint32_t *)(0x40084034))
#define TIMER1_CAPTURE2 (*(volatile uint32_t *)(0x40085034))
#define TIMER2_CAPTURE2 (*(volatile uint32_t *)(0x400C3034))
#define TIMER3_CAPTURE2 (*(volatile uint32_t *)(0x400C4034))

#define TIMER0_CAPTURE3 (*(volatile uint32_t *)(0x40084038))
#define TIMER1_CAPTURE3 (*(volatile uint32_t *)(0x40085038))
#define TIMER2_CAPTURE3 (*(volatile uint32_t *)(0x400C3038))
#define TIMER3_CAPTURE3 (*(volatile uint32_t *)(0x400C4038))

/**
 * @brief Table 792
 *  external match output control register
 *  enable the output pin on mat0_en through mat3_en
 *  matchnEnable-- turn on output for this match
 *  matchnSelect-- 
 *     0x00 do nothing
 *     0x01 clear
 *     0x02 set
 *     0x03 toggle
 */
struct TimerExternalMatchControl{
    unsigned match0_outEnable    : 1;
    unsigned match1_outEnable    : 1;
    unsigned match2_outEnable    : 1;
    unsigned match3_outEnable    : 1;
    unsigned match0_outSelect    : 2;
    unsigned match1_outSelect    : 2;
    unsigned match2_outSelect    : 2;
    unsigned match3_outSelect    : 2;
    unsigned                     :20;
};                 

#define TIMER0_EXTERNAL_MATCH_CONTROL (*(volatile struct TimerExternalMatchControl *)(0x4008403C))
#define TIMER1_EXTERNAL_MATCH_CONTROL (*(volatile struct TimerExternalMatchControl *)(0x4008503C))
#define TIMER2_EXTERNAL_MATCH_CONTROL (*(volatile struct TimerExternalMatchControl *)(0x400C403C))
#define TIMER3_EXTERNAL_MATCH_CONTROL (*(volatile struct TimerExternalMatchControl *)(0x400C503C))

/**
 * @brief Table 794:
 * ### modeSelect
 * define the prescale counter or timer counter increment source
 *           - 0x00 timer mode, rising edge of the timer peripheral clock
 *           - 0x01 counter mode, rising edge of capture input
 *           - 0x02 counter mode, falling edge of capture input
 *           - 0x03 counter mode, rising and falling edges of capture input
 *
 * ###countSelect
 * which capture input pin to use (CAPTURE0,1,2,3 respecitively)
 */
struct TimerCountControl{
    unsigned modeSelect  : 2;  //!< select timer/counter increment source
    unsigned countSelect : 2;  //!< if capture mode, which capture pin to use
    unsigned             :28;
};

#define TIMER0_COUNT_CONTROL (*(volatile struct TimerCountControl *)(0x40084070)
#define TIMER1_COUNT_CONTROL (*(volatile struct TimerCountControl *)(0x40085070)
#define TIMER2_COUNT_CONTROL (*(volatile struct TimerCountControl *)(0x400C3070)
#define TIMER3_COUNT_CONTROL (*(volatile struct TimerCountControl *)(0x400C4070)


#endif //__timer_defs_h
