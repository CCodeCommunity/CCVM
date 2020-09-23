#include "CCVM.h"

#define debug 1

void (*ccvm_instructionset[256])(CCVM*) = {
  /* 0x00 */ ccvm_instructions_exit,
  /* 0x01 */ ccvm_instructions_push_lit,
  /* 0x02 */ ccvm_instructions_push_reg,
  /* 0x03 */ ccvm_instructions_pop_reg,
  /* 0x04 */ ccvm_instructions_nop, // TODO
  /* 0x05 */ ccvm_instructions_stack_dupe,
  /* 0x06 */ ccvm_instructions_mov_lit_reg,
  /* 0x07 */ ccvm_instructions_nop, // TODO
  /* 0x08 */ ccvm_instructions_nop, // TODO
  /* 0x09 */ ccvm_instructions_nop, // TODO
  /* 0x0a */ ccvm_instructions_nop,
  /* 0x0b */ ccvm_instructions_nop,
  /* 0x0c */ ccvm_instructions_nop,
  /* 0x0d */ ccvm_instructions_nop,
  /* 0x0e */ ccvm_instructions_nop,
  /* 0x0f */ ccvm_instructions_nop,
  /* 0x10 */ ccvm_instructions_math_add_reg,
  /* 0x11 */ ccvm_instructions_math_add_stack,
  /* 0x12 */ ccvm_instructions_math_sub_reg,
  /* 0x13 */ ccvm_instructions_math_sub_stack,
  /* 0x14 */ ccvm_instructions_math_mul_reg,
  /* 0x15 */ ccvm_instructions_math_mul_stack,
  /* 0x16 */ ccvm_instructions_math_div_reg,
  /* 0x17 */ ccvm_instructions_math_div_stack,
  /* 0x18 */ ccvm_instructions_math_not_reg,
  /* 0x19 */ ccvm_instructions_math_not_stack,
  /* 0x1a */ ccvm_instructions_math_and_reg,
  /* 0x1b */ ccvm_instructions_math_and_stack,
  /* 0x1c */ ccvm_instructions_math_or_reg,
  /* 0x1d */ ccvm_instructions_math_or_stack,
  /* 0x1e */ ccvm_instructions_math_xor_reg,
  /* 0x1f */ ccvm_instructions_math_xor_stack,
};

CCVM ccvm_create_ccvm() {
    CCVM ret = {0};
    return ret;
}

void ccvm_program_load(CCVM* vm, char *filename) {
    // open file
    FILE *fp = fopen(filename, "rb");

    // get buffer size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // buffer allocation
    unsigned char *buffer = (unsigned char *) malloc(size);

    // error detection
    if (fp == NULL) {
        printf("[ERROR] could not open file: %s", filename);
        exit(1);
    } else if(fread(buffer, sizeof *buffer, size, fp) != size) {
        printf("[ERROR] while reading file: %s", filename);
        exit(1);
    }

    vm->bytecode = buffer;
    vm->program_length = size;
}

void ccvm_program_debug(CCVM* vm) {
    for (int i = 0; i < vm->program_length; i++) {
        printf("0x%.2x ", vm->bytecode[i]);
    }
    puts("");
}

void ccvm_program_step(CCVM* vm) {
    uint8_t instruction = vm->bytecode[vm->pc];
    printf("[DEBUG] doing instruction %d\n", instruction);
    ccvm_instructionset[instruction](vm);
}

void ccvm_program_run(CCVM* vm) {
    vm->stack = ccvm_stack_init();
    while (!ccvm_flags_get(&vm->flags, ccvm_flag_stop)) {
        ccvm_program_step(vm);    
        vm->pc++;
    }
}

void ccvm_registers_debug(CCVM* vm) {
    printf("registers:\n\ta = %u\n\tb = %u\n\tc = %u\n\tc = %u\n", vm->registers[0], vm->registers[1], vm->registers[2], vm->registers[3]);
}