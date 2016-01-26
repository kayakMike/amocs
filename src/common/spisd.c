#include "system.h"
#include "string.h"
#include "utility.h"



//canditates for spisd structure
struct SpiSD_R1Response{
    unsigned idle_state              : 1;
    unsigned erase_reset             : 1;
    unsigned cmd_illegal             : 1;
    unsigned crc_err                 : 1;
    unsigned erase_seq_err           : 1;
    unsigned address_err             : 1;
    unsigned param_err               : 1;
    unsigned                         : 1;
};

struct SpiSD_R2Response{
    unsigned range_invalid           : 1;
    unsigned erase_param_invalid     : 1;
    unsigned write_protect_violation : 1;
    unsigned correct_failure_err     : 1;
    unsigned controller_err          : 1;
    unsigned unknown_err             : 1;
    unsigned erase_skip_err          : 1;
    unsigned card_lock               : 1;
};

enum SpiSD_CardState{
    NOCONNECT,
    READY,
    IDLE,
    READ,
    WRITE,
    ERROR
};

//every command token relays a state byte back as an acknowlegement
uint8_t sdc_status=0xFF;

//command CMD2 returns extended state information
uint8_t sdc_ext_status=0xFF;

// management variable to track card as a state machine
// card can be present, not present, initialized, read, write states 
uint8_t sdc_state; 

//probably don't really need these long term
uint8_t ifcond[4];
uint8_t ocr[4];
uint8_t cid[16];
uint8_t csd[16];


//junk globals.  Refactor these out
uint8_t crc[2];
uint8_t str[10];
uint8_t i;

void spi_timeout_function(void *val){
    *((uint8_t *)val)=false;
}

// dummy function
uint8_t crc_compute_crc7(uint8_t *array, uint32_t len){
    uint8_t result=0;

    if(array[0]==0x40){
        result=0x4A;
    }
    if(array[0]==0x48){
        result=0x43;
    }
    return result;
}

uint8_t spisd_parse_r1_response(void){
    uint8_t res;
    uint8_t ontime=true;
    SoftTimer tim={.period=500, .callback=&spi_timeout_function, .arg=&ontime};
    systick_register_swtimer(&tim);
    //time out
    spi_recv(&res,1);
    while((res&0x80) && ontime){
        spi_recv(&res,1);
    }
    systick_deregister_swtimer(&tim);


    if((res&0x80 && ontime==false)){
        uart0_send("spisd R1 acknowlege time out \n\r");
        sdc_state=ERROR;
    }
    uart0_send("res1 ");
    uint_to_hex_string(res,str);
    uart0_send(str);
    uart0_send(" \n\r");

    return res;
}

void spisd_initialize_card(void){
    spisd_go_idle();
    spisd_send_if_cond();
    spisd_app_send_op_cond();
    spisd_read_ocr();
    spisd_read_card_identity();
    spisd_read_card_specific();
}

uint8_t spisd_send_command(uint8_t index,uint32_t arg){
    uint8_t cmd_token[6];

    cmd_token[0]=index|0x40;
    cmd_token[1]=(uint8_t)(arg>>24);
    cmd_token[2]=(uint8_t)(arg>>16);
    cmd_token[3]=(uint8_t)(arg>> 8);
    cmd_token[4]=(uint8_t)(arg    );
    cmd_token[5]=(uint8_t)((crc_compute_crc7(cmd_token,5))<<1)|0x01;

    spi_send(cmd_token,6);
    sdc_status=spisd_parse_r1_response();
    if(sdc_status&0x80){
    }
}    

void spisd_go_idle(void){
    uart0_send("cmd0 \n\r");
    //rattle port so the card can figure out the timing
    for(i=0;i<10;i++){
        spi_xmit(0xFF);
    }

    spisd_send_command(0x00,0x00);
    while((sdc_status!=0x01)){
        spi_recv(&sdc_status,1);
    }
}

void spisd_extend_status(void){
    spisd_send_command(2,0);
    spi_recv(&sdc_ext_status,1);
}

void spisd_send_if_cond(void){
    uart0_send("cmd8 \n\r");
    spisd_send_command(0x08,0x01AA);
    spi_recv(ifcond,4);
}

void spisd_app_send_op_cond(void){
    uart0_send("acmd41 \n\r");
    spisd_send_command(55,0);
    spisd_send_command(41,0x40000000);
    while((sdc_status!=0x00)){
        spisd_send_command(55,0);
        spisd_send_command(41,0x40000000);
    }
}

void spisd_read_ocr(void){
    uart0_send("cmd58 \n\r");
    spisd_send_command(58,0x00);
    spi_recv(ocr,4);
}

void spisd_read_card_identity(void){
    uart0_send("cmd10 \n\r");
    spisd_send_command(10,0x00);
    spi_recv(cid,16);
    spi_recv(crc,2);
}

void spisd_read_card_specific(void){
    uart0_send("cmd9 \n\r");
    spisd_send_command(9,0x00);
    spi_recv(csd,16);
    spi_recv(crc,2);
}

void spisd_read_single_block(uint8_t *block, uint32_t sector){
    uart0_send("cmd17 \n\r");
    uint8_t token;
    spisd_send_command(17,sector);
    
    spi_recv(&token,1);
    while(token!=0xFE){
        uint_to_hex_bstring(token,str);
        uart0_send(str);
        uart0_send(" ");
        spi_recv(&token,1);
    }
    uart0_send("try to fill block \n\r");
    spi_recv(block,512);
    uart0_send("block filled\n\r");
    spi_recv(crc,2);
    uart0_send("complete\n\r");
}

void spisd_start_read(uint32_t sector){
    spisd_send_command(18,sector);
    sdc_state=READ;
}

void spisd_read_next_block(uint8_t *block){
    //card must be in READ state
    uint8_t token;
    spi_recv(&token,1);
    while(token!=0xFE){
        spi_recv(&token,1);
    }
    spi_recv(block,512);
    spi_recv(crc,2);
}

void spisd_stop_read(void){
    spisd_send_command(12,0);
}


/*   
    for(i=0;i<4;i++){
        uart0_send("ifcond: ");
        uint_to_hex_string((uint32_t)ifcond[i],str);
        uart0_send(str);
        uart0_send(" end \n\r");
    }
    
    for(i=0;i<4;i++){
        uart0_send("ocr: ");
        uint_to_hex_string((uint32_t)ocr[i],str);
        uart0_send(str);
        uart0_send(" end \n\r");
    }

    for(i=0;i<16;i++){
        uart0_send("cid ");
        uint_to_hex_string((uint32_t)ocr[i],str);
        uart0_send(str);
        uart0_send(" end \n\r");
    }
    uart0_send_message(cid,16);
    uart0_send("\n\r");
    
    for(i=0;i<16;i++){
        uart0_send("csd ");
        uint_to_hex_string((uint32_t)ocr[i],str);
        uart0_send(str);
        uart0_send(" end \n\r");
    }
    uart0_send_message(csd,16);
    uart0_send("\n\r");
*/
