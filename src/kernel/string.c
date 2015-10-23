#include "string.h"

//  "０１２３４５６７８９ＡＢＣＤＥＦ"


uint8_t uint_to_string(uint32_t in, uint8_t base, uint8_t max, uint8_t *bytes){

    uint8_t symbols[]="0123456789ABCDEF";
    uint32_t div=0x10000000;
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


