#include "utf8.h"


//private function
void utf8_byte_type(uint8_t byte,uint8_t *type, uint8_t *value){
    if((byte>>7) == 0x00){
        *type=1;
        *value=byte;
    }
    else if((byte>>6) == 0x02){
        //byte is a continuation byte
        //0b10xx xxxx >> 6 = 0b10 (2)
        //value = byte & 0b00111111
        *type=0;
        *value=byte & 0x3F;
        if(*value<=1){
            //this is an illegal value
        }
    }
    else if((byte>>5) == 0x06){
        //byte is start of a two byte code point 
        //value = byte & 0b00011111
        //cannot be zero
        //cannot be one
        *type=2;
        *value=byte & 0x1F;
    }
    else if((byte>>4) == 0x0E){
        //byte is start of a three byte code point 
        //value = byte & 0b00001111
        //cannot be zero
        *type=3;
        *value=byte & 0xF;
    }
    else if((byte>>3) == 0x1E){
        //byte is start of a four byte code point 
        //value = byte & 0b00000111
        //cannot be zero
        *type=4;
        *value=byte & 0x7; 
    }
    else{
        //definitely invalid byte.
    }
}

uint32_t utf8_decode(uint8_t *array){
    uint8_t cp_byte_count;
    uint8_t value;
    uint32_t result=0xFFFFFFFF;
    utf8_byte_type(array[0],&cp_byte_count,&value);
    if(cp_byte_count==1){
        result=(uint32_t)value;
    }
    else if(cp_byte_count==2){
        result=(uint32_t)value<<6;
        utf8_byte_type(array[1],&cp_byte_count,&value);
        result=result+value;
    }
    else if(cp_byte_count==3){
        result=(uint32_t)value<<12;
        utf8_byte_type(array[1],&cp_byte_count,&value);
        result=result+(value<<6);
        utf8_byte_type(array[2],&cp_byte_count,&value);
        result=result+(value);
    }
    else if(cp_byte_count==4){
        result=(uint32_t)value<<18;
        utf8_byte_type(array[1],&cp_byte_count,&value);
        result=result+((uint32_t)value<<12);
        utf8_byte_type(array[2],&cp_byte_count,&value);
        result=result+((uint32_t)value<<6);
        utf8_byte_type(array[3],&cp_byte_count,&value);
        result=result+((uint32_t)value);
    }
    return result;
}


