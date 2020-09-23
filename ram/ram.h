#ifndef ccvm_ram_guard
#define ccvm_ram_guard

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../CCVM.h"

typedef struct CCVM CCVM;

/*
	Custom data structure that dynamically allocates 32 bit values to the memory
	it will grow when needed but it will not grow bigger then it needs to, it will
	not shrink ever, unless someone manually calls the ccvm_ram_grow function
	with a lower value that the current capacity
*/
typedef struct ccvm_ram {
	uint32_t* memory;
	size_t capacity;
} ccvm_ram;

// function to write a value to a specified
// location in memory
void ccvm_ram_write(ccvm_ram*, uint32_t, uint32_t);

// function to read & return a value from
// a specified location in memory
uint32_t ccvm_ram_read(ccvm_ram*, uint32_t);

// function to initioalize a new memory block
// with a small amount of pre-allocated memory
ccvm_ram* ccvm_ram_init();

// function to grow the memory realocated the memory
// to some specified size
void ccvm_ram_grow(ccvm_ram*, size_t);

// function to print a page of the memory
// neatly in the console
void ccvm_ram_debug(CCVM*);



#endif