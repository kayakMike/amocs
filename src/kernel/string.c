#include "string.h"


//  "０１２３４５６７８９ＡＢＣＤＥＦ"



uint8_t uint32_to_hexstring(uint32_t convert, uint8_t *bytes){
    char symbols[]="0123456789ABCDEF";
    uint8_t sym=0;
    uint8_t index=0;
    uint32_t div=0x10000000;
    while(div>0){
        sym=convert/div;
        convert=convert-(sym*div);  
        bytes[index]=symbols[sym];
        index++;
        div=div/0x10;
    }
    bytes[index]='\0'; 
    return index;
}

uint8_t uint8_to_hexstring(uint8_t convert, uint8_t *bytes){
    char symbols[]="0123456789ABCDEF";
    uint8_t sym=0;
    uint8_t index=0;
    uint32_t div=0x10;
    while(div>0){
        sym=convert/div;
        convert=convert-(sym*div);  
        bytes[index]=symbols[sym];
        index++;
        div=div/0x10;
    }
    bytes[index]='\0'; 
    return index;
}
