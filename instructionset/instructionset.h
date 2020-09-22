#ifndef ccvm_instructionset_guard
#define ccvm_instructionset_guard

#include "../flags/flags.h"

typedef struct CCVM CCVM;

void ccvm_instructions_exit(CCVM*);
void ccvm_instructions_push_lit(CCVM*);
void ccvm_instructions_nop(CCVM*);
void ccvm_instructions_mov_lit_reg(CCVM*);

extern void (*ccvm_instructionset[256])(CCVM*);
#endif