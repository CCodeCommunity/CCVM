#ifndef stack_guard
#define stack_guard

#include <stdint.h>

/*
Custom data structure that dynamically allocates 32 bit values to the memory
*/

typedef struct CCVM CCVM;

typedef struct ccvm_stack {
    uint32_t capacity;
    uint32_t length;
    uint32_t* ptr;
} ccvm_stack;

// inits a stack with 400 bytes
ccvm_stack* ccvm_stack_init();

// pushes a 32 bit value to the stack
void ccvm_stack_push(ccvm_stack* target, uint32_t value);

// deletes a 32 bit value from the top of the stack and returns it
uint32_t ccvm_stack_pop(ccvm_stack* target);

// returns the value from the top of the stack
uint32_t ccvm_stack_peek(ccvm_stack* target);

// frees all memory from ccvm_stack
void ccvm_stack_delete(ccvm_stack* target);

// neatly prints out information about the stack along with its contents
void ccvm_stack_debug(CCVM* target);

#endif