#include <stdio.h>
#include <string.h>
#include <ccvm/CCVM.h>

// gcc main.c CCVM.c flags/flags.c instructionset/instructionset.c stack/stack.c ram/ram.c -o ccvm
// cloc main.c CCVM.c CCVM.h stack instructionset flags ram

#include "stdio.h"
#include <ccvm/CCVM.h>
#include <ccvm/stack.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        puts("[ERROR] Please give a valid .ccb file");
        return 1;
    } else {
        CCVM vm = ccvm_create_ccvm();
        ccvm_program_load(&vm, argv[1]);
        ccvm_program_run(&vm);
    }

    return 0;
}