#include "instructionset.h"
#include "../stack/stack.h"
#include "../flags/flags.h"
#include "../CCVM.h"

#include <limits.h>

/*
// clear screen on windows
#ifdef _WIN32
#include <windows.h>
void clearScreen(void) {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {0, 0};
    DWORD dwCount, dwSize;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOutput, &csbi);
    dwSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hOutput, 0x20, dwSize, topLeft, &dwCount);
    FillConsoleOutputAttribute(hOutput, 0x07, dwSize, topLeft, &dwCount);
    SetConsoleCursorPosition(hOutput, topLeft);
}
#endif

// clear sceen on UNIX systems
#ifdef __unix__
#include <stdio.h>
void clearScreen(void) {
    printf("\x1B[2J");
}
#endif
*/

void clearScreen(void) {
	system("cls || clear");
}

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

void compareNumbers(CCVM* vm, uint32_t a, uint32_t b) {
	ccvm_flags_set(&vm->flags, ccvm_flag_equal, a == b);
	ccvm_flags_set(&vm->flags, ccvm_flag_not_equal, a != b);
	ccvm_flags_set(&vm->flags, ccvm_flag_greater, a > b);
	ccvm_flags_set(&vm->flags, ccvm_flag_smaller, a < b);
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

// [opcode(1) register(1)] 2b
void ccvm_instructions_math_inc_reg(CCVM* vm) {
	char a = fetchReg(vm);

	if (vm->registers[a] == UINT_MAX) {
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	vm->registers[a]++;
}

// [opcode(1) register(1)] 2b
void ccvm_instructions_math_dec_reg(CCVM* vm) {
	char a = fetchReg(vm);

	if (vm->registers[a] == 0) {
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	vm->registers[a]--;
}

// [opcode(1)] 1b
void ccvm_instructions_math_inc_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);

	if (a == UINT_MAX) {
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	ccvm_stack_push(vm->stack, ++a);
}

// [opcode(1)] 1b
void ccvm_instructions_math_dec_stack(CCVM* vm) {
	uint32_t a = ccvm_stack_pop(vm->stack);

	if (a == 0) {
		ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 1);
	}

	ccvm_stack_push(vm->stack, ++a);
}

// [opcode(1) register(1) register(1)] 3b
void ccvm_instructions_compare_reg_reg(CCVM* vm) {
	char a = vm->registers[fetchReg(vm)];
	char b = vm->registers[fetchReg(vm)];
	compareNumbers(vm, a, b);
}

// [opcode(1) register(1) literal(4)] 6b
void ccvm_instructions_compare_reg_lit(CCVM* vm) {
	uint32_t a = vm->registers[fetchReg(vm)];
	uint32_t b = fetchLit(vm);
	compareNumbers(vm, a, b);
}

// [opcode(1) register(1) literal(4)] 6b
void ccvm_instructions_compare_stack_lit(CCVM* vm) {
	uint32_t a = ccvm_stack_peek(vm->stack);
	uint32_t b = fetchLit(vm);
	compareNumbers(vm, a, b);
}

// [opcode(1)] 1b
void ccvm_instructions_flag_reset(CCVM* vm) {
	ccvm_flags_set(&vm->flags, ccvm_flag_equal, 0);
	ccvm_flags_set(&vm->flags, ccvm_flag_not_equal, 0);
	ccvm_flags_set(&vm->flags, ccvm_flag_greater, 0);
	ccvm_flags_set(&vm->flags, ccvm_flag_smaller, 0);
	ccvm_flags_set(&vm->flags, ccvm_flag_overflow, 0);
}

// [opcode(1)] 1b
void ccvm_instructions_syscall(CCVM* vm) {
	switch (vm->registers[0]) {
		case 0: {
			// cout
		}

		case 1: {
			// cin
		}

		case 2: {
			// cclear
			clearScreen();
		}
	}
}

// [] 0b
void ccvm_instructions_nop(CCVM* vm) {
	puts("[INFO] nop called");
}