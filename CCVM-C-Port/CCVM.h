#ifndef ccvm_guard
#define ccvm_guard

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "flags/flags.h"
#include "stack/stack.h"

// macro to create a default version of the ccvm
#define CCVM_DEFAULT {0};

typedef struct CCVM {
	uint32_t ccvm_registers[4];
	ccvm_flagset flags;
	uint8_t *bytecode;
	ccvm_stack stack;
	uint32_t *memory;
	uint32_t pc;
	uint32_t sbp;

	size_t program_length;
} CCVM;

#include "instructionset/instructionset.h"

// main executation functionality
void ccvm_load_program(CCVM* vm, char* program);	// loads a program into the bytecode array of a VM

uint8_t ccvm_fetch_opcode(CCVM* vm);				// fetches an opcode from program and sets it as instruction
uint16_t ccvm_fetch_integer(CCVM* vm);				// fetches an opcode from program and returns it
uint8_t ccvm_fetch_register(CCVM* vm);				// fetches an opcode from program and returns it

void ccvm_debug_registers(CCVM* vm);				// prints registers
void ccvm_debug_memory(CCVM* vm);					// prints memory
void ccvm_debug_program(CCVM* vm);					// prints program data

void ccvm_step(CCVM* vm);								// run a single CPU clockcycle
void ccvm_run(CCVM* vm);								// run the VM continuously

#endif