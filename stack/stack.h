#ifndef stack_guard
#define stack_guard

#include <stdint.h>

/*
Custom data structure that dynamically allocates 32 bit values to the memory
*/

struct ccvm_stack {
    int size;
    int32_t index;
    int32_t* ptr;
};


// inits a stack with 400 bytes
void ccvm_stack_init(struct ccvm_stack* target);

void ccvm_push(struct ccvm_stack* target, int32_t value);
int32_t ccvm_pop(struct ccvm_stack* target);
int32_t ccvm_peek(struct ccvm_stack* target);
void ccvm_stack_delete(struct ccvm_stack* target);

#endif