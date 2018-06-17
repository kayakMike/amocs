#include "types.h"

//from the lpc1769 data sheet
#define PORT4_DIR (*(volatile uint32_t *)(0x2009C080))
#define PORT4_SET (*(volatile uint32_t *)(0x2009C098))
#define PORT4_CLR (*(volatile uint32_t *)(0x2009C09C))
#define PIN28 (1<<28)

uint32_t delay(uint32_t value){
    while(value){
        value--;
    }
    return value;
}

int main(int argc, char **argv)
{
    //simplest micro controller program.
    //blink a gpio GPIO
    PORT4_DIR = PORT4_DIR | PIN28;
    while(TRUE)
    {
        PORT4_CLR = PIN28;
        delay(100000000);
        PORT4_SET = PIN28;
	    delay(100000000);
    }
    return 0;
}
