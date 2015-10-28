#include "string.h"

//  "０１２３４５６７８９ＡＢＣＤＥＦ"


uint8_t uint_to_string(uint32_t in, uint8_t base, uint8_t size, uint8_t *bytes){ 
    uint8_t symbols[]="0123456789ABCDEF";
    uint32_t div;
    switch (size){
        case 4:
            div=0x10000000;
            break;
        case 2:
            div=0x1000;
            break;
        case 1:
            div=0x10;
            break;
        default:
            div=0x10000000;
            break;
    }
    uint32_t sym=0;
    uint32_t index=0;
    while(div>0){
        sym=in/div;
        in=in-(sym*div);  
        bytes[index]=symbols[sym];
        index++;
        div=div/base;
    }
    bytes[index]='\0';
    return index;
}





/*
    uint8_t i=0; 
    for(i=0;msg[i]!='\0';i++){
        uint_to_string(msg[i],HEX,2,str);
        uart0_send(str);
        uart0_send(" ");
    }
*/
