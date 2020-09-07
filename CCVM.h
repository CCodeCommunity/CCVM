#ifndef ccvm_guard
#define ccvm_guard

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "flags/flags.h"
#include "instructionset/instructionset.h"

/*
	An enum to reference the registers more conveniently
	inside an instance of a VM 
*/
typedef enum ccvm_Register {
	CCVM_A, CCVM_B, CCVM_C, CCVM_D
} ccvm_Register;

/*
	The vm structs packs all the info needed for a VM
	
	registers:
		An array of 4 uint32's to store individual 32bit unsigned integers
	
	bytecode:
		An array of opcodes and meta data that represents the program that has
		to be ran on the virtual machine
	
	PC:
		The program counter, an 32bit unsigned integer that keeps track of what
		byte is currently being read on the bytecode array

	SBP:
		A 32bit unsigned integer that keeps track of what index the base of the
		stack array is position

	stack:
		A first in last out data structure of unsigned 32 bit integers to store
		larger amount of data on the VM

	memory:
		A 32 bit unsigned integer array representing the RAM memory of the VM

	program_length:
		The length of the bytecode array
*/
typedef struct CCVM {
	uint32_t ccvm_registers[4];
	ccvm_flagset flags;
	uint8_t *bytecode;
	uint32_t *stack;
	uint32_t *memory;
	uint32_t pc;
	uint32_t sbp;

	size_t program_length;
} CCVM;

// main executation functionality
CCVM 	ccvm_create_ccvm();                   		// returns a new fresh VM with default state
void ccvm_load_program(CCVM* vm, char* program);	// loads a program into the bytecode array of a VM

uint8_t ccvm_fetch_opcode(CCVM* vm);				// fetches an opcode from program and sets it as instruction
uint16_t ccvm_fetch_integer(CCVM* vm);				// fetches an opcode from program and returns it
uint8_t ccvm_fetch_register(CCVM* vm);				// fetches an opcode from program and returns it

void ccvm_debug_registers(CCVM* vm);				// prints registers
void ccvm_debug_memory(CCVM* vm);					// prints memory
void ccvm_debug_program(CCVM* vm);					// prints program data
void ccvm_debug_flags(CCVM* vm);					// prints flags
void ccvm_debug_stack(CCVM* vm);					// prints stack

void ccvm_step(CCVM* vm);								// run a single CPU clockcycle
void ccvm_run(CCVM* vm);								// run the VM continuously

#endif