#include "hd44780.h"
#include "types.h"
#include "lpc8xx.h"

//uint8_t get_bit(uint8_t byte, uint8_t bit){
//    uint8_t res = (byte >> bit) & 0x01;
//    return res; 
//}


void lcd_wait(uint32_t time){
    while(time){
        time--;
    }
}

void send_byte(uint8_t byte){

    

}

