#include <stdio.h>
#include <string.h>
#include "CCVM.h"
#include "flags/flags.h"
#include "ram/ram.h"

// gcc main.c CCVM.c flags/flags.c instructionset/instructionset.c stack/stack.c ram/ram.c -o ccvm
// cloc main.c CCVM.c CCVM.h stack instructionset flags ram

int matchStr(char* a, char* b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) {
        puts("[ERROR] Please give a valid .ccb file");
        return 1;
    }

	puts("CCBD V1");

    CCVM vm = ccvm_create_ccvm();

    ccvm_program_load(&vm, argv[1]);

    // ccvm_program_run(&vm);
    char command[100];

    while (1) {
        printf(">> ");

        fgets(command, 100, stdin);

        if (matchStr(command, "exit\0", 5)) {
            break;
        }

        else {
            command[strlen(command) - 1] = 0x0;
            printf("ERROR: unknown CCBD command '%s'\n\n", command);
        }
    }
}