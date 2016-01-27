#ifndef __SYSTIME_H
#define __SYSTIME_H
#include "micro_types.h"

#define MAX_TIMERS 8 

void     isr_sysTick             (void);
void     systime_initialize      (void);
uint32_t systime_getSystemCount  (void);
uint32_t systime_getTimerCount   (void);
void     systime_stopCounter     (void);
void     systime_startCounter    (void);
void     systime_resetTimer      (void);
void     systime_resetCounter    (void);


//systick
typedef struct SoftTimer{
    uint32_t period;
    uint32_t end;
    void *arg;
    void (*callback)(void *arg);
}SoftTimer;

uint8_t  systime_createSWtimer    (SoftTimer *timer);
uint8_t  systime_deleteSWtimer    (SoftTimer *timer);
void     systime_evaluateSWtimers (void);

#endif //__SYSTIME_H

