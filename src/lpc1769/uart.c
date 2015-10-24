#include "micro_types.h"
#include "uart0.h"
#define UART0_DATA    (*(uint32_t *)(0x4000C000))
#define UART0_FLAG    (*(uint32_t *)(0x40011000))


void uart0_send(char *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
        while(UART0_FLAG & 0x0){
            //spin until UART0 is not busy anymore
        }
        UART0_DATA=msg[i];
    }    
}

void send_message(uint8_t *message, uint32_t count){
    uint32_t index=0;
    while(index<count){
        if(UART0_FLAG){
            UART0_DATA=message[index];
            index++;
        }
    }
}
