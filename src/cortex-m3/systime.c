#include "systime.h"
#include "syscontrol.h"
#include "systick.h"
#include "thread.h"
#include "blink.h"


volatile uint32_t sys_count=0;
volatile SoftTimer *swtimers[MAX_TIMERS];
volatile uint32_t systick_uptime=0;


void isr_sysTick(void){
    sys_count++;
    thread_triggerContextSwitch();
}

void systime_initialize(void){
    SYSTICK_CONTROL.clock_source_select =1;
    SYSTICK_CURRENT_VALUE.counter_value =(16000000-1);
    SYSTICK_RELOAD_VALUE.counter_value  =(16000000-1);
    SYSTICK_CONTROL.interrupt_enable    =1;
//    SYSTEM_INTERRUPT_PRIORITY.sysTick   =0xFF; //lowest priority
    SYSTICK_CONTROL.counter_enable      =1;
}

uint32_t systime_getSystemCount(void){
    return sys_count;
}

uint32_t systime_getTimerCount(void){
    return SYSTICK_CURRENT_VALUE.counter_value;
}

void systime_stopCounter(void){
    SYSTICK_CONTROL.counter_enable      =0;
}

void systime_startCounter(void){
    SYSTICK_CONTROL.counter_enable      =1;
}

void systime_resetTimer(void){
    SYSTICK_CURRENT_VALUE.counter_value =SYSTICK_RELOAD_VALUE.counter_value;
}

void systime_resetCounter(void){
    sys_count=0;
}

uint8_t systime_createSWtimer(SoftTimer *timer){
    uint8_t i=0;
    timer->end=systick_uptime+(timer->period);
    //put pointer in the first
    while(swtimers[i]!=NULL){
        i++;
    }
    if(i<MAX_TIMERS){
        swtimers[i]=timer;
        return 1;
    }
    return 0;
}


uint8_t systime_deleteSWtimer(SoftTimer *timer){
    uint8_t i=0;
    for(i=0;i<MAX_TIMERS;i++){
        if(swtimers[i]==timer){
            swtimers[i]=NULL;
        }
    }
}

void systime_evaluateSWtimers(void){
    uint8_t i=0;
    while(i<MAX_TIMERS){
        if((swtimers[i]!=NULL)&&(swtimers[i]->end==systick_uptime)){
            (*(swtimers[i]->callback))(swtimers[i]->arg);
            swtimers[i]=NULL;
        }
        i++;
    }
}


