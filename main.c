#include "stdio.h"
#include "CCVM.h"
#include "flags/flags.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		puts("[ERROR] Please give a valid .ccb file");
		return 1;
	} else {
		CCVM vm = ccvm_create_ccvm();
		ccvm_load_program(&vm, argv[1]);
		ccvm_debug_program(&vm);
	}

	return 0;
}