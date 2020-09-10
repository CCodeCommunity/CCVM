#include "stdio.h"
#include "CCVM.h"

#include "stack/stack.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		puts("[ERROR] Please give a valid .ccb file");
		return 1;
	} else {
		CCVM vm = CCVM_DEFAULT;
		ccvm_load_program(&vm, argv[1]);
		ccvm_run(&vm);

		puts("\nflags:");
		ccvm_debug_flags(&vm.flags);

		puts("\nstack:");
		ccvm_debug_stack(&vm.stack);
	}

	return 0;
}