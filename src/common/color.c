#include "color.h"
//#include <math.h>
/*
    uint8_t red[3]={0x00,0xFF,0x00};
    uint8_t grn[3]={0xFF,0x00,0x00};
    uint8_t blu[3]={0x00,0x00,0xFF};
    uint8_t off[3]={0x00,0x00,0x00};
    uint8_t wht[3]={0xFF,0xFF,0xFF};

    uint8_t one[12];
*/



RGBColor color_convertHSV(uint8_t hue, uint8_t sat, uint8_t val){
    uint8_t region, fpart, p, q, t;
    RGBColor pix;
    if(sat==0){
        pix.red=val;
        pix.grn=val;
        pix.blu=val;
        return pix;
    }
    /* make hue 0-5 */
    region=hue/43;
    /* find remainder part, make it from 0-255 */
    fpart = (hue - (region * 43)) * 6;
    /* calculate temp vars, doing integer multiplication */
    p = (val*(255-sat))>>8;
    q = (val*(255-((sat*fpart)>>8)))>>8;
    t = (val*(255-((sat*(255-fpart))>>8)))>>8;

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
    return pix;
}

void color_testRainbow(uint8_t *pixarray, uint8_t index){
    RGBColor pix;
    pix=color_convertHSV((index+  0)%256, 255, 32);
    pixarray[ 0]=pix.grn;                   
    pixarray[ 1]=pix.red;                   
    pixarray[ 2]=pix.blu;                   
    pix=color_convertHSV((index+ 64)%256, 255, 32);
    pixarray[ 3]=pix.grn;                   
    pixarray[ 4]=pix.red;                   
    pixarray[ 5]=pix.blu;                   
    pix=color_convertHSV((index+128)%256, 255, 32);
    pixarray[ 6]=pix.grn;                   
    pixarray[ 7]=pix.red;                   
    pixarray[ 8]=pix.blu;                   
    pix=color_convertHSV((index+192)%256, 255, 32);
    pixarray[ 9]=pix.grn;
    pixarray[10]=pix.red;
    pixarray[11]=pix.blu;
}
