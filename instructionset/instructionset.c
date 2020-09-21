#include "instructionset.h"
#include "../CCVM.h"

void ccvm_instructions_exit(CCVM* vm) {
    ccvm_flags_set(&vm->flags, ccvm_flag_stop, 1);
}
