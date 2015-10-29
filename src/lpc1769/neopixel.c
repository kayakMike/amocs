#include "hwdef_timer.h"
#include "hwdef_nvic.h"
#include "hwdef_pinsel.h"
#include "neopixel.h"
#include "hwdef_gpio.h"


#define PIXEL_COUNT    4
#define ARRAY_SIZE  (PIXEL_COUNT * 3)
#define FRAME_SIZE  (PIXEL_COUNT * 3 * 8)
#define NRZ_ONE    200000
#define NRZ_ZERO   100000
#define NRZ_PERIOD 300000
#define REFRESH    4000000

//GLOBALS!!!
uint8_t pixelData[ARRAY_SIZE];
uint8_t frameRecomputeFlag=0;
uint32_t frame[FRAME_SIZE];
uint32_t frameIndex=0;
uint32_t frameReady=0;
uint32_t change=0;

void Timer0_Handler(void){
    //  void *id;
    //  format_printm(&id,"TimerHandler : Checking IN!");
    //  format_apply(id);
    //  set match 0 enable, and clear on match 
    TIMER0_INTERRUPT.match0=1;
    TIMER0_EXT_MATCH_CTL.em0=1;
    TIMER0_EXT_MATCH_CTL.mode0=1;
    //set match0 and match1 counter
    TIMER0_MATCH0=frame[frameIndex];
    TIMER0_MATCH1=NRZ_PERIOD;
    frameIndex++;
    if(frameIndex>=FRAME_SIZE){   //24
        //wait a long time before the next refresh
        TIMER0_MATCH1=REFRESH;
        frameIndex=0;
        frameRecomputeFlag=1;
    }

}

void neopix_initializeDemo(void){
    //set port 1_16 to T0_MATCH0 <---------this works!
    PINSEL3.p128=3;
    PINMODE3.p128=2;
   
    FIO3DIR.pin29=1; 
    FIO3SET.pin29=1;

    uint32_t i;
    for(i=0;i<FRAME_SIZE;i++){
        frame[i]==NRZ_ONE;
    }
    //enable interrupt for TIMER0 <---This ALSO works!
    NVIC_SET_ENABLE.timer0=1;
    NVIC_CLEAR_PENDING.timer0=1;

    TIMER0_MATCH_CTL.interrupt0=1;
    TIMER0_MATCH_CTL.reset0=1;
    
    TIMER0_EXT_MATCH_CTL.em0=1;
    TIMER0_EXT_MATCH_CTL.mode0=1;
}

void neopix_startDemo(void){
    TIMER0_MATCH1=REFRESH;
    TIMER0_CTL.reset=1; 
    TIMER0_CTL.enable=1; 
    TIMER0_CTL.reset=0; 
}

void neopix_stopDemo(void){
    TIMER0_CTL.enable=0;
}

void neopix_computeFrame(void){
    uint32_t index=0;
    uint8_t div=0;
    uint8_t pos=0;
    uint8_t bit=0;
    if(frameRecomputeFlag==1){
        neopix_changePixels();
        for(index=0; index<FRAME_SIZE; index++){    
            div=index/8; 
            pos=7-(index%8);
            bit=(pixelData[div] >> pos) & 0x01; 
            if(bit){
                frame[index]=NRZ_ONE;
            }
            else{ 
                frame[index]=NRZ_ZERO;
            }
        }
        frameRecomputeFlag=0;
    }
}

void neopix_setPixelRgb(uint32_t pixIndex, uint8_t red, uint8_t grn, uint8_t blu){
    uint32_t pix=pixIndex*3;
    pixelData[pix]=grn;
    pixelData[pix+1]=red;
    pixelData[pix+2]=blu;
}

uint8_t *neopix_getPixel(uint32_t pixIndex){
    return pixelData+(pixIndex*3);
}

void neopix_changePixels(void){
    neopix_setPixelRgb(0,255,  0,  0);
    neopix_setPixelRgb(1,  0,255,  0);
    neopix_setPixelRgb(2,  0,  0,255);
    neopix_setPixelRgb(3,  change,  change,  change);
    change++; 
}

