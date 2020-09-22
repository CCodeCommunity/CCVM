#include "instructionset.h"
#include "../stack/stack.h"
#include "../CCVM.h"

int fetchLit(CCVM* vm) {
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
void ccvm_instructions_exit(CCVM* vm) {
    ccvm_flags_set(&vm->flags, ccvm_flag_stop, 1);
}

void ccvm_instructions_push_lit(CCVM* vm) {
	ccvm_stack_push(vm->stack, fetchLit(vm));
}

void ccvm_instructions_mov_lit_reg(CCVM* vm) {
	char reg = fetchReg(vm);
	int lit = fetchLit(vm);

	vm->registers[reg] = lit;
}

void ccvm_instructions_nop(CCVM* vm) {

}