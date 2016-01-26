#include "color.h"

uint8_t color_tst_msg[4][12]={
    {0xFF,0x00,0x00, 0x00,0xFF,0x00, 0x00,0x00,0xFF, 0x00,0x00,0x00},
    {0x00,0x00,0x00, 0xFF,0x00,0x00, 0x00,0xFF,0x00, 0x00,0x00,0xFF},
    {0x00,0x00,0xFF, 0x00,0x00,0x00, 0xFF,0x00,0x00, 0x00,0xFF,0x00},
    {0x00,0xFF,0x00, 0x00,0x00,0xFF, 0x00,0x00,0x00, 0xFF,0x00,0x00}
};

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
        p = (val*(255-sat))>>8;
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

void color_test_rainbow(uint8_t *pixarray, uint8_t index){
    RGBColor pix;
    index=index%360;
    pix=hsvtorgb(index,   255, 100);
    pixarray[ 0]=pix.grn;
    pixarray[ 1]=pix.red;
    pixarray[ 2]=pix.blu;
    pix=hsvtorgb(index+90,255, 100);
    pixarray[ 3]=pix.grn;
    pixarray[ 4]=pix.red;
    pixarray[ 5]=pix.blu;
    pix=hsvtorgb(index+180,255, 100);
    pixarray[ 6]=pix.grn;
    pixarray[ 7]=pix.red;
    pixarray[ 8]=pix.blu;
    pix=hsvtorgb(index+270,255, 100);
    pixarray[ 9]=pix.grn;
    pixarray[10]=pix.red;
    pixarray[11]=pix.blu;

}
