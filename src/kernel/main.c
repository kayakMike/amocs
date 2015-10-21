#include "micro_types.h"
#include "uart0.h"
#include "utf8.h"
#include "string.h"

//struct Stack{

    /*   ProgramStatusRegister
    *    ProgramCounter
    *    LinkRegister
    *    StackPointer
    *    r12 - r0
    */
//} 


void util_sleep(uint32_t msec){
    uint32_t i;
    for(i=0;i<(100000*msec);i++){
    }
}


void main01(void){
    while(true){
        uart0_send("main01 send message to UART\n");
        util_sleep(100);
    }
}

void main02(void){
    while(true){
        uart0_send("main02 send message to UART\n");
        util_sleep(100);
    }
}

void main03(void){
    while(true){
        uart0_send("main03 send message to UART\n");
        util_sleep(100);
    }
}

int main00(void){
    char message[]=      "New Hello World! \n";
    char string_buffer[]="------------";
    uint32_t i=0;
    uint32_t counter=0x10405; 
    send_message(message,18);
    UTF8Encode utf8Test;
    while(1){
        uart0_send("Begin character");
        utf8Test=utf8_encode(counter);
        for(i=0;i<utf8Test.count;i++){
            uint8_to_hexstring(utf8Test.bytes[i],string_buffer);
            uart0_send(" ");
            uart0_send(string_buffer);
            uart0_send(" ");
        }
        uart0_send(" ");
        send_message(utf8Test.bytes,utf8Test.count);
        uart0_send(" ");
        uint32_to_hexstring(counter,string_buffer);
        uart0_send(string_buffer);
        uart0_send(" end of line \n");
        counter++;
        util_sleep(100);
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
}

    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t SP;
    uint32_t LR;
    uint32_t PC;
    uint32_t xPSR;
*/

