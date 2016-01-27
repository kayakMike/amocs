#include "micro_types.h"
#include "system.h"
//for Stellaris
#define UART0_DATA    (*(volatile uint32_t *)(0x4000C000))
#define UART0_FLAG    (*(volatile uint32_t *)(0x4000C018))

void uart0_send(char *msg){
    uint32_t i=0;
    while(msg[i]!=0x00){
        while(UART0_FLAG & 0x0){
            //spin until UART0 is not busy anymore
        }
        UART0_DATA=msg[i];
        i++;
    }    
}

//better
void uart0_send_message(uint8_t *msg, uint32_t len){
    while(len){
        if(UART0_FLAG & 0x0){
            UART0_DATA=*msg;
            msg++;
            len--;
        }
    }
}



void uart0_initialize(void){}
