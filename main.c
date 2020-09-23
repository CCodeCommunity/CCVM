#include "stdio.h"
#include "CCVM.h"
#include "flags/flags.h"

// gcc main.c CCVM.c flags/flags.c instructionset/instructionset.c stack/stack.c -o ccvm
// cloc main.c CCVM.c CCVM.h stack instructionset flags

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		puts("[ERROR] Please give a valid .ccb file");
		return 1;
	} else {
		CCVM vm = ccvm_create_ccvm();
		
		ccvm_program_load(&vm, argv[1]);
		ccvm_program_debug(&vm);
		puts("");

		ccvm_program_run(&vm);
		puts(""); // remove

		ccvm_stack_debug(&vm);
		puts("");

		ccvm_registers_debug(&vm);
		puts("");

		ccvm_flags_debug(&vm);
		puts("");
	}

	return 0;
}