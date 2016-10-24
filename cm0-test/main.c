#include "types.h"

//from the lpc824 user manual 

#define PORT0_DIR (*(volatile uint32_t *)(0xA0002000))
#define PORT0_VAL (*(volatile uint32_t *)(0xA0002100))
#define PORT0_SET (*(volatile uint32_t *)(0xA0002200))
#define PORT0_CLR (*(volatile uint32_t *)(0xA0002280))
#define PORT0_NOT (*(volatile uint32_t *)(0xA0002300))

#define PIN06 (1 <<  6)
#define PIN07 (1 <<  7)
#define PIN08 (1 <<  8)
#define PIN09 (1 <<  9)
#define PIN14 (1 << 14)
#define PIN23 (1 << 23)
#define PIN22 (1 << 22)
#define PIN21 (1 << 21)
#define PIN20 (1 << 20)
#define PIN18 (1 << 18)
#define PIN19 (1 << 19)

void simple_delay(uint32_t delay);
void assembly_blink(void);
uint32_t translate_number(uint32_t num);

uint8_t tbl[32];
void init_lookup_table(void);

int main()
{
    //simplest micro controller program.
    //blink a gpio GPIO
    //PORT0_DIR = PORT0_DIR | PIN06 | PIN07 | PIN08 | PIN09 | PIN14 | PIN23;
    //PORT0_DIR = PORT0_DIR | PIN22 | PIN21 | PIN20 | PIN18 | PIN19 | PIN26;
    //PORT0_DIR = PORT0_DIR | PIN25 | PIN24 | PIN01 | PIN15 ; 
    init_lookup_table();
    uint32_t i = 0;
    for(i = 0; i < 16; i++){
        PORT0_DIR = PORT0_DIR | (1 << tbl[i]);
    }
    i = 0;
    uint32_t out = 0;
    uint32_t num = 0;
    uint8_t fwd  = 1;
    while(TRUE){
        out = translate_number(num);
        PORT0_VAL = out;
        simple_delay(16000);
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
    }
    return 0;
}
void init_lookup_table(void){
    tbl[0]  =   15;
    tbl[1]  =   6;
    tbl[2]  =   7;
    tbl[3]  =   8;
    tbl[4]  =   9;
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
