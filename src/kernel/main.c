#include "micro_types.h"
#include "uart0.h"
#include "utf8.h"
#include "string.h"

volatile uint32_t globalIndex;
extern volatile uint32_t system_LongCount;

void sleep(void);

int main(void){
    globalIndex=0; 
    char message[]="New Hello World! \n";
    char string_buffer[]="------------";
    uint32_t i=0;
    uint32_t counter=0x10405; 
 

    send_message(message,20);
    UTF8Encode utf8Test;
    utf8Test.bytes[0]=0x00;
    utf8Test.bytes[1]=0x00;
    utf8Test.bytes[2]=0x00;
    utf8Test.bytes[3]=0x00;

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
       sleep();
    }
}

void sleep(void){
    uint32_t i;
    for(i=0;i<10000000;i++){
        globalIndex++;
    }
}



    //uint8_t utf8Test[]="€";
    //uint8_t utf8Test[]={0xc3,0xaf,0x00};
    //uint8_t utf8Test[]={0xc3,0xb0,0x00};  //LATIN SMALL LETTER ETH
    //uint8_t utf8Test[]={0xc3,0xb1,0x00};  //LATIN SMALL LETTER N WITH TILDE
    //uint8_t utf8Test[]={0xf0,0x90,0x90,0x81}; // DESERET LONG O 𐐅
    //uint8_t utf8Test[]="~"i𐐁𐐁𐐁 𐌰𐌰𐌡𐌡𐌀𐌀𐇡𐇡𐆗𐆗𐆠𐆠𐊀𐊀𐊺𐊺𐋈𐋈𐐁𐐅𐐅;
    //uint8_t utf8Test[]="₠";
