#include "micro_types.h"
#include "uart0.h"
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



void send_message(uint8_t *message, uint32_t count){
    uint32_t index=0;
    while(index<count){
        while(UART0_FLAG & 0x0){
            //spin until UART0 is not busy anymore
        }
        UART0_DATA=message[index];
        index++;
    }
}
