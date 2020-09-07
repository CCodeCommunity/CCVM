#include <stdint.h>
#include "stack.h"

void ccvm_stack_init(struct ccvm_stack* target) {
    target->ptr = (int32_t*) malloc(target->size * sizeof(int32_t));
}

void ccvm_push(struct ccvm_stack* target, int32_t value) {
    if (target->index > 100) {
        target->ptr = (int32_t*) realoc(target->ptr, target->size * sizeof(int32_t));
    }

    target->index++;
    target->ptr[target->index] = value;
}

int32_t ccvm_pop(struct ccvm_stack* target) {
    
}

void ccvm_stack_delete(struct ccvm_stack* target) {
    free(target);
}