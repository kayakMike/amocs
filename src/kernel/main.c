#include "system.h"
#include "string.h"
#include "color.h"

void util_sleep(uint32_t msec){
    uint32_t i=120000*msec;
    while(i--){
        //noop??
    }
}

void output_system_stats(void){
    uint32_t core_clock_speed=system_core_clock();
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    uart0_send("BASIC SYSTEM STATS! \n\r");
    uart0_send("    System CPU Clock:  ");
    uint_to_decimal_string(core_clock_speed,str);
    uart0_send(str);
    uart0_send(" ");
    uint_to_hex_string(core_clock_speed,str);
    uart0_send(str);
    uart0_send("\n\r");
}

void main00(void){
    while(true){
        uart0_send("main00! \n\r");
    }
}

void main01(void){
    while(true){
        uart0_send("main01! \n\r");
    }
}

void main02(void){
    while(true){
        uart0_send("main02! \n\r");
    }
}

void main03(void){


//    util_sleep(2);
//    nrz0_enable();

    uint8_t msg[15]={0x00,0x00,0x00, 
                     0x00,0xFF,0x00, 
                     0x00,0x00,0xFF, 
                     0xFF,0x00,0xFF,
                     0x00,0xFF,0xFF};
    uint8_t i=0;
    RGBColor pix;
    
    while(true){
        uart0_send("main03! \n\r");
        gpio_toggle();
        pix=hsvtorgb(i+  0,255, 25);
        msg[ 0]=pix.grn;
        msg[ 1]=pix.red;
        msg[ 2]=pix.blu;
        pix=hsvtorgb(i+ 64,255, 25);
        msg[ 3]=pix.grn;
        msg[ 4]=pix.red;
        msg[ 5]=pix.blu;
        pix=hsvtorgb(i+128,255, 25);
        msg[ 6]=pix.grn;
        msg[ 7]=pix.red;
        msg[ 8]=pix.blu;
        pix=hsvtorgb(i+192,255, 25);
        msg[ 9]=pix.grn;
        msg[10]=pix.red;
        msg[11]=pix.blu;
        pix=hsvtorgb(i ,255, 25);
        msg[12]=pix.grn;
        msg[13]=pix.red;
        msg[14]=pix.blu;
        nrz0_send_message(msg,15);
        i++;
    }
}

