#ifndef __HWDEF_TIMER_H
#define __HWDEF_TIMER_H

typedef struct{
    unsigned  match0    : 1;
    unsigned  match1    : 1;
    unsigned  match2    : 1;
    unsigned  match3    : 1;
    unsigned  capture0  : 1;
    unsigned  capture1  : 1;
    unsigned  capture2  : 1;
    unsigned  capture3  : 1;
    unsigned            :26;
}TimerInterrupt;

#define TIMER0_INTERRUPT (*(volatile TimerInterrupt *)(0x40004000))
#define TIMER1_INTERRUPT (*(volatile TimerInterrupt *)(0x40008000))
#define TIMER2_INTERRUPT (*(volatile TimerInterrupt *)(0x40090000))
#define TIMER3_INTERRUPT (*(volatile TimerInterrupt *)(0x40094000))


typedef struct{
    unsigned  enable    : 1;
    unsigned  reset     : 1;
    unsigned            :30;
}TimerControl;


#define TIMER0_CTL (*(volatile TimerControl *)(0x40004004))
#define TIMER1_CTL (*(volatile TimerControl *)(0x40008004))
#define TIMER2_CTL (*(volatile TimerControl *)(0x40090004))
#define TIMER3_CTL (*(volatile TimerControl *)(0x40094004))

typedef struct{
    unsigned  mode    : 2;
    unsigned  input   : 2;
    unsigned          :28;
}TimerCountControl;


#define TIMER0_COUNT_CTL (*(volatile TimerControl *)(0x400040070))
#define TIMER1_COUNT_CTL (*(volatile TimerControl *)(0x400080070))
#define TIMER2_COUNT_CTL (*(volatile TimerControl *)(0x400900070))
#define TIMER3_COUNT_CTL (*(volatile TimerControl *)(0x400940070))

#define TIMER0_COUNT (*(volatile uint32_t *)(0x40004008))
#define TIMER1_COUNT (*(volatile uint32_t *)(0x40008008))
#define TIMER2_COUNT (*(volatile uint32_t *)(0x40090008))
#define TIMER3_COUNT (*(volatile uint32_t *)(0x40094008))

#define TIMER0_PRESCALE (*(volatile uint32_t *)(0x4000400C))
#define TIMER1_PRESCALE (*(volatile uint32_t *)(0x4000800C))
#define TIMER2_PRESCALE (*(volatile uint32_t *)(0x4009000C))
#define TIMER3_PRESCALE (*(volatile uint32_t *)(0x4009400C))

#define TIMER0_PRESCALE_COUNT (*(volatile uint32_t *)(0x40004010))
#define TIMER1_PRESCALE_COUNT (*(volatile uint32_t *)(0x40008010))
#define TIMER2_PRESCALE_COUNT (*(volatile uint32_t *)(0x40090010))
#define TIMER3_PRESCALE_COUNT (*(volatile uint32_t *)(0x40094010))

#define TIMER0_MATCH0 (*(volatile uint32_t *)(0x40004018))
#define TIMER1_MATCH0 (*(volatile uint32_t *)(0x40008018))
#define TIMER2_MATCH0 (*(volatile uint32_t *)(0x40090018))
#define TIMER3_MATCH0 (*(volatile uint32_t *)(0x40094018))

#define TIMER0_MATCH1 (*(volatile uint32_t *)(0x4000401C))
#define TIMER1_MATCH1 (*(volatile uint32_t *)(0x4000801C))
#define TIMER2_MATCH1 (*(volatile uint32_t *)(0x4009001C))
#define TIMER3_MATCH1 (*(volatile uint32_t *)(0x4009401C))

#define TIMER0_MATCH2 (*(volatile uint32_t *)(0x40004020))
#define TIMER1_MATCH2 (*(volatile uint32_t *)(0x40008020))
#define TIMER2_MATCH2 (*(volatile uint32_t *)(0x40090020))
#define TIMER3_MATCH2 (*(volatile uint32_t *)(0x40094020))

#define TIMER0_MATCH3 (*(volatile uint32_t *)(0x40004024))
#define TIMER1_MATCH3 (*(volatile uint32_t *)(0x40008024))
#define TIMER2_MATCH3 (*(volatile uint32_t *)(0x40090024))
#define TIMER3_MATCH3 (*(volatile uint32_t *)(0x40094024))

typedef struct{
    unsigned  interrupt0    : 1;
    unsigned  reset0        : 1;
    unsigned  stop0         : 1;
    unsigned  interrupt1    : 1;
    unsigned  reset1        : 1;
    unsigned  stop1         : 1;
    unsigned  interrupt2    : 1;
    unsigned  reset2        : 1;
    unsigned  stop2         : 1;
    unsigned  interrupt3    : 1;
    unsigned  reset3        : 1;
    unsigned  stop3         : 1;
    unsigned                :20;
}TimerMatchControl;

#define TIMER0_MATCH_CTL (*(volatile TimerMatchControl *)(0x40004014))
#define TIMER1_MATCH_CTL (*(volatile TimerMatchControl *)(0x40008014))
#define TIMER2_MATCH_CTL (*(volatile TimerMatchControl *)(0x40090014))
#define TIMER3_MATCH_CTL (*(volatile TimerMatchControl *)(0x40094014))


typedef struct{
    unsigned  rising0       : 1;
    unsigned  falling0      : 1;
    unsigned  interrupt0    : 1;
    unsigned  rising1       : 1;
    unsigned  falling1      : 1;
    unsigned  interrupt     : 1;
    unsigned                :26;
}TimerCaptureControl;

#define TIMER0_CAPTURE_CTL (*(volatile TimerCaptureControl *)(0x40004028))
#define TIMER1_CAPTURE_CTL (*(volatile TimerCaptureControl *)(0x40008028))
#define TIMER2_CAPTURE_CTL (*(volatile TimerCaptureControl *)(0x40090028))
#define TIMER3_CAPTURE_CTL (*(volatile TimerCaptureControl *)(0x40094028))

typedef struct{
    unsigned  em0          : 1;
    unsigned  em1          : 1;
    unsigned  em2          : 1;
    unsigned  em3          : 1;
    unsigned  mode0        : 2;
    unsigned  mode1        : 2;
    unsigned  mode2        : 2;
    unsigned  mode3        : 2;
    unsigned               : 4;
}TimerExternalMatchControl;

#define TIMER0_EXT_MATCH_CTL (*(volatile TimerExternalMatchControl *)(0x4000403C))
#define TIMER1_EXT_MATCH_CTL (*(volatile TimerExternalMatchControl *)(0x4000803C))
#define TIMER2_EXT_MATCH_CTL (*(volatile TimerExternalMatchControl *)(0x4009003C))
#define TIMER3_EXT_MATCH_CTL (*(volatile TimerExternalMatchControl *)(0x4009403C))



#endif //__HWDEF_TIMER_H

