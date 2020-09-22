#include "instructionset.h"
#include "../stack/stack.h"
#include "../CCVM.h"

int fetchLit(CCVM* vm) {
	int n = 0;

	for (int i = 1; i <= 4; i++) {
		n = (n << 8) + vm->bytecode[vm->pc + i];
	}

	return n;
	vm->pc += 4;
}

// ---- opcodes ----
void ccvm_instructions_exit(CCVM* vm) {
	puts("here\n");
    ccvm_flags_set(&vm->flags, ccvm_flag_stop, 1);
}

void ccvm_instructions_push_lit(CCVM* vm) {
	ccvm_stack_push(vm->stack, fetchLit(vm));
}