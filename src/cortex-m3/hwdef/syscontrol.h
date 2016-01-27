#ifndef __SYSCONTROL_H
#define __SYSCONTROL_H
#include "micro_types.h"



/*  The ACTLR provides disable bits for the following processor functions:
 *     IT folding
 *     write buffer use for accesses to the default memory map
 *     interruption of multi-cycle instructions.
 *  By default this register is set to provide optimum performance from the
 *  Cortex-M3 processor, and does not normally require modification.
 *
 */
typedef struct AuxillaryControl{
    unsigned irq_multi_disable     : 1;  //disable interrupting ldm and stm multiple byte 
    unsigned write_buffer_disable  : 1;  //disable the write buffer
    unsigned it_folding_disable    : 1;  //disable it folding
    unsigned                       :29; 
}AuxillaryControl;

#define AUXILLARY_CONTROL       (*(volatile AuxillaryControl *)(0xE000E008))

/*  The CPUID register contains the processor 
 *      part number, 
 *      version, and 
 *      implementation information
 */
typedef struct CpuIdentification{
    unsigned revision             : 4;
    unsigned part_number          :12;
    unsigned constant             : 4;
    unsigned variant              : 4;
    unsigned implementer          : 8;
}CpuIdentification;
#define CPU_IDENTIFICATION     (*(volatile CpuIdentification *)(0xE000ED00))


/* The Interrupt Control and State Register provides
 *    a set-pending bit for the 
 *        Non-Maskable Interrupt (NMI) exception
 *    set-pending and clear-pending bits for the 
 *        PendSV and 
 *        SysTick exceptions
 * state indicates:
 *    the exception number of the exception being processed
 *    whether there are preempted active exceptions
 *    the exception number of the highest priority pending exception
 *    whether any interrupts are pending.
 */
typedef struct InterruptControlState{
    unsigned active_vector       : 8; //ro shows the active vector number
    unsigned                     : 2; //reserved
    unsigned rettobase           : 1; //other preemptive active vector
    unsigned pending_vector      : 8; //other avtive vector
    unsigned isr_pending         : 1; //isr pending, excluding nmi and faults
    unsigned res_debug           : 1; //zero if processor is not in debug
    unsigned                     : 1; //reserved
    unsigned systick_clr_pending : 1; //removes the systick pending state
    unsigned systick_set_pending : 1; //sets the systick to be executed
    unsigned pendsv_clr_pending  : 1; //removes the pendsv pending state
    unsigned pendsv_set_pending  : 1; //sets the pendsv pending state
    unsigned                     : 2;
    unsigned nmi_set_pending     : 1; //sets the pendsv pending state
}InterruptControlState;
#define IRQ_CONTROL_STATE     (*(volatile InterruptControlState *)(0xE000ED04))


/*
 * When setting TBLOFF, you must align the offset to the number of exception 
 * entries in the vector table. The minimum alignment is 32 words, enough for
 * up to 16 interrupts. For more interrupts, adjust the alignment by rounding
 * up to the next power of two. For example, if you require 21 interrupts, the
 * alignment must be on a 64-word boundary because the required table size is
 * 37 words, and the next power of two is 64. See your vendor documentation for
 * the alignment details for your device.
 *
 */
typedef struct VectorTableOffset{
    unsigned                    : 7;
    unsigned offset             :25;
}VectorTableOffset;
#define VECTOR_TABLE         (*(volatile VectorTableOffset *)(0xE000ED00))


/*  The Application Interrupt and Reset Control
 *  register provides priority grouping control for the 
 *     exception model, 
 *     endian status for data accesses, 
 *     and reset control of the system. 
 *
 */
typedef struct ApplicationInterruptResetControl{
    unsigned vector_reset         : 1; // reserved for debug
    unsigned vector_ctl_active    : 1; // reserved for debug
    unsigned system_reset_request : 1; // set this to 1 to force the system to reset
    unsigned                      : 5; // reserved
    unsigned priority_group       : 3; // controls the binary point to determine isr group/sub priorities
    unsigned                      : 4; // reserved
    unsigned endianness           : 1; // RO  0 is little endian 1 is big endian.  this is implementation defined
    unsigned vectkey              :16; // unlock..  Read as 0xFA05.  To unlock, write 0x5FA
}ApplicationInterruptResetControl;
#define APPLICATION_IRQ_RESET_CONTROL    (*(volatile ApplicationInterruptResetControl *)(0xE000ED0C))


/*
 * The SystemControl register governs features of entry to and exit from low power state.
 */
typedef struct SystemControl{
    unsigned                    : 1;  //  reserved
    unsigned sleep_on_exit      : 1;  //  indicates sleep on exit. set to 1 for an ISR driven application  
    unsigned sleep_deep         : 1;  //  0: normal sleep.  1: deep sleep mode
    unsigned                    : 1;  //  reserved
    unsigned send_event_on_pend : 1;  //  0: only enabled interrupts can wake the processor. 1: then all interrupts and events
    unsigned                    :27;
}SystemControl;
#define SYSTEM_CONTROL     (*(volatile SystemControl *)(0xE000ED10))

//Configuration and Control
//System ISR Priority Register 1
//System ISR Priority Register 2
//System ISR Priority Register 3

typedef struct SystemInterruptPriority{
    unsigned memManage           : 8;
    unsigned busFault            : 8;
    unsigned usageFault          : 8;
    unsigned                     : 8;
    unsigned                     : 8; 
    unsigned                     : 8;
    unsigned                     : 8;
    unsigned svCall              : 8;
    unsigned                     : 8;
    unsigned                     : 8;
    unsigned pendSV              : 8;
    unsigned sysTick             : 8;
}SystemInterruptPriority;

#define SYSTEM_INTERRUPT_PRIORITY (*(volatile SystemInterruptPriority *)(0xE000ED18))


//System ISR Control and State
//Configurable Fault Status
//MemManage Fault Status
//BusFault Status
//Usage Fault Status
//HardFault Status
//MemManage Fault Address Register
//BusFault Address Register
//Auxillary Fault Status Register

#endif //__SYSCONTROL_H
