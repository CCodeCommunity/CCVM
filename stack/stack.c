#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "../CCVM.h"

ccvm_stack* ccvm_stack_init() {
    ccvm_stack* target = malloc(sizeof(ccvm_stack));
    target->capacity = 100;
    target->length = 0;
    target->ptr = (uint32_t*) malloc(target->capacity * sizeof(uint32_t));
    return target;
}

void ccvm_stack_push(ccvm_stack* target, uint32_t value) {
    if (target->length > target->capacity) {
        target->ptr = (uint32_t*) realloc(target->ptr, target->capacity * sizeof(uint32_t));
        target->capacity = target->capacity * sizeof(uint32_t);
    }

    target->ptr[target->length] = value;

    target->length++;
}

uint32_t ccvm_stack_pop(ccvm_stack* target) {
    uint32_t value = target->ptr[target->length - 1];
    target->ptr[target->length] = 0;

    target->length--;
    return value;
}

uint32_t ccvm_stack_peek(ccvm_stack* target) {
    return target->ptr[target->length - 1];
}

void ccvm_stack_delete(ccvm_stack* target) {
    free(target);
}

void ccvm_stack_debug(CCVM* target) {
    printf("stack: length: %d capacity: %d \n", target->stack->length, target->stack->capacity);
    
    if (target->stack->length == 0) {
        puts("\t*empty*\n");
        return;
    }

    for (int i = target->stack->length - 1; i >= 0; i--) {
        printf("\t%u\n", target->stack->ptr[i]);
    }
}