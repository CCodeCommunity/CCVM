#ifndef stack_guard
#define stack_guard

#include <stdint.h>

/*
Custom data structure that dynamically allocates 32 bit values to the memory
*/

typedef struct ccvm_stack {
    int capacity;
    int32_t length;
    int32_t* ptr;
} ccvm_stack;


// inits a stack with 400 bytes
ccvm_stack ccvm_stack_init();

// pushes a 32 bit value to the stack
void ccvm_push(ccvm_stack* target, int32_t value);

// deletes a 32 bit value from the top of the stack and returns it
int32_t ccvm_pop(ccvm_stack* target);

// returns the value from the top of the stack
int32_t ccvm_peek(ccvm_stack* target);

// frees all memory from ccvm_stack
void ccvm_stack_delete(ccvm_stack* target);

// neatly prints out information about the stack along with its contents
void ccvm_stack_debug(ccvm_stack* target);

#endif