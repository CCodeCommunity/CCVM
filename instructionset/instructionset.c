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
	puts("hey");
	char a = fetchReg(vm);
	char b = fetchReg(vm);

	vm->registers[a] += vm->registers[b];
	if (a > INT_MAX - b) { // overflow check
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}
}

// [] 0b
void ccvm_instructions_nop(CCVM* vm) {}