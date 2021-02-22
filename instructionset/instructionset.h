#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../flags/flags.h"
#include "../ram/ram.h"

typedef struct CCVM CCVM;

// special non used
/* 0x?? */	void ccvm_instructions_nop(CCVM*);

// exit the VM
/* 0x00 */ 	void ccvm_instructions_exit(CCVM*);

// stack opcodes
/* 0x01 */	void ccvm_instructions_push_lit(CCVM*);
/* 0x02 */	void ccvm_instructions_push_reg(CCVM*);
/* 0x03 */	void ccvm_instructions_pop_reg(CCVM*);
/* 0x04 */  void ccvm_instructions_pop_memory(CCVM*);
/* 0x05 */	void ccvm_instructions_stack_dupe(CCVM*);

// MOV opcodes
/* 0x06 */	void ccvm_instructions_mov_lit_reg(CCVM*);
/* 0x07 */	void ccvm_instructions_mov_lit_mem(CCVM*);
/* 0x08 */	void ccvm_instructions_mov_mem_reg(CCVM*);
/* 0x09 */	void ccvm_instructions_mov_reg_mem(CCVM*);
/* 0x0a */  void ccvm_instructions_mov_reg_reg(CCVM*);
/* 0x0b */  void ccvm_instructions_mov_mem_mem(CCVM*); // todo
/* 0x0c */  void ccvm_instructions_push_mem(CCVM*);    // todo

// math opcodes
/* 0x10 */	void ccvm_instructions_math_add_reg(CCVM*);
/* 0x11 */	void ccvm_instructions_math_add_stack(CCVM*);
/* 0x12 */	void ccvm_instructions_math_sub_reg(CCVM*);
/* 0x13 */	void ccvm_instructions_math_sub_stack(CCVM*);
/* 0x14 */	void ccvm_instructions_math_mul_reg(CCVM*);
/* 0x15 */	void ccvm_instructions_math_mul_stack(CCVM*);
/* 0x16 */	void ccvm_instructions_math_div_reg(CCVM*);
/* 0x17 */	void ccvm_instructions_math_div_stack(CCVM*);
/* 0x18 */	void ccvm_instructions_math_not_reg(CCVM*);
/* 0x19 */	void ccvm_instructions_math_not_stack(CCVM*);
/* 0x1a */	void ccvm_instructions_math_and_reg(CCVM*);
/* 0x1b */	void ccvm_instructions_math_and_stack(CCVM*);
/* 0x1c */	void ccvm_instructions_math_or_reg(CCVM*);
/* 0x1d */	void ccvm_instructions_math_or_stack(CCVM*);
/* 0x1e */	void ccvm_instructions_math_xor_reg(CCVM*);
/* 0x1f */	void ccvm_instructions_math_xor_stack(CCVM*);

// jump opcodes
/* 0x20 */	void ccvm_instructions_jump_absolute(CCVM*);
/* 0x30 */	void ccvm_instructions_compare_reg_reg(CCVM*);
/* 0x31 */	void ccvm_instructions_compare_reg_lit(CCVM*);
/* 0x32 */	void ccvm_instructions_compare_stack_lit(CCVM*);

/* 0x33 */	void ccvm_instructions_jump_equal(CCVM*);
/* 0x34 */	void ccvm_instructions_jump_notequal(CCVM*);
/* 0x35 */	void ccvm_instructions_jump_greater(CCVM*);
/* 0x36 */	void ccvm_instructions_jump_smaller(CCVM*);
/* 0x37 */	void ccvm_instructions_jump_overflow(CCVM*);
/* 0x40 */	void ccvm_instructions_flag_reset(CCVM*);

// other math opcodes
/* 0x50 */	void ccvm_instructions_math_inc_reg(CCVM*);
/* 0x51 */	void ccvm_instructions_math_dec_reg(CCVM*);
/* 0x52 */  void ccvm_instructions_math_inc_stack(CCVM*);
/* 0x53 */	void ccvm_instructions_math_dec_stack(CCVM*);

// other
/* 0x60 */	void ccvm_instructions_procedure_call(CCVM*);
/* 0x61 */	void ccvm_instructions_procedure_return(CCVM*);

// all new:
/* 0x70 */  void ccvm_instructions_math_add_reg_num(CCVM*);
/* 0x71 */  void ccvm_instructions_math_add_stack_num(CCVM*);
/* 0x72 */  void ccvm_instructions_math_sub_reg_num(CCVM*);
/* 0x73 */  void ccvm_instructions_math_sub_stack_num(CCVM*);
/* 0x74 */  void ccvm_instructions_math_mul_reg_num(CCVM*);
/* 0x75 */  void ccvm_instructions_math_mul_stack_num(CCVM*);
/* 0x76 */  void ccvm_instructions_math_div_reg_num(CCVM*);
/* 0x77 */  void ccvm_instructions_math_div_stack_num(CCVM*);
/* 0x78 */  void ccvm_instructions_math_and_reg_num(CCVM*);
/* 0x79 */  void ccvm_instructions_math_and_stack_num(CCVM*);
/* 0x7a */  void ccvm_instructions_math_or_reg_num(CCVM*);
/* 0x7b */  void ccvm_instructions_math_or_stack_num(CCVM*);
/* 0x7c */  void ccvm_instructions_math_xor_reg_num(CCVM*);
/* 0x7d */  void ccvm_instructions_math_xor_stack_num(CCVM*);
/* 0x7e */  void ccvm_instructions_math_rand_reg(CCVM*);// todo
/* 0x7f */  void ccvm_instructions_math_rand_stack(CCVM*);// todo
/* 0x80 */  void ccvm_instructions_math_pow_reg(CCVM*);// todo
/* 0x81 */  void ccvm_instructions_math_pow_stack(CCVM*);// todo
/* 0x82 */  void ccvm_instructions_math_pow_reg_num(CCVM*);// todo
/* 0x83 */  void ccvm_instructions_math_pow_stack_num(CCVM*);// todo
/* 0x84 */  void ccvm_instructions_math_sqrt_reg(CCVM*);// todo
/* 0x85 */  void ccvm_instructions_math_sqrt_stack(CCVM*);// todo

/* 0x8a */  void ccvm_instructions_math_root_reg_num(CCVM*);// todo
/* 0x8b */  void ccvm_instructions_math_root_stack_num(CCVM*);// todo
/* 0x8e */  void ccvm_instructions_math_mod_reg_num(CCVM*);// todo
/* 0x8f */  void ccvm_instructions_math_mod_stack_num(CCVM*);// todo
// end of all new

/* 0xff */	void ccvm_instructions_syscall(CCVM*);

extern void (*ccvm_instructionset[256])(CCVM*);
#endif
