#include "micro_types.h"
#include "utility.h"
#include "blink.h"
#include "ucom.h"
#include "systime.h"
//#include "nrz.h"
//#include "color.h"
#include "thread.h"



/*
void testcall(void *ptr){
    *((uint8_t *)ptr)=*((uint8_t *)ptr)+1;
    ucom_sendString(UART0,"future function: ");
}
*/

void main01(void){
    
    while(true){
        ucom_sendString(UART2,"thread01 test OK: \n\r");
        util_sleep(500);
    }
}


void main02(void){

    while(true){
        ucom_sendString(UART2,"thread02 test OK: \n\r");
        util_sleep(500);
    }
}

void main03(void){

    while(true){
        ucom_sendString(UART2,"thread03 test OK: \n\r");
        util_sleep(500);
    }
}

void main00(void){

//    nrz_initialize();
/*    uint8_t neo[4][12]={
        {0xFF,0x00,0x00, 0x00,0xFF,0x00, 0x00,0x00,0xFF, 0x00,0x00,0x00},
        {0x00,0x00,0x00, 0xFF,0x00,0x00, 0x00,0xFF,0x00, 0x00,0x00,0xFF},
        {0x00,0x00,0xFF, 0x00,0x00,0x00, 0xFF,0x00,0x00, 0x00,0xFF,0x00},
        {0x00,0xFF,0x00, 0x00,0x00,0xFF, 0x00,0x00,0x00, 0xFF,0x00,0x00}
    };
*/
//    uint8_t *neo[4]={red,grn,blu,off};

    uint32_t i=0;
//    uint8_t pix[12];

    while(true){
        blink_toggleOutput(0,20);
        ucom_sendString(UART2,"UART2 test OK: \n\r");
        ucom_sendString(UART0,"UART0 test OK: \n\r");
//        ucom_sendString(UART2,"UART2 test OK: \n\r");
        util_sleep(5000);
        //test ut nrz..
//        color_testRainbow(pix,(i%256));
//        nrz_send_message(pix,12);
//        i++;
    }
}


