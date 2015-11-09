#include "system.h"
#include "micro_types.h"
#include "hwdef_clock.h"
#include "hwdef_timer.h"
#include "hwdef_nvic.h"
#include "hwdef_pinmx.h"


//#define NRZ_MAX     (4*3*8)
#define NRZ_MAX         120
#define NRZ_ONE         200 
#define NRZ_ZERO        100 
#define NRZ_PERIOD      300 
#define NRZ_PAUSE       120000

//bytes to be transfered
//index to the current bit
volatile uint32_t nrz_index;
volatile uint32_t nrz_values[NRZ_MAX];

volatile uint8_t nrz_lock=false;
volatile uint8_t xmit_complete=false;


void Timer0_Handler(void){
    TIMER0_INTERRUPT.match1=1; 
    TIMER0_EXT_MATCH_CTL.em0=1;
    if(xmit_complete){
        nrz_lock=false;
        NVIC_SET_ENABLE.timer0=0;
        NVIC_CLR_PENDING.timer0=0;
        TIMER0_CTL.enable=0;
    }
    else{
        TIMER0_MATCH0=nrz_values[nrz_index];
        nrz_index++;
        if(nrz_index>NRZ_MAX){
            TIMER0_MATCH1=NRZ_PAUSE;
            xmit_complete=true;
            nrz_index=0;
        }
        else{
            TIMER0_MATCH1=NRZ_PERIOD;
        }
    }
}

void nrz0_enable(void){
    NVIC_SET_ENABLE.timer0=1;
    NVIC_CLR_PENDING.timer0=1;
    TIMER0_CTL.enable=1;
    TIMER1_CTL.reset=0;
}


void nrz0_disable(void){
    while(xmit_complete==false){};
    TIMER0_MATCH1=NRZ_PAUSE;
    NVIC_SET_ENABLE.timer0=0;
    NVIC_CLR_PENDING.timer0=0;
    TIMER0_CTL.enable=0;
    TIMER0_CTL.reset=0;
}


void nrz0_send_message(uint8_t *in, uint32_t len){
    uint8_t byte=0;
    uint8_t bit=0;
    uint8_t i=0;;
    nrz0_disable();
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
    xmit_complete=false;
    nrz0_enable();
}



void Timer0_Initialize(void){
    PERIPHERAL_CLOCK_SEL0.timer0=1;

    TIMER0_PRESCALE=0;
    
    TIMER0_EXT_MATCH_CTL.em0=1;
    TIMER0_EXT_MATCH_CTL.mode0=1;
   
    TIMER0_MATCH1=NRZ_PAUSE;
    TIMER0_INTERRUPT.match1=1; 
    TIMER0_MATCH_CTL.interrupt1=1;
    TIMER0_MATCH_CTL.reset1=1;
   
    PIN_FUNC.p3_25=2;

    //calculate_nrz();
}

