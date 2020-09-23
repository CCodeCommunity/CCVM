#include "instructionset.h"
#include "../stack/stack.h"
#include "../flags/flags.h"
#include "../CCVM.h"

#include <limits.h>

uint32_t fetchLit(CCVM* vm) {
	int n = 0;

	for (int i = 1; i <= 4; i++) {
		n = (n << 8) + vm->bytecode[vm->pc + i];
	}

	vm->pc += 4;

	return n;
}

char fetchReg(CCVM* vm) {
	vm->pc++;
	return vm->bytecode[vm->pc];
}

// ---- opcodes ----

// [opcode(1)] 1b
void ccvm_instructions_exit(CCVM* vm) {
    ccvm_flags_set(&vm->flags, ccvm_flag_stop, 1);
}

// [opcode(1) literal(4)] 5b
void ccvm_instructions_push_lit(CCVM* vm) {
	ccvm_stack_push(vm->stack, fetchLit(vm));
}

// [opcode(1) literal(4) register(1)] 6b
void ccvm_instructions_mov_lit_reg(CCVM* vm) {
	char reg = fetchReg(vm);
	int lit = fetchLit(vm);

	vm->registers[reg] = lit;
}

// [opcode(1) register(1)] 2b
void ccvm_instructions_push_reg(CCVM* vm) {
	ccvm_stack_push(vm->stack, vm->registers[fetchReg(vm)]);
};

// [opcode(1)] 1b 
void ccvm_instructions_stack_dupe(CCVM* vm) {
	ccvm_stack_push(vm->stack, ccvm_stack_peek(vm->stack));
}

// [opcode(1) register(1)] 2b
void ccvm_instructions_pop_reg(CCVM* vm) {
	vm->registers[fetchReg(vm)] = ccvm_stack_pop(vm->stack);
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_math_add_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);
	
	if (vm->registers[a] > UINT_MAX - vm->registers[b]) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	vm->registers[a] += vm->registers[b];
}


void ccvm_instructions_math_sub_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);
	
	if (vm->registers[a] < vm->registers[b]) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	vm->registers[a] -= vm->registers[b];
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_math_mul_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);

	if (vm->registers[a] > UINT_MAX / (uint64_t)vm->registers[b]) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	vm->registers[a] *= vm->registers[b];
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_math_div_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);
	vm->registers[a] /= vm->registers[b];
	// no overflow check needed
	// since integer division can not
	// cause overflow
}

// [opcode(1) register(1)] 3b
void ccvm_instructions_math_not_reg(CCVM* vm) {
	char n = fetchReg(vm);
	vm->registers[n] = ~vm->registers[n];
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_math_and_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);
	vm->registers[a] &= vm->registers[b];
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_math_or_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);
	vm->registers[a] |= vm->registers[b];
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_math_xor_reg(CCVM* vm) {
	char a = fetchReg(vm);
	char b = fetchReg(vm);
	vm->registers[a] ^= vm->registers[b];
}

// [opcode(1)] 1b
void ccvm_instructions_math_add_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a + b);

	if (a > UINT_MAX - b) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}
}

// [opcode(1)] 1b
void ccvm_instructions_math_sub_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a - b);

	if (a < b) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}
}

// [opcode(1)] 1b
void ccvm_instructions_math_mul_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a * b);

	if (a > UINT_MAX / (uint64_t)b) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}
}

// [opcode(1)] 1b
void ccvm_instructions_math_div_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a / b);

	// no overflow check needed
	// since integer division can not
	// cause overflow
}

// [opcode(1)] 1b
void ccvm_instructions_math_not_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, ~a);
}

// [opcode(1)] 1b
void ccvm_instructions_math_and_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a & b);
}

// [opcode(1)] 1b
void ccvm_instructions_math_or_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a | b);
}

// [opcode(1)] 1b
void ccvm_instructions_math_xor_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);
	uint32_t b = ccvm_stack_pop(vm->stack);
	ccvm_stack_push(vm->stack, a ^ b);
}

// [] 0b
void ccvm_instructions_nop(CCVM* vm) {}