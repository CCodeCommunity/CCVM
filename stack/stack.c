#include <stdint.h>
#include <stdlib.h>
#include "stack.h"

ccvm_stack ccvm_stack_init() {
    ccvm_stack target;
    target.ptr = (int32_t*) malloc(target.size * sizeof(int32_t));

    return target;
}

void ccvm_push(ccvm_stack* target, int32_t value) {
    if (target->index > 100) {
        target->ptr = (int32_t*) realoc(target->ptr, target->size * sizeof(int32_t));
    }

    target->ptr[target->index] = value;
    target->index++;
}

int32_t ccvm_pop(ccvm_stack* target) {
    int32_t value = target->ptr[target->index];
    free(target->ptr[target->index]);
    
    target->index--;
    return value;
}

int32_t ccvm_peek(ccvm_stack* target) {
    return target->ptr[target->index];
}

void ccvm_stack_delete(ccvm_stack* target) {
    free(target);
}