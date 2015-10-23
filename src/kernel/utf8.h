#ifndef __UTF8_H
#define __UTF8_H

#include "micro_types.h"

typedef enum{
    DECODE_OK,
    EXPECTED_CONTINUE,
    UNEXPECTED_CONTINUE,
    INVALID_BYTE
}UTF8DecodeStatus;

typedef enum{
    ENCODE_OK,
    INVALID_CODEPOINT
}UTF8EncodeStatus;

typedef struct{
    uint32_t code;
    uint8_t count;
    UTF8DecodeStatus status;
}UTF8Decode;

typedef struct{
    uint8_t bytes[4];  //current spec only calls for four bytes
    uint8_t count;
    UTF8EncodeStatus status;
}UTF8Encode;


UTF8Decode utf8_decode(uint8_t *byteArray);
UTF8Encode utf8_encode(uint32_t codepoint);

#endif //__UTF8_H


