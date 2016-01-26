#include "system.h"
#include "micro_types.h"
#include "clock.h"
#include "timer.h"
#include "nvic.h"
#include "pinmx.h"
#include "mutex.h"
//#include "string.h"

#define NRZ_MAX         (4*3*8) 
#define NRZ_ONE         200 
#define NRZ_ZERO        100 
#define NRZ_PERIOD      300
#define NRZ_PAUSE       1200000

//bytes to be transfered
//index to the current bit
volatile uint8_t nrz_index;
volatile uint16_t nrz_values[NRZ_MAX];
volatile uint8_t  nrz0_xmit_complete=true;
volatile uint8_t nrz0_mutex_lock=0;

//void nrz0_debug_output(void);

    
void isr_timer0(void){

    if(TIMER0_MATCH1==NRZ_PAUSE){
        TIMER0_CTL.enable=0;
        TIMER0_CTL.reset=0;
        nrz0_xmit_complete=true;
    }
    else if(nrz_index<NRZ_MAX){
        TIMER0_EXT_MATCH_CTL.em0=1;
        TIMER0_MATCH0=(uint32_t)nrz_values[nrz_index];
        TIMER0_MATCH1=NRZ_PERIOD;
        nrz_index++;
    }
    else if(nrz_index==NRZ_MAX){
        TIMER0_EXT_MATCH_CTL.em0=0;
        TIMER0_MATCH1=NRZ_PAUSE;
        nrz_index=0;
    }
    TIMER0_INTERRUPT.match1=1;
}

void nrz0_enable(void){
    nrz0_xmit_complete=false;
    TIMER0_MATCH1=NRZ_PERIOD;
    TIMER1_CTL.reset=0;
    TIMER0_CTL.enable=1;
}

void nrz0_disable(void){
    TIMER0_CTL.enable=0;
    TIMER0_CTL.reset=0;
}


//arrange bits into a bunch of 
void nrz0_send_message(uint8_t *in, uint32_t len){
    uint8_t byte=0;
    uint8_t bit=0;
    uint8_t i=0;
    //spin untill the previous message is transmintting
    while(nrz0_xmit_complete==false){};
    for(i=0;i<NRZ_MAX;i++){
        byte=i/8;
        bit=7-(i%8);
        if( (in[byte]>>bit) &0x01){
            nrz_values[i]=NRZ_ONE;
        }
        else{
            nrz_values[i]=NRZ_ZERO;
        }
    }
    nrz0_enable();
}

void nrz0_initialize(void){
    PERIPHERAL_CLOCK_SEL0.timer0=1;
    TIMER0_PRESCALE=0;
    TIMER0_EXT_MATCH_CTL.em0=1;
    TIMER0_EXT_MATCH_CTL.mode0=1;
    TIMER0_MATCH1=NRZ_PERIOD;
    TIMER0_INTERRUPT.match1=1; 
    TIMER0_MATCH_CTL.interrupt1=1;
    TIMER0_MATCH_CTL.reset1=1;
    PIN_FUNC.p3_25=2;
    NVIC_SET_ENABLE.timer0=1;
    NVIC_CLR_PENDING.timer0=1;
    TIMER0_CTL.enable=0;
    NVIC_PRIORITY_CTL.timer0=0x01;
}

/*
void nrz0_debug_output(void){ 
    uint8_t i; 
    uint8_t nrz[12];
    uint8_t num[12];
    
    for(i=0;i<NRZ_MAX;i++){
        uint_to_decimal_string(nrz_values[i],nrz);
        uint_to_decimal_string(i,num);
        uart0_send("index : ");
        uart0_send(num);
        uart0_send("value : ");
        uart0_send(nrz);
        uart0_send("\n\r");
    }

}
*/
