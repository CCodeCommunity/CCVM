#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "flags/flags.h"

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
	uint8_t *ccvm_bytecode;
	uint32_t *ccvm_stack;
	uint32_t *ccvm_memory;
	uint32_t ccvm_pc;
	uint32_t ccvm_sbp;

	size_t ccvm_program_length;
} CCVM;

// main executation functionality
CCVM 	ccvm_create_ccvm();                   	// returns a new fresh VM with default state
void ccvm_load_program(CCVM*, char *);			// loads a program into the bytecode array of a VM

uint8_t ccvm_fetch_opcode(CCVM*);				// fetches an opcode from program and sets it as instruction
uint16_t ccvm_fetch_integer(CCVM*);				// fetches an opcode from program and returns it
uint8_t ccvm_fetch_register(CCVM*);				// fetches an opcode from program and returns it

void ccvm_debug_registers(CCVM*);				// prints registers
void ccvm_debug_memory(CCVM*);					// prints memory
void ccvm_debug_program(CCVM*);					// prints program data
void ccvm_debug_flags(CCVM*);					// prints flags
void ccvm_debug_stack(CCVM*);					// prints stack

void ccvm_step();								// run a single CPU clockcycle
void ccvm_run();								// run the VM continuously