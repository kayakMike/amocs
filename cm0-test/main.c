#include "types.h"
#include "lpc8xx.h"
#include "hd44780.h"

void simple_delay(uint32_t delay);
void assembly_blink(void);
uint32_t translate_number(uint32_t num);

uint8_t tbl[32];
void init_lookup_table(void);
void setup_xtal_oscillator(void);

int main() {

    SYSTEM_CLOCK_CONTROL.iocon = 1;
    PIO0_08.mode = 0x00;
    PIO0_09.mode = 0x00;
    SYSTEM_CLOCK_CONTROL.iocon = 0;

    PIN_ENABLE.xtalin  = 0;
    PIN_ENABLE.xtalout = 0;

    POWER_CONFIGURATION_REGISTER.xtal_osc = 0; //powers up the oscillator!
    simple_delay(10000);
    
    SYSTEM_OSCILLATOR_CONTROL.bypass = 0;
    SYSTEM_OSCILLATOR_CONTROL.frequency_range = 0;
   
    CLOCK_OUT_SELECT.select = 0x01; // 0x0 IRC 0x1 XTAL 0x2 Watchdog 0x3 Main
    CLOCK_OUT_UPDATE_ENABLE.update = 0x00;
    CLOCK_OUT_UPDATE_ENABLE.update = 0x01;
    CLOCK_OUT_DIVIDER = 4;
    PIN_ASSIGN_11.clockout_o = 0x1C;  // 1C is 28

    lcd_init();

//    init_lookup_table();
//    uint32_t i = 0;
//    for(i = 0; i < 16; i++){
//        PORT0_DIR = PORT0_DIR | (1 << tbl[i]);
//    }
//    i = 0;
//    uint32_t out = 0;
//    uint32_t num = 0;
//    uint8_t fwd  = 1;
//    PORT0_DIR = PORT0_DIR | (1<< 28);
    while(TRUE){
/*        out = translate_number(num);
        PORT0_VAL = out;
        simple_delay(16000);
        PORT0_NOT = PORT0_NOT |(1<< 28);
        simple_delay(16000);
        if( fwd == 1){
            i++;
        }
        else{
            i--;
        }
        num = 1 << i;
        if(i == 15){
            fwd = 0;
        }
        if(i == 0){
            fwd = 1;
        }
*/
    }
    return 0;
}

void init_lookup_table(void){
    tbl[0]  =  15;
    tbl[1]  =   8;  //6
    tbl[2]  =   9;  //7
    tbl[3]  =  12;
    tbl[4]  =  13;
    tbl[5]  =  14;
    tbl[6]  =  23;
    tbl[7]  =  22;
    tbl[8]  =  21;
    tbl[9]  =  20;
    tbl[10] =   1;
    tbl[11] =  18;
    tbl[12] =  19;
    tbl[13] =  26;
    tbl[14] =  24;
    tbl[15] =  25;
}

uint32_t translate_number(uint32_t num){
    uint32_t out = 0;
    uint32_t bit = 0;
    for(uint8_t i = 0; i < 16; i++){
        bit = ((num >> i) & 0x01);
        if(bit == 0x01){
            out = out | (1 << tbl[i]);
        }
    }
    return out;
}

void simple_delay(uint32_t delay){

    while(delay){
        delay--;
    }

}



void assembly_blink(void){
    uint8_t delay = 200; 
    asm volatile(
    "    ldr r1, .port0not             \n" 
    "    ldr r2, .pin27                \n"
    ".main:                            \n"
    "    str r1, [r2]                  \n"  //one?
    "    movs r3, #200                 \n"
    ".dloop:                           \n"
    "    sub   r3, r3, #1              \n"
    "    bne .dloop                    \n"  //branching takes 2 clocks
    "    b .main                       \n"  //branching takes 2 clocks
    ".align 4                          \n"  //seemed to be necessary
    ".port0not:                        \n"
    "    .word 134217728               \n"  // value is 0xA0002300
    ".pin27:                           \n"  
    "    .word 2684363520              \n"  // value is (1<<27)
    :
    : [delay] "r" (delay)
    :
    );


}


        //basic counting:
        //i++;
        //if(i > 65536){
        //    i = 0;
        //}
        //num = i;
        //one way scan
        //i++;
        //if(i > 15){
        //    i = 0;
        //}
        //num = 1 << i;
        //two way scan
   /* typedef struct pin_027_reg {
        unsigned                       : 3;
        unsigned mode                  : 2;
        unsigned hysteresis            : 1;
        unsigned invert                : 1;
        unsigned                       : 3;
        unsigned open_drain            :10; 
        unsigned s_mode                : 2;
        unsigned clk_divide            : 3;
        unsigned                       :16;
    }Pin_027_Reg; 
    #define PIN_027_REG (*(volatile Pin_027_Reg *)(0x40044054))
    */
/*#define PIN06 (1 <<  6)
#define PIN07 (1 <<  7)
#define PIN08 (1 <<  8)
#define PIN09 (1 <<  9)
#define PIN12 (1 << 12)
#define PIN13 (1 << 13)
#define PIN14 (1 << 14)
#define PIN23 (1 << 23)
#define PIN22 (1 << 22)
#define PIN21 (1 << 21)
#define PIN20 (1 << 20)
#define PIN18 (1 << 18)
#define PIN19 (1 << 19)
#define PIN28 (1 << 28)
#define PIN27 (1 << 27)
*/
