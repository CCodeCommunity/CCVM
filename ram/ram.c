#include "ram.h"
#define BEGIN_SIZE 1

// helpers
uint32_t limit(n, max) {
	return n < max ? n : max;
}

// ram functions
ccvm_ram* ccvm_ram_init() {
	ccvm_ram* ram = malloc(sizeof(ccvm_ram));
	ram->capacity = 10;
	ram->memory = (uint32_t*) malloc(10 * sizeof(uint32_t));
	return ram;
}

uint32_t ccvm_ram_read(ccvm_ram* ram, uint32_t addr) {
	if (addr >= ram->capacity) {
		ccvm_ram_grow(ram, addr+1);
	}

	return ram->memory[addr];
}

void ccvm_ram_write(ccvm_ram* ram, uint32_t addr, uint32_t val) {
	if (addr >= ram->capacity) {
		ccvm_ram_grow(ram, addr+1);
	}

	ram->memory[addr] = val;
}

void ccvm_ram_grow(ccvm_ram* ram, size_t newCapacity) {
	ram->memory = realloc(ram->memory, newCapacity * sizeof(uint32_t));
	ram->capacity = newCapacity;
}

void ccvm_ram_debug(CCVM* vm) {
	for (int i = 0; i <= (vm->ram->capacity); i++) {
		printf("%d\n", i);
		if (i == 1) {
			//printf("[0x000] ");
		}

		printf("0x%.8x ", ccvm_ram_read(vm->ram, i));

		if (i % 10 == 0 && i != limit(vm->ram->capacity, 1000)) {
			//printf("\n[0x%.3x] ", i);
		}
	}
}