#include <stdio.h>
#include <string.h>
#include "CCVM.h"
#include "flags/flags.h"
#include "ram/ram.h"

// gcc main.c CCVM.c flags/flags.c instructionset/instructionset.c stack/stack.c ram/ram.c -o ccvm
// cloc main.c CCVM.c CCVM.h stack instructionset flags ram

int main(int argc, char* argv[]) {
	char debug = 0;

	if (argc >= 3 && strcmp(argv[2], "-d") == 0) {
		debug = 1;
	}

	if (argc <= 1) {
		puts("[ERROR] Please give a valid .ccb file");
		return 1;
	} else {
		CCVM vm = ccvm_create_ccvm();

		ccvm_program_load(&vm, argv[1]);

		// ccvm_program_debug(&vm);
		ccvm_program_run(&vm);

		if (debug == 1) {
			ccvm_stack_debug(&vm);

			ccvm_registers_debug(&vm);
			puts("");

			ccvm_flags_debug(&vm);
			puts("");

			ccvm_ram_debug(&vm);
			puts("");
		}
	}

	return 0;
}