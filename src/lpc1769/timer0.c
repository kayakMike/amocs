#include "system.h"
#include "micro_types.h"
#include "hwdef_timer.h"
#include "hwdef_gpio.h"
#include "hwdef_nvic.h"


void Timer0_Handler(void){
    
    if(PORT1_VAL.pin27==1){
        PORT1_CLR.pin27=1;
    }
    else{
        PORT1_SET.pin27=1;
    }
    TIMER0_INTERRUPT.match0=1;

}

void Timer0_Initialize(void){
    TIMER0_INTERRUPT.match0=1;
    TIMER0_MATCH0=15000000;
    TIMER0_PRESCALE=0;

    TIMER0_MATCH_CTL.interrupt0=1;
    TIMER0_MATCH_CTL.reset0=1;
    
    NVIC_SET_ENABLE.timer0=1;
    NVIC_CLEAR_PENDING.timer0=1;

    TIMER0_CTL.enable=1;
    TIMER0_CTL.reset=1;
    TIMER0_CTL.reset=0;
    
    PORT1_SET.pin27=1;
}

