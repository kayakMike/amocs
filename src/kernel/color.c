#include "color.h"

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
