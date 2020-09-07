#include "CCVM.h"

CCVM ccvm_create_ccvm() {
	CCVM ret = {0};
	return ret;
}

void ccvm_load_program(CCVM* vm, char *filename) {
	// open file
	FILE *fp = fopen(filename, "rb");

	// get buffer size
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// buffer allocation
	unsigned char *buffer = (unsigned char *) malloc(size);

	// error detection
	if (fp == NULL) {
		printf("[ERROR] could not open file: %s", filename);
		exit(1);
	} else if(fread(buffer, sizeof *buffer, size, fp) != size) {
		printf("[ERROR] while reading file: %s", filename);
		exit(1);
	}

	vm->bytecode = buffer;
	vm->program_length = size;
}

void ccvm_debug_program(CCVM* vm) {
	for (int i = 0; i < vm->program_length; i++) {
		printf("0x%.2x ", vm->bytecode[i]);
	}
}

void ccvm_step(CCVM* vm) {
	uint8_t instruction = vm->bytecode[vm->pc];
	int a = 5;
	ccvm_instructionset[instruction](&a);
}

void ccvm_run(CCVM* vm) {
	while (!ccvm_flags_get(&vm->flags, ccvm_flag_stop)) {
		ccvm_step(vm);	
		vm->pc++;
	}
}