#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../flags/flags.h"

typedef struct CCVM CCVM;

// special non used
/* 0x?? */	void ccvm_instructions_nop(CCVM*);

// exit the VM
/* 0x00 */ 	void ccvm_instructions_exit(CCVM*);

// stack opcodes
/* 0x01 */	void ccvm_instructions_push_lit(CCVM*);
/* 0x02 */	void ccvm_instructions_push_reg(CCVM*);
/* 0x03 */	void ccvm_instructions_pop_reg(CCVM*);
/* 0x04 */  // void ccvm_instructions_pop_memory(CCVM*);
/* 0x05 */	void ccvm_instructions_stack_dupe(CCVM*);

// MOV opcodes
/* 0x06 */	void ccvm_instructions_mov_lit_reg(CCVM*);
/* 0x07 */	// void ccvm_instructions_mov_lit_mem(CCVM*);
/* 0x08 */	// void ccvm_instructions_mov_mem_reg(CCVM*);
/* 0x09 */	// void ccvm_instructions_mov_reg_mem(CCVM*);

extern void (*ccvm_instructionset[256])(CCVM*);
#endif