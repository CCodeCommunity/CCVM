#include <stdio.h>
#include <string.h>
#include <ccvm/CCVM.h>

#include "stdio.h"
#include <ccvm/CCVM.h>
#include <ccvm/stack.h>

#define DEBUG 1

// count lines of code in this project:
// codel count -e .c .h ^C


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