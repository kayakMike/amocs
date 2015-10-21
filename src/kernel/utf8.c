#include "utf8.h"

/*byte types in UTF-8
 * CP1  CODEPOINT_1 --> basically an ASCII, one byte character sequence
 * CP2  CODEPOINT_2 --> start of a two byte codepoint
 * CP3  CODEPOINT_3 --> start of a three byte codepoint
 * CP4  CODEPOINT_4 --> start of a four byte codepoint
 * CONTINUE    --> additional byte of a multibyte sequence
 * INVALID     --> invalid octets include C0, C1, F5, and FF
 */
typedef enum {
    INVALID  =-10,     //unidentifiable token  
    CONTINUE =-1,      //continuation byte
    CP1      =0,       //start of a one byte codepoint
    CP2      =1,       //start of a two byte codepoint
    CP3      =2,       //start of a three byte codepoint
    CP4      =3,       //start of a four byte codepoint
    /*not in current specification
    CP5      =4,
    CP6      =5
    */
}UTF8TokenType;

typedef struct{
    UTF8TokenType type;
    uint32_t value;    
}UTF8Token;



//private function to identify the utf8 token type and parse the token value
UTF8Token process_token(uint8_t byte){
    UTF8Token res;
    if((byte&0x80)     ==0x00){        //test most significant 1 bits  
        res.value=(uint32_t)byte;      //0b0xxxxxxx is a one byte encoding
        res.type=CP1;
    }
    else if((byte&0xC0)==0x80){        //test most significant 2 bits  
        res.value=(uint32_t)byte&0x3F; //0b110xxxxx designates start of 2 byte codepoint
        res.type=CONTINUE;
    }
    else if((byte&0xE0)==0xC0){        //test most significant 3 bits  
        res.value=(uint32_t)byte&0x3F; //0b110xxxxx designates start of 2 byte codepoint
        res.type=CP2;
    }
    else if((byte&0xF0)==0xE0){        //test most significant 4 bits
        res.value=(uint32_t)byte&0x1F; //0b1110xxxx designates start of 3 byte codepoint
        res.type=CP3;
    }
    /*not in the current specification
    else if((byte&0xF8)==0xF0){ //test most significant 5 bits
        *value=byte&0x0F;        //0b11110xxx designates start of 4 byte codepoint
        return CP4;
    }
    else if((byte&0xFC)==0xF8){ //test most significant 6 bits
        *value=byte&0x07;         //0b111110xx designates start of 5 byte codepoint
        return CP5;
    }
    else if((byte&0xFE)==0xFC){ //test most significant 7 bits
        *value=byte&0x03;        //0b1111110x designates start of 6 byte codepoint
        return CP6;
    }
    */
    else{                             //default case....
        res.value=0xFF;  //255
        res.type=INVALID;
    }
    return res;
}


// byteArray must be called on a UTF8 boundary
UTF8Decode utf8_decode(uint8_t *byteArray){
    UTF8Decode res;
    UTF8Token token=process_token(*byteArray);
    res.count=1;
    res.code=token.value;
    if(token.type>0){
        int8_t count_required=token.type;
        while(count_required){
            byteArray++;
            token=process_token(*byteArray);
            if(token.type==CONTINUE){
                res.code=(res.code<<6)+(uint32_t)token.value;
                res.count++;
                count_required--;
            }
            else if(token.type==INVALID){
               res.code=0x00FFFD;
               res.status=INVALID_BYTE;
               break;
            }
            //subtle fall through logic here.
            else if(token.type!=CONTINUE){
               res.code=0x00FFFD;
               res.status=EXPECTED_CONTINUE;
               break;
            }
        }
    }
    else if(token.type==INVALID){
        res.code=0xFFFD;
        res.status=INVALID_BYTE;
    }
    else if(token.type==CONTINUE){
        res.code=0xFFFD;
        res.status=UNEXPECTED_CONTINUE;
    }
    res.status=DECODE_OK;
    return res; 
}

UTF8Encode utf8_encode(uint32_t codepoint){
    UTF8Encode res;
    if(codepoint<=0x7F){
        //one byte encoding,  7  bits arranged
        //0: 0x0xxxxxx
        res.bytes[0]=codepoint&0x7F;
        res.count=1;
    }
    else if(codepoint<=0x7FF){
        //two byte encoding,  11 bits 
        //0: 0b110xxxxx
        //1: 0b10xxxxxx
        res.bytes[0]=( codepoint>>6 )      +0xC0;
        res.bytes[1]=((codepoint    )&0x3F)+0x80;
        res.count=2;
    }
    else if(codepoint<=0xFFFF){
        //three byte encoding, 16 bits
        //0: 0b1110xxxx 
        //1: 0b10xxxxxx 
        //2: 0b10xxxxxx
        res.bytes[0]=( codepoint>>12)      +0xE0;
        res.bytes[1]=((codepoint>> 6)&0x3F)+0x80;
        res.bytes[2]=((codepoint    )&0x3F)+0x80;
        res.count=3;
    }
    else if(codepoint<=0x1FFFFF){
        //four byte encoding,  21 bits
        //0: 0b11110xxx 
        //1: 0b10xxxxxx 
        //2: 0b10xxxxxx
        //3: 0b10xxxxxx
        res.bytes[0]=( codepoint>>18)      +0xF0;
        res.bytes[1]=((codepoint>>12)&0x3F)+0x80;
        res.bytes[2]=((codepoint>> 6)&0x3F)+0x80;
        res.bytes[3]=((codepoint    )&0x3F)+0x80;
        res.count=4;
    }
    /* not in the current specification
    else if(codepoint<=0x3FFFFFF){
        //five byte
        res.bytes[0]=( codepoint>>24)      +0xF8;
        res.bytes[1]=((codepoint>>18)&0x3F)+0x80;
        res.bytes[2]=((codepoint>>12)&0x3F)+0x80;
        res.bytes[3]=((codepoint>> 6)&0x3F)+0x80;
        res.bytes[4]=((codepoint    )&0x3F)+0x80;
        res.count=5;
    }
    else if(codepoint<=0x7FFFFFFF){
        //six byte
        res.bytes[0]=( codepoint>>30)      +0xFC;
        res.bytes[1]=((codepoint>>24)&0x3F)+0x80;
        res.bytes[2]=((codepoint>>18)&0x3F)+0x80;
        res.bytes[3]=((codepoint>>12)&0x3F)+0x80;
        res.bytes[4]=((codepoint>> 6)&0x3F)+0x80;
        res.bytes[5]=((codepoint    )&0x3F)+0x80;
        res.count=6;
    }
    */
    return res;
}

