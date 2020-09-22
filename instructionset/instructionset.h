#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../flags/flags.h"

typedef struct CCVM CCVM;

void ccvm_instructions_exit(CCVM* vm);
void ccvm_instructions_push_lit(CCVM* vm);

extern void (*ccvm_instructionset[256])(CCVM*);
#endif