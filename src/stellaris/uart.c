#include "micro_types.h"
#include "uart0.h"
//for Stellaris
#define UART0_DATA    (*(uint32_t *)(0x4000C000))
#define UART0_FLAG    (*(uint32_t *)(0x4000C018))

void uart0_send(char *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
    //    while(UART0_FLAG & 0x0){
            //spin until UART0 is not busy anymore
            //
    //    }
        UART0_DATA=msg[i];
    }    
}

