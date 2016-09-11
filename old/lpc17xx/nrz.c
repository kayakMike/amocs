#include "nrz.h"
#include "clock.h"
#include "timer.h"
#include "nvic.h"
#include "pinmx.h"
#include "mutex.h"

#define NRZ_MAX         (4*3*8)

//neo pixels:  
//   period:  1.25 microseconds
//   one   :  0.85 microseconds
//   zero  :  0.40 microseconds
//   timer is running at 120 MHZ
//   1.25 microseconds is (1.25e-6*120e6) is 150 clock cycles
//   0.85 microseconds is (0.85e-6*120e6) is 102 clock cycles
//   0.40 microseconds is (0.40e-6*120e6) is  48 clock cycles
#define NRZ_ONE         200 
#define NRZ_ZERO        100 
#define NRZ_PERIOD      300 
#define NRZ_PAUSE       12000

//bytes to be transfered
//index to the current bit
volatile uint8_t  nrz_index=0;
volatile uint32_t nrz_values[NRZ_MAX];
volatile uint8_t  nrz_xmit_complete=true;

void isr_timer0(void){

    if(TIMER0_MATCH1==NRZ_PAUSE){
        TIMER0_CTL.enable=0;
        TIMER0_CTL.reset=0;
        nrz_xmit_complete=true;
    }
    else if(nrz_index<NRZ_MAX){
        TIMER0_EXT_MATCH_CTL.em0=1;
        TIMER0_MATCH0=nrz_values[nrz_index];
        TIMER0_MATCH1=NRZ_PERIOD;
        nrz_index++;
    }
    else if(nrz_index==NRZ_MAX){
        TIMER0_MATCH1=NRZ_PAUSE;
        TIMER0_MATCH0=NRZ_ZERO;
    }
    TIMER0_INTERRUPT.match1=1;
}

void nrz_enable(void){
    nrz_index=0;
    nrz_xmit_complete=false;
    TIMER0_MATCH1=NRZ_PERIOD;
    TIMER1_CTL.reset=0;
    TIMER0_CTL.enable=1;
}

void nrz_disable(void){
    TIMER0_CTL.enable=0;
    TIMER0_CTL.reset=0;
}

//arrange bits into a bunch of 
void nrz_send_message(uint8_t *in, uint32_t len){
    uint8_t byte=0;
    uint8_t bit=0;
    uint8_t i=0;
    //spin untill the previous message is transmintting
    while(nrz_xmit_complete==false){
  
    };
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
    nrz_enable();
}

void nrz_initialize(void){
    PERIPHERAL_CLOCK_SEL0.timer0 =1;
    PIN_FUNC.p3_25               =2;
    NVIC_SET_ENABLE.timer0       =1;
    NVIC_CLR_PENDING.timer0      =1;

    // the priority of the timing on the isr is very critical because of the bit bang...
//    NVIC_PRIORITY_CTL.timer0     =0x00;

    TIMER0_PRESCALE              =0;
    TIMER0_EXT_MATCH_CTL.em0     =1;
    TIMER0_EXT_MATCH_CTL.mode0   =1;
    TIMER0_MATCH1                =NRZ_PERIOD;
    TIMER0_MATCH_CTL.interrupt1  =1;
    TIMER0_INTERRUPT.match1      =1; 
    
    TIMER0_CTL.enable            =0;
    TIMER0_MATCH_CTL.reset1      =1;
}


