#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../CCVM.h"

typedef void (*instruction)(CCVM*);
instruction ccvm_instructionset[256];

void ccvm_instructions_exit(CCVM* vm);

#endif