#include "system.h"
#include "string.h"

void util_sleep(uint32_t msec){
    uint32_t i=120000*msec;
    while(i--){
        //noop??
    }
}

void main00(void){
    while(true){
    }
}

void main01(void){
    while(true){
    }
}

void main02(void){
    while(true){
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

typedef struct{
    uint8_t red;
    uint8_t grn;
    uint8_t blu;
}RGBColor;


RGBColor hsvtorgb(uint8_t hue, uint8_t sat, uint8_t val){
    uint8_t region, fpart, p, q, t;
    RGBColor pix;
    if(sat==0){
        pix.red=val;
        pix.grn=val;
        pix.blu=val;
    }
    else{
        /* make hue 0-5 */
        region=hue/43;

        /* find remainder part, make it from 0-255 */
        fpart = (hue - (region * 43)) * 6;
        /* calculate temp vars, doing integer multiplication */
        p = (val*(255-sat))>> 8;
        q = (val*(255-((sat*fpart)>>8)))>>8;
        t = (val*(255-((sat*(255-fpart))>>8)))>>8;
            
        /* assign temp vars based on color cone region */
        switch(region){
            case 0:
                pix.red=val;
                pix.grn=t; 
                pix.blu=p; 
                break;
            case 1:
                pix.red=q;
                pix.grn=val;
                pix.blu=p;
                break;
            case 2:
                pix.red=p;
                pix.grn=val;
                pix.blu=t;
                break;
            case 3:
                pix.red=p;
                pix.grn=q;
                pix.blu=val;
                break;
            case 4:
                pix.red=t;
                pix.grn=p; 
                pix.blu=val; 
                break;
            default:
                pix.red=val; 
                pix.grn=p; 
                pix.blu=q; 
                break;
        }
    }

    return pix;
}



void main03(void){


    util_sleep(2);
    nrz0_enable();

    uint8_t msg[15]={0x00,0x00,0x00, 
                     0x00,0xFF,0x00, 
                     0x00,0x00,0xFF, 
                     0xFF,0x00,0xFF,
                     0x00,0xFF,0xFF};
    uint8_t i=0;
    RGBColor pix;
    
    while(true){
//        gpio_toggle();
//        output_system_stats();
        util_sleep(1);
        pix=hsvtorgb(i+  0 ,255, 50);
        msg[ 0]=pix.grn;
        msg[ 1]=pix.red;
        msg[ 2]=pix.blu;
        pix=hsvtorgb(i+ 51,255, 50);
        msg[ 3]=pix.grn;
        msg[ 4]=pix.red;
        msg[ 5]=pix.blu;
        pix=hsvtorgb(i+102,255, 50);
        msg[ 6]=pix.grn;
        msg[ 7]=pix.red;
        msg[ 8]=pix.blu;
        pix=hsvtorgb(i+153,255, 50);
        msg[ 9]=pix.grn;
        msg[10]=pix.red;
        msg[11]=pix.blu;
        pix=hsvtorgb(i+204,255, 50);
        msg[12]=pix.grn;
        msg[13]=pix.red;
        msg[14]=pix.blu;

        nrz0_send_message(msg,15);
        i++;
    }
}

