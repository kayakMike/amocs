#include "micro_types.h"
#include "system.h"
#include "utf8.h"
#include "string.h"
#include "crc.h"

uint16_t crcTable[256];
uint8_t crc7Table[256];

//good for CRC16 bit polys
void crc16_init(void){
    uint16_t res=0;
    uint16_t div=0;
    uint8_t i; 

    for(div=0;div<256;++div){
        res=div<<8;
        for(i=8;i>0;--i){
            if(res&(0x8000)){
                res=(res<<1)^0x1021;
            }
            else{
                res=(res<<1);
            }
        }
    }
}


void crc7_init(void){
    uint16_t res=0;
    uint16_t div=0;
    uint8_t i; 

    for(div=0;div<256;++div){
        res=div;
        for(i=8;i>0;--i){
            if(res&0x80){
                res=(res<<1)^0x89;
            }
            else{
                res=(res<<1);
            }
        }
        crc7Table[div]=res;
    }
}

void dump_crc7Table(void){
    uint32_t i,j;
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    for(j=0;j<32;j++){
        for(i=0;i<8;i++){
            uint_to_string(crc7Table[i+(8*j)],HEX,1,str);
            uart0_send("0x");
            uart0_send(str);
            uart0_send(", ");
        }
        uart0_send("\n");
    }
}

void dump_crcTable(void){
    uint32_t i,j;
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    for(j=0;j<32;j++){
        for(i=0;i<8;i++){
            uint_to_string(crcTable[i+(8*j)],HEX,2,str);
            uart0_send("0x");
            uart0_send(str);
            uart0_send(", ");
        }
        uart0_send("\n");
    }
}

uint16_t crc_ccitt(uint8_t *msg, uint32_t len){
    uint32_t i;
    uint8_t j;
    uint16_t res=0x0000;

    for(i=0;i<len;i++){
        j=msg[i]^(res>>8);
        res=crcTable[j]^(res<<8);
    }
    return res;
}

uint8_t crc7(uint8_t *msg, uint32_t len){
    uint32_t i;
    uint8_t j;
    uint8_t res=0;

    for(i=0;i<len;i++){
        j=msg[i]^(res);
        res=crc7Table[j]^res;
    }
    return res;
}




void util_sleep(uint32_t msec){
    uint32_t i=400000*msec;
    while(i--){
        //noop
    }
}

void main00(void){
    uint32_t i=0;
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
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
//      gpio_toggle();
//      uart0_send("Hello World!!!\n");
        crc16_init();
        crc7_init();
        dump_crc7Table();
//        dump_crcTable();

        uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0";
        uint8_t msg[]="Great Googly moggly!!!";
    
        uart0_send(msg);
        uart0_send("\n------------------\n");
        uint8_t i;  
        for(i=0;msg[i]!='\0';i++){
            uint_to_string(msg[i],HEX,1,str);
            uart0_send(str);
            uart0_send(" ");
        }
        //uint16_t crc=crc_compute_ccitt(0xFFFF,msg,12);
        uart0_send("\n-----------------------------\n");
        uart0_send("String is ");
        uint_to_string(i,DECIMAL,1,str);
        uart0_send(str);
        uart0_send(" bytes long");
        uart0_send("\n-----------------------------\n");
        
        uint8_t crc=crc7(msg,i);
        uint_to_string(crc,HEX,1,str);
        uart0_send("crc7 : ");
        uart0_send(str);
        uart0_send("\n");
        util_sleep(20000);
    }
}

void main03(void){
    while(true){
        gpio_toggle();
        uart0_send("HELLO WORLD ");
        util_sleep(1);
        uart0_send(" YAH!!!! HELLO WORLD ");
    }
}


//48 65 6C 6C 6F 20 57 6F 72 6C 64 00
//uint8_t utf8Test[]="€";
//uint8_t utf8Test[]={0xc3,0xaf,0x00};
//uint8_t utf8Test[]={0xc3,0xb0,0x00};  //LATIN SMALL LETTER ETH
//uint8_t utf8Test[]={0xc3,0xb1,0x00};  //LATIN SMALL LETTER N WITH TILDE
//uint8_t utf8Test[]={0xf0,0x90,0x90,0x81}; // DESERET LONG O 𐐅
//uint8_t utf8Test[]="~"i𐐁𐐁𐐁 𐌰𐌰𐌡𐌡𐌀𐌀𐇡𐇡𐆗𐆗𐆠𐆠𐊀𐊀𐊺𐊺𐋈𐋈𐐁𐐅𐐅;
//uint8_t utf8Test[]="₠";


/*
 *  48 65 6C 6C 6F 20 57 6F 72 6C 64
 *
uint32_t initializeStack(uint32_t origin, uint32_t entryFunction){
    uint32_t *stack=(uint32_t *)origin;
    stack=stack-16;
    //stack[18]=0 
    stack[16]=0x01000000;               //xPSR
    stack[15]=(uint32_t)entryFunction;  //PC
    stack[14]=(uint32_t)exitFunction;    //lr
    //   r12,r3,r2,r1,r0 --> index-5=8
    stack[8]=0xFFFFFFF9;                //execReturn
    //   r11-4           --> index-8=0
    return (uint32_t)stack;
*/
