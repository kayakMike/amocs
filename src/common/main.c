#include "system.h"
#include "string.h"
#include "color.h"
#include "utility.h"


void output_number(uint32_t num){
    uint8_t str[10];
    uint_to_decimal_string(num,str);
    uart0_send(str);
} 

void testcall(void *ptr){
    gpio_toggle020();
    *((uint8_t *)ptr)=*((uint8_t *)ptr)+1;
    uart0_send("system uptime: ");
    output_number(systick_return_uptime());
    uart0_send(" end \n\r");
}

void main00(void){
    uint8_t data[512];
    uint8_t str[10];
    uint32_t i;
    uint32_t j;
    uint32_t k=0;

    spisd_initialize_card();

    while(true){
        util_sleep(10000);
        uart0_send("sdcard init test: \n\r");
         
        spisd_read_single_block(data,k);
        uart0_send("\t block 0: \n\r");
        for(i=0;i<32;i++){
            uint_to_hex_string(i,str);
            uart0_send(str);
            uart0_send(": ");
            for(j=0;j<16;j++){
                uint_to_hex_bstring(data[j+i*16],str);
                uart0_send(str);
                uart0_send(" ");
            }
            uart0_send("\n\r");
        }
        uart0_send("\n\rsdcard init test complete \n\r");
        k++;
    }
}

void main01(void){
    SoftTimer stimer0;
    SoftTimer stimer1;
    uint8_t arg=0x00;
    uart0_send("Timer Test \n\r");
    util_sleep(1000);

    stimer0.period=2000;
    stimer0.callback=&testcall;
    stimer0.arg=&arg;
    
    stimer1.period=3000;
    stimer1.callback=&testcall;
    stimer1.arg=&arg;

//    systick_register_swtimer(&stimer0);
//    systick_register_swtimer(&stimer1);

    while(true){
//        output_number(arg);
//        uart0_send(" end \n\r");
//        util_sleep(1000);
    }
    
}


void main02(void){
    while(true){
        uart2_send("uart2 test! ");
    }
}

void main03(void){

    uint8_t i=0;
    uint8_t msg[12];
    while(true){
    }
}
