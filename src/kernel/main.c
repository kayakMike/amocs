#include "micro_types.h"
#include "system.h"
#include "utf8.h"
#include "string.h"



void util_sleep(uint32_t msec){
    uint32_t i;
    for(i=0;i<(10000*msec);i++){
    }
}

void main00(void){
    uint32_t i=0;
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    while(true){
        util_sleep(100);
        i++;
    }
}

void main01(void){
    uint32_t i=0x42;
    UTF8Encode des;
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    while(true){
        uart0_send("-->--> main01 ");
        des=utf8_encode(i);
        uint_to_string(i,HEX,16,str);
        uart0_send(str);
        uart0_send("  |  ");
        send_message(des.bytes,des.count); 
        uart0_send("   -->\n");
        util_sleep(200);
        i++;
    }
}

void main02(void){
    while(true){
        gpio_toggle();
//        uart0_send("Hello World!!!\n");
        util_sleep(200);
    }
}

void main03(void){
    while(true){
        util_sleep(400);
    }
}


//uint8_t utf8Test[]="€";
//uint8_t utf8Test[]={0xc3,0xaf,0x00};
//uint8_t utf8Test[]={0xc3,0xb0,0x00};  //LATIN SMALL LETTER ETH
//uint8_t utf8Test[]={0xc3,0xb1,0x00};  //LATIN SMALL LETTER N WITH TILDE
//uint8_t utf8Test[]={0xf0,0x90,0x90,0x81}; // DESERET LONG O 𐐅
//uint8_t utf8Test[]="~"i𐐁𐐁𐐁 𐌰𐌰𐌡𐌡𐌀𐌀𐇡𐇡𐆗𐆗𐆠𐆠𐊀𐊀𐊺𐊺𐋈𐋈𐐁𐐅𐐅;
//uint8_t utf8Test[]="₠";


/*
uint32_t initializeStack(uint32_t origin, uint32_t entryFunction){
    uint32_t *stack=(uint32_t *)origin;
    stack=stack-16;
    //stack[18]=0 
    stack[16]=0x01000000;               //xPSR
    stack[15]=(uint32_t)entryFunction;  //PC
    stack[14]=(uint32_t)exitFunction;    //lr
    //   r12,r3,r2,r1,r0 --> index-5=8
    stack[8]=0xFFFFFFF9;                //execReturn
    //   r11-4           --> index-8=0
    return (uint32_t)stack;
*/
