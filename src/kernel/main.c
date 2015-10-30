#include "micro_types.h"
#include "system.h"
#include "utf8.h"
#include "string.h"
#include "crc.h"
#include "neopixel.h"

void util_sleep(uint32_t msec){
    uint32_t i=400000*msec;
    while(i--){
        //noop
    }
}

void main00(void){
    uint32_t i=0;
    while(true){
        util_sleep(100);
        i++;
    }
}

void main01(void){
    uint32_t i=0x42;
    UTF8Encode des;
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    while(true){
        uart0_send("-->--> main01 ");
        des=utf8_encode(i);
        uint_to_string(i,HEX,16,str);
        uart0_send(str);
        uart0_send("  |  ");
        send_message(des.bytes,des.count); 
        uart0_send("   -->\n");
        util_sleep(200);
        i++;
    }
}

void main02(void){
    while(true){
        crc16_init();
        crc7_init();
        dump_crc7Table();
        uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0";
        uint8_t msg[]="Hello Me Myself and I";
        uart0_send(msg);
        uart0_send("\n------------------\n");
        uint8_t i;  
        for(i=0;msg[i]!='\0';i++){
            uint_to_string(msg[i],HEX,1,str);
            uart0_send(str);
            uart0_send(" ");
        }
        uart0_send("\n-----------------------------\n");
        uart0_send("String is ");
        uint_to_string(i,DECIMAL,1,str);
        uart0_send(str);
        uart0_send(" bytes long");
        uart0_send("\n-----------------------------\n");
        uint8_t crc7=crc_compute_crc7(0,msg,i);
        uint_to_string(crc7,HEX,1,str);
        uart0_send("crc7 :");
        uart0_send(str);
        uart0_send("\n");
        uart0_send("\n-----------------------------\n");
        uint16_t crc16=crc_ccitt(msg,i);
        uint_to_string(crc16,HEX,2,str);
        uart0_send("crc16 : ");
        uart0_send(str);
        uart0_send("\n");

        util_sleep(10000);
    }
}

void main03(void){

//  neopix_startDemo();
    while(true){
        gpio_toggle();
        uart0_send("NEOPIXEL TEST! ");
//        neopix_computeFrame();
        util_sleep(10);
    }
}

