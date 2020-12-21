#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../flags/flags.h"
#include "../ram/ram.h"

typedef struct CCVM CCVM;

// special non used
/* 0x?? len = 1*/	void ccvm_instructions_nop(CCVM*);

// exit the VM
/* 0x00 len = 1*/ 	void ccvm_instructions_exit(CCVM*);

// stack opcodes
/* 0x01 len = 5*/	void ccvm_instructions_push_lit(CCVM*);
/* 0x02 len = 2*/	void ccvm_instructions_push_reg(CCVM*);
/* 0x03 len = 2*/	void ccvm_instructions_pop_reg(CCVM*);
/* 0x04 len = 5*/  void ccvm_instructions_pop_memory(CCVM*);
/* 0x05 len = 1*/	void ccvm_instructions_stack_dupe(CCVM*);

// MOV opcodes
/* 0x06 len = 6*/	void ccvm_instructions_mov_lit_reg(CCVM*);
/* 0x07 len = 9*/	void ccvm_instructions_mov_lit_mem(CCVM*);
/* 0x08 len = 6*/	void ccvm_instructions_mov_mem_reg(CCVM*);
/* 0x09 len = 6*/	void ccvm_instructions_mov_reg_mem(CCVM*);
/* 0x0a len = 3*/  void ccvm_instructions_mov_reg_reg(CCVM*);
/* 0x0B len = 9*/  void ccvm_instructions_mov_mem_mem(CCVM*);
/* 0x0C len = 5*/  void ccvm_instructions_push_mem(CCVM*);

// math opcodes
/* 0x10 len = 3*/	void ccvm_instructions_math_add_reg(CCVM*);
/* 0x11 len = 1*/	void ccvm_instructions_math_add_stack(CCVM*);
/* 0x12 len = 3*/	void ccvm_instructions_math_sub_reg(CCVM*);
/* 0x13 len = 1*/	void ccvm_instructions_math_sub_stack(CCVM*);
/* 0x14 len = 3*/	void ccvm_instructions_math_mul_reg(CCVM*);
/* 0x15 len = 1*/	void ccvm_instructions_math_mul_stack(CCVM*);
/* 0x16 len = 3*/	void ccvm_instructions_math_div_reg(CCVM*);
/* 0x17 len = 1*/	void ccvm_instructions_math_div_stack(CCVM*);
/* 0x18 len = 2*/	void ccvm_instructions_math_not_reg(CCVM*);
/* 0x19 len = 1*/	void ccvm_instructions_math_not_stack(CCVM*);
/* 0x1a len = 3*/	void ccvm_instructions_math_and_reg(CCVM*);
/* 0x1b len = 1*/	void ccvm_instructions_math_and_stack(CCVM*);
/* 0x1c len = 3*/	void ccvm_instructions_math_or_reg(CCVM*);
/* 0x1d len = 1*/	void ccvm_instructions_math_or_stack(CCVM*);
/* 0x1e len = 3*/	void ccvm_instructions_math_xor_reg(CCVM*);
/* 0x1f len = 1*/	void ccvm_instructions_math_xor_stack(CCVM*);

// jump opcodes
/* 0x20 len = 5*/	void ccvm_instructions_jump_absolute(CCVM*);
/* 0x30 len = 3*/	void ccvm_instructions_compare_reg_reg(CCVM*);
/* 0x31 len = 6*/	void ccvm_instructions_compare_reg_lit(CCVM*);
/* 0x32 len = 5*/	void ccvm_instructions_compare_stack_lit(CCVM*);

/* 0x33 len = 1*/	void ccvm_instructions_jump_equal(CCVM*);
/* 0x34 len = 1*/	void ccvm_instructions_jump_notequal(CCVM*);
/* 0x35 len = 1*/	void ccvm_instructions_jump_greater(CCVM*);
/* 0x36 len = 1*/	void ccvm_instructions_jump_smaller(CCVM*);
/* 0x37 len = 1*/	void ccvm_instructions_jump_overflow(CCVM*);
/* 0x40 len = 1*/	void ccvm_instructions_flag_reset(CCVM*);

// other math opcodes
/* 0x50 len = 2*/	void ccvm_instructions_math_inc_reg(CCVM*);
/* 0x51 len = 2*/	void ccvm_instructions_math_dec_reg(CCVM*);
/* 0x52 len = 1*/  void ccvm_instructions_math_inc_stack(CCVM*);
/* 0x53 len = 1*/	void ccvm_instructions_math_dec_stack(CCVM*);

// other
/* 0x60 len = 5*/	void ccvm_instructions_procedure_call(CCVM*);
/* 0x61 len = 1*/	void ccvm_instructions_procedure_return(CCVM*);
/* 0xff len = 1*/	void ccvm_instructions_syscall(CCVM*);

extern void (*ccvm_instructionset[256])(CCVM*);
#endif
