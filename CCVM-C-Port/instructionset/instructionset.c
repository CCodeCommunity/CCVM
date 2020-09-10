#include "instructionset.h"

uint32_t ccvm_fetch32(CCVM* vm) {
    uint32_t value = 0;
    
    for (int i = 0; i < 4; i++) {
        char byte = vm->bytecode[++vm->pc];
        value = (value << 8) + byte;
    }

    return value;
}

void ccvm_instructions_exit(CCVM* vm) {
    ccvm_flags_set(&vm->flags, ccvm_flag_stop, 1);
}

void ccvm_instructions_push_lit(CCVM* vm) {
    uint32_t value = ccvm_fetch32(vm);
    ccvm_stack_push(&vm->stack, value);
}



instruction ccvm_instructionset[256] = {ccvm_instructions_exit, ccvm_instructions_push_lit};