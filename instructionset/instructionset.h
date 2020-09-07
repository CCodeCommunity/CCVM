#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../CCVM.h"
#include "../flags/flags.h"

void ccvm_instructions_exit(CCVM* vm);

void (*ccvm_instructionset[256])(CCVM*) = {
   ccvm_instructions_exit
};

#endif