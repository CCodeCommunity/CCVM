#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

ccvm_stack ccvm_stack_init() {
    ccvm_stack target;
    target.ptr = (int32_t*) malloc(target.capacity * sizeof(int32_t));
    target.length = 0;
    target.capacity = 100;

    return target;
}

void ccvm_stack_push(ccvm_stack* target, int32_t value) {
    if (target->length >= target->capacity) {
        target->ptr = (int32_t*) realloc(target->ptr, target->capacity * sizeof(int32_t));
        target->capacity = target->capacity * sizeof(int32_t);
    }
    
    target->ptr[target->length] = value;
    target->length++;
}

int32_t ccvm_strack_pop(ccvm_stack* target) {
    int32_t value = target->ptr[target->length - 1];
    target->ptr[target->length] = 0;

    target->length--;
    return value;
}

int32_t ccvm_stack_peek(ccvm_stack* target) {
    return target->ptr[target->length - 1];
}

void ccvm_stack_delete(ccvm_stack* target) {
    free(target);
}

void ccvm_debug_stack(ccvm_stack* target) {
    printf("length = %d; capacity = %d \n", target->length, target->capacity);

    if (target->length == 0) {
        puts("*empty*");
        return;
    }

    int index = 0;
    
    while (index <= target->capacity) {
        printf("%d ", target->ptr[index]);

        if (index % 50 == 0) {
            printf("\n");
        }

        if (index == (target->capacity -1)) {
            printf("\n");
        }

        index++;
    }
}