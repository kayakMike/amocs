#include "micro_types.h"
#include "uart0.h"

volatile uint32_t globalIndex;
extern volatile uint32_t system_LongCount;

uint8_t uint_to_string_deterministic(char *string, uint32_t convert);
uint8_t uint_to_string(char *string,uint32_t convert);
void string_reverse(char *string, uint32_t length);
void sleep(void);

int main(void){
    globalIndex=0; 
 
    char message[]="Hello World! ";
    char string_buffer[12];
    uint32_t counter=0; 
    while(1){
        uart0_send(message);
        uint_to_string_deterministic(string_buffer,system_LongCount);
        uart0_send(string_buffer);
        uart0_send(" go ");
        uint_to_string_deterministic(string_buffer,counter);
        uart0_send(string_buffer);
        uart0_send(" end of line \n");
        sleep();
        counter++;
    }
}


void sleep(void){
    uint32_t i;
    for(i=0;i<1000000;i++){
        globalIndex++;
    }
}

void string_reverse(char *string, uint32_t length){
    char swp;
    uint32_t left=0;
    uint32_t right=length;
    while(left<right){
        swp=string[left];
        string[left]=string[right];
        string[right]=swp;
        right--;
        left++;
    }
}

uint8_t uint_to_string(char *string,uint32_t convert){
    char symbols[]="01234567890";
    uint8_t sym=0;
    uint8_t i=0;
    //corner case. convert is zero
    if(convert==0){
        string[0]='0';
        i=1; 
    }
    while(convert>0){
       sym=convert%10;
       convert=convert/10;
       string[i]=symbols[sym];
       i++;
    }
    string[i]='\0'; //null concatenate!
    i--;
    string_reverse(string,(uint32_t)i);
    return i;
}


//forward facing deterministic version of the above.
uint8_t uint_to_string_deterministic(char *string, uint32_t convert){

    //uint32_t max value is 4 294 967 296, so decimal division to get the left 
    //most digit is 1 000 000 000
    //1 000 000 000 1
    //  100 000 000 2
    //   10 000 000 3
    //    1 000 000 4
    //      100 000 5
    //       10 000 6
    //        1 000 7
    //          100 8
    //           10 9
    //            1 10
    //            0 --end here
    //only loop through 10 times! not bad.
    char symbols[]="01234567890";
    uint8_t sym=0;
    uint8_t index=0;
    uint32_t div=1000000000;
    while(div>0){
        sym=convert/div;
        convert=convert-(sym*div);  //must strip the leading power of 10
        string[index]=symbols[sym];
        index++;
        div=div/10;
    }
    string[index]='\0'; //null concatenate!
    return index-1;
}


