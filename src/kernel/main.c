#include "micro_types.h"
#include "uart0.h"
#include "utf8.h"
#include "string.h"


uint8_t crc7_table[256];
//uint16_t crc16_table[256];

uint16_t crc16_table[256];
/* {
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
    0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
    0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
    0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
    0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
    0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
    0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
    0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
    0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
    0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
    0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
    0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
    0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
    0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
    0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
    0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
    0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
    0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
    0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
    0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
    0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
    0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
    0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
    0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
    0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
    0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
    0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
    0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
    0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
    0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};
*/

//this doesn't work!!!
void generate_crc16_table(void){
    uint32_t CRCPoly=0x18005; 
    uint32_t i;
    uint8_t j;
    for (i = 0; i < 256; i++){
        if(i&0x8000){
            crc16_table[i]=i^CRCPoly;
        }
        else{
            crc16_table[i]=i;
        }
        for(j = 0; j < 16; j++){
            crc16_table[i]=crc16_table[i]<<1;
            if(crc16_table[i] & 0x8000){
                crc16_table[i]=crc16_table[i]^CRCPoly;
            }
        }
    }
}

void generate_crc7_table(void){
    uint8_t CRCPoly = 0x89; 
    uint16_t i;
    uint8_t j;

    for (i = 0; i < 256; i++){
        //TERNARY EQUIVALENT:
        //crc7_table[i] = (i & 0x80) ? i ^ CRCPoly : i;
        if(i&0x80){
            crc7_table[i]=i^CRCPoly;
        }
        else{
            crc7_table[i]=i;
        }
        //end TERNARY EQUIVALENT
        for(j = 1; j < 8; j++){
            crc7_table[i]=crc7_table[i]<<1;
            if(crc7_table[i] & 0x80){
                crc7_table[i]=crc7_table[i]^CRCPoly;
            }
        }
        //seems that the crc table entry is always left shifted when used...
        crc7_table[i]=crc7_table[i]<<1;
    }
}

uint8_t compute_crc16(uint8_t crc, uint8_t *buffer, uint32_t len){
    while (len--){
        crc=crc16_table[crc ^ *buffer];
        buffer++;
    }
    return crc;
}

uint8_t compute_crc7(uint8_t crc, uint8_t *buffer, uint32_t len){
    while (len--){
        crc=crc7_table[crc ^ *buffer];
        buffer++;
    }
    return crc;
}

void util_sleep(uint32_t msec){
    uint32_t i;
    for(i=0;i<(100000*msec);i++){
    }
}

uint32_t util_array_length(uint8_t *array){
    uint32_t i=0;
    while(array[i]!='\0'){
        i++;
    }
    return i;
}

void dump_ascii_characters(uint8_t *msg,uint32_t count){
    uint8_t buffer[]="\0\0\0\0\0\0\0\0\0";
    while(count--){
        send_message(msg,1);
        uart0_send(" :");
        uint8_to_hexstring(*msg,buffer);
        uart0_send(" ");
        uart0_send(buffer);
        uart0_send("\n");
        msg++;
    }
}

void dump_uint8_hextable(uint8_t *table, uint32_t col, uint32_t row){
    uint8_t buffer[]="\0\0\0\0\0\0";
    uint32_t i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            uint8_to_hexstring((table[j+(i*col)]),buffer);
            uart0_send(" 0x");
            uart0_send(buffer);
            uart0_send(", ");
        }
        uart0_send("\n");
    }
}

void dump_uint16_hextable(uint16_t *table, uint32_t col, uint32_t row){
    uint8_t buffer[]="\0\0\0\0\0\0";
    uint32_t i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            uint16_to_hexstring((table[j+(i*col)]),buffer);
            uart0_send(" 0x");
            uart0_send(buffer);
            uart0_send(", ");
        }
        uart0_send("\n");
    }
}

void main00(void){
    generate_crc7_table();
    generate_crc16_table();
//    dump_uint8_hextable(crc7_table,8,32);
    uart0_send(" ---------------------------------\n");
    dump_uint16_hextable(crc16_table,8,32);
    uart0_send("\n---------------------------------\n");
    uint8_t buffer[]="\0\0\0\0\0\0";
    uint32_t i,j;
    uint8_t msg[]="Great Googly Moogly!!!!";
    uint32_t len=util_array_length(msg);    
    uint8_t crc_test=compute_crc7(0,msg,len);
    uint8_to_hexstring(crc_test,buffer);
    uart0_send("the CRC7 of |");
    uart0_send(msg);
    uart0_send("| is 0x");
    uart0_send(buffer);

    uart0_send(" and then shifted down: ");
    uint8_to_hexstring((crc_test>>1),buffer);
    uart0_send("| is 0x");
    uart0_send(buffer);
    uart0_send("\n");

//    dump_ascii_characters(msg,len);

    i=len;
    uint8_t *p=msg;
    while(i--){
        uint8_to_hexstring(*p,buffer);
        uart0_send(" ");
        uart0_send(buffer);
        p++;
    }
    uart0_send("\n");

    uart0_send("END OF PROGRAM\n");
    while(true){
    }
}

void main01(void){
    while(true){
//        uart0_send("main01 send message to UART\n");
        util_sleep(100);
    }
}

void main02(void){
    while(true){
//        uart0_send("main02 send message to UART\n");
        util_sleep(100);
    }
}

void main03(void){
    while(true){
//        uart0_send("main03 send message to UART\n");
        util_sleep(100);
    }
}

int main04(void){
    char message[]=      "New Hello World! \n";
    char string_buffer[]="------------";
    uint32_t i=0;
    uint32_t counter=0x10405; 
    send_message(message,18);
    UTF8Encode utf8Test;
    while(1){
        uart0_send("Begin character");
        utf8Test=utf8_encode(counter);
        for(i=0;i<utf8Test.count;i++){
            uint8_to_hexstring(utf8Test.bytes[i],string_buffer);
            uart0_send(" ");
            uart0_send(string_buffer);
            uart0_send(" ");
        }
        uart0_send(" ");
        send_message(utf8Test.bytes,utf8Test.count);
        uart0_send(" ");
        uint32_to_hexstring(counter,string_buffer);
        uart0_send(string_buffer);
        uart0_send(" end of line \n");
        counter++;
        util_sleep(100);
    }
}


//uint8_t utf8Test[]="€";
//uint8_t utf8Test[]={0xc3,0xaf,0x00};
//uint8_t utf8Test[]={0xc3,0xb0,0x00};  //LATIN SMALL LETTER ETH
//uint8_t utf8Test[]={0xc3,0xb1,0x00};  //LATIN SMALL LETTER N WITH TILDE
//uint8_t utf8Test[]={0xf0,0x90,0x90,0x81}; // DESERET LONG O 𐐅
//uint8_t utf8Test[]="~"i𐐁𐐁𐐁 𐌰𐌰𐌡𐌡𐌀𐌀𐇡𐇡𐆗𐆗𐆠𐆠𐊀𐊀𐊺𐊺𐋈𐋈𐐁𐐅𐐅;
//uint8_t utf8Test[]="₠";


/*
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
}

    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
    uint32_t r12;
    uint32_t SP;
    uint32_t LR;
    uint32_t PC;
    uint32_t xPSR;
*/

