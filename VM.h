#include <stdint.h>

/*
	An enum to reference the registers more conveniently
	inside an instance of a VM 
*/
enum Register {
	A, B, C, D
};

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
*/
typedef struct {
	uint32_t registers[4];
	uint8_t *bytecode;
	uint32_t *stack;
	uint32_t *memory;
	uint32_t PC;
	uint32_t SBP;
} VM;

// main executation functionality
VM 	 vm_createNewVM();                      // returns a new fresh VM with default state
void vm_loadProgram(VM*, char *filename);	// loads a program into the bytecode array of a VM
uint8_t vm_fetch_opcode(VM*);				// fetches an opcode from program and sets it as instruction
uint16_t vm_fetch_integer(VM*);				// fetches an opcode from program and returns it
uint8_t vm_fetch_register(VM*);				// fetches an opcode from program and returns it
void vm_step();								// run a single CPU clockcycle
void vm_run();								// run the VM continuously