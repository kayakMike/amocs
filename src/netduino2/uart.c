#include "micro_types.h"
#include "uart0.h"
//for Netduino USART1:  0x4001 1000 - 0x4001 13FF
#define USART1_DATA    (*(uint32_t *)(0x40011004))
#define USART1_FLAG    (*(uint32_t *)(0x40011000))


void uart0_send(char *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
//        while(USART1_FLAG & 0x0){
            //spin until USART1 is not busy anymore
//        }
        USART1_DATA=msg[i];
    }    
}

