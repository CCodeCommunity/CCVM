#include "VM.h"

VM vm_createNewVM() {
	VM ret = {
		.registers = {0, 0, 0, 0},
		.bytecode = NULL,
		.stack = NULL,
		.memory = NULL,
		.PC = 0,
		.SBP = 0,
	};
	return ret;
}