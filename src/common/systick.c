#include "system.h"
#include "systick.h"
#include "process.h"

#define MAX_TIMERS  8
//some simple ideas...

volatile SoftTimer *swtimers[MAX_TIMERS];
volatile uint32_t systick_uptime=0;

void systick_evaluate_swtimers(void);

void isr_systick(void){
    systick_uptime++;
    systick_evaluate_swtimers();
    proc_request_context_switch();
}

void systick_initialize(void){
    SYSTICK_RELOAD_VALUE.bits.counterValue=(1200000-1);
    SYSTICK_CONTROL.bits.selectClockSource=1;
    SYSTICK_CONTROL.bits.enableIrq=1;
    SYSTICK_CONTROL.bits.enableCounter=1;
    SYSTICK_IRQ_PRIORITY=0x1F;
    //initialize swtimers array.
    uint8_t i=0;
    for(i=0;i<MAX_TIMERS;i++){
        swtimers[i]=NULL;
    }
}

uint32_t systick_return_uptime(void){
    return systick_uptime;
}


uint8_t systick_register_swtimer(SoftTimer *timer){
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

uint8_t systick_deregister_swtimer(SoftTimer *timer){
    uint8_t i=0;
    for(i=0;i<MAX_TIMERS;i++){
        if(swtimers[i]==timer){
            swtimers[i]=NULL;
        }
    }
}

void systick_evaluate_swtimers(void){
    uint8_t i=0;
    while(i<MAX_TIMERS){
        if((swtimers[i]!=NULL)&&(swtimers[i]->end==systick_uptime)){
            (*(swtimers[i]->callback))(swtimers[i]->arg);
            swtimers[i]=NULL;
        }
        i++;
    }
}
