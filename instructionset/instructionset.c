#include "instructionset.h"

void ccvm_instructions_exit(CCVM* vm) {
    ccvm_flags_set(vm->flags, ccvm_flags_exit, 1);
}