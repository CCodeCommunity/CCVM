#include "CCVM.h"

void (*ccvm_instructionset[256])(CCVM*) = {
  /* 0x00 */ ccvm_instructions_exit,
  /* 0x01 */ ccvm_instructions_push_lit,
  /* 0x02 */ ccvm_instructions_push_reg,
  /* 0x03 */ ccvm_instructions_pop_reg,
  /* 0x04 */ ccvm_instructions_pop_memory,
  /* 0x05 */ ccvm_instructions_stack_dupe,
  /* 0x06 */ ccvm_instructions_mov_lit_reg,
  /* 0x07 */ ccvm_instructions_mov_lit_mem,
  /* 0x08 */ ccvm_instructions_mov_mem_reg,
  /* 0x09 */ ccvm_instructions_mov_reg_mem,
  /* 0x0a */ ccvm_instructions_mov_reg_reg,
  /* 0x0b */ ccvm_instructions_mov_mem_mem,
  /* 0x0c */ ccvm_instructions_push_mem,
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
  /* 0x20 */ ccvm_instructions_jump_absolute,
  /* 0x21 */ ccvm_instructions_nop,
  /* 0x22 */ ccvm_instructions_nop,
  /* 0x23 */ ccvm_instructions_nop,
  /* 0x24 */ ccvm_instructions_nop,
  /* 0x25 */ ccvm_instructions_nop,
  /* 0x26 */ ccvm_instructions_nop,
  /* 0x27 */ ccvm_instructions_nop,
  /* 0x28 */ ccvm_instructions_nop,
  /* 0x29 */ ccvm_instructions_nop,
  /* 0x2a */ ccvm_instructions_nop,
  /* 0x2b */ ccvm_instructions_nop,
  /* 0x2c */ ccvm_instructions_nop,
  /* 0x2d */ ccvm_instructions_nop,
  /* 0x2e */ ccvm_instructions_nop,
  /* 0x2f */ ccvm_instructions_nop,
  /* 0x30 */ ccvm_instructions_compare_reg_reg,
  /* 0x31 */ ccvm_instructions_compare_reg_lit,
  /* 0x32 */ ccvm_instructions_compare_stack_lit,
  /* 0x33 */ ccvm_instructions_jump_equal,
  /* 0x34 */ ccvm_instructions_jump_notequal,
  /* 0x35 */ ccvm_instructions_jump_greater,
  /* 0x36 */ ccvm_instructions_jump_smaller,
  /* 0x37 */ ccvm_instructions_jump_overflow,
  /* 0x38 */ ccvm_instructions_nop,
  /* 0x39 */ ccvm_instructions_nop,
  /* 0x3a */ ccvm_instructions_nop,
  /* 0x3b */ ccvm_instructions_nop,
  /* 0x3c */ ccvm_instructions_nop,
  /* 0x3d */ ccvm_instructions_nop,
  /* 0x3e */ ccvm_instructions_nop,
  /* 0x3f */ ccvm_instructions_nop,
  /* 0x40 */ ccvm_instructions_flag_reset,
  /* 0x41 */ ccvm_instructions_nop,
  /* 0x42 */ ccvm_instructions_nop,
  /* 0x43 */ ccvm_instructions_nop,
  /* 0x44 */ ccvm_instructions_nop,
  /* 0x45 */ ccvm_instructions_nop,
  /* 0x46 */ ccvm_instructions_nop,
  /* 0x47 */ ccvm_instructions_nop,
  /* 0x48 */ ccvm_instructions_nop,
  /* 0x49 */ ccvm_instructions_nop,
  /* 0x4a */ ccvm_instructions_nop,
  /* 0x4b */ ccvm_instructions_nop,
  /* 0x4c */ ccvm_instructions_nop,
  /* 0x4d */ ccvm_instructions_nop,
  /* 0x4e */ ccvm_instructions_nop,
  /* 0x4f */ ccvm_instructions_nop,
  /* 0x50 */ ccvm_instructions_math_inc_reg,
  /* 0x51 */ ccvm_instructions_math_dec_reg,
  /* 0x52 */ ccvm_instructions_math_inc_stack,
  /* 0x53 */ ccvm_instructions_math_dec_stack,
  /* 0x54 */ ccvm_instructions_nop,
  /* 0x55 */ ccvm_instructions_nop,
  /* 0x56 */ ccvm_instructions_nop,
  /* 0x57 */ ccvm_instructions_nop,
  /* 0x58 */ ccvm_instructions_nop,
  /* 0x59 */ ccvm_instructions_nop,
  /* 0x5a */ ccvm_instructions_nop,
  /* 0x5b */ ccvm_instructions_nop,
  /* 0x5c */ ccvm_instructions_nop,
  /* 0x5d */ ccvm_instructions_nop,
  /* 0x5e */ ccvm_instructions_nop,
  /* 0x5f */ ccvm_instructions_nop,
  /* 0x60 */ ccvm_instructions_procedure_call,
  /* 0x61 */ ccvm_instructions_procedure_return,
  /* 0x62 */ ccvm_instructions_nop,
  /* 0x63 */ ccvm_instructions_nop,
  /* 0x64 */ ccvm_instructions_nop,
  /* 0x65 */ ccvm_instructions_nop,
  /* 0x66 */ ccvm_instructions_nop,
  /* 0x67 */ ccvm_instructions_nop,
  /* 0x68 */ ccvm_instructions_nop,
  /* 0x69 */ ccvm_instructions_nop,
  /* 0x6a */ ccvm_instructions_nop,
  /* 0x6b */ ccvm_instructions_nop,
  /* 0x6c */ ccvm_instructions_nop,
  /* 0x6d */ ccvm_instructions_nop,
  /* 0x6e */ ccvm_instructions_nop,
  /* 0x6f */ ccvm_instructions_nop,
  /* 0x70 */ ccvm_instructions_math_add_reg_num,
  /* 0x71 */ ccvm_instructions_math_add_stack_num,
  /* 0x72 */ ccvm_instructions_math_sub_reg_num,
  /* 0x73 */ ccvm_instructions_math_sub_stack_num,
  /* 0x74 */ ccvm_instructions_math_mul_reg_num,
  /* 0x75 */ ccvm_instructions_math_mul_stack_num,
  /* 0x76 */ ccvm_instructions_math_div_reg_num,
  /* 0x77 */ ccvm_instructions_math_div_stack_num,
  /* 0x78 */ ccvm_instructions_math_and_reg_num,
  /* 0x79 */ ccvm_instructions_math_and_stack_num,
  /* 0x7a */ ccvm_instructions_math_or_reg_num,
  /* 0x7b */ ccvm_instructions_math_or_stack_num,
  /* 0x7c */ ccvm_instructions_math_xor_reg_num,
  /* 0x7d */ ccvm_instructions_math_xor_stack_num,
  /* 0x7e */ ccvm_instructions_nop,
  /* 0x7f */ ccvm_instructions_nop,
  /* 0x80 */ ccvm_instructions_nop,
  /* 0x81 */ ccvm_instructions_nop,
  /* 0x82 */ ccvm_instructions_nop,
  /* 0x83 */ ccvm_instructions_nop,
  /* 0x84 */ ccvm_instructions_nop,
  /* 0x85 */ ccvm_instructions_nop,
  /* 0x86 */ ccvm_instructions_nop,
  /* 0x87 */ ccvm_instructions_nop,
  /* 0x88 */ ccvm_instructions_nop,
  /* 0x89 */ ccvm_instructions_nop,
  /* 0x8a */ ccvm_instructions_nop,
  /* 0x8b */ ccvm_instructions_nop,
  /* 0x8c */ ccvm_instructions_nop,
  /* 0x8d */ ccvm_instructions_nop,
  /* 0x8e */ ccvm_instructions_nop,
  /* 0x8f */ ccvm_instructions_nop,
  /* 0x90 */ ccvm_instructions_nop,
  /* 0x91 */ ccvm_instructions_nop,
  /* 0x92 */ ccvm_instructions_nop,
  /* 0x93 */ ccvm_instructions_nop,
  /* 0x94 */ ccvm_instructions_nop,
  /* 0x95 */ ccvm_instructions_nop,
  /* 0x96 */ ccvm_instructions_nop,
  /* 0x97 */ ccvm_instructions_nop,
  /* 0x98 */ ccvm_instructions_nop,
  /* 0x99 */ ccvm_instructions_nop,
  /* 0x9a */ ccvm_instructions_nop,
  /* 0x9b */ ccvm_instructions_nop,
  /* 0x9c */ ccvm_instructions_nop,
  /* 0x9d */ ccvm_instructions_nop,
  /* 0x9e */ ccvm_instructions_nop,
  /* 0x9f */ ccvm_instructions_nop,
  /* 0xa0 */ ccvm_instructions_nop,
  /* 0xa1 */ ccvm_instructions_nop,
  /* 0xa2 */ ccvm_instructions_nop,
  /* 0xa3 */ ccvm_instructions_nop,
  /* 0xa4 */ ccvm_instructions_nop,
  /* 0xa5 */ ccvm_instructions_nop,
  /* 0xa6 */ ccvm_instructions_nop,
  /* 0xa7 */ ccvm_instructions_nop,
  /* 0xa8 */ ccvm_instructions_nop,
  /* 0xa9 */ ccvm_instructions_nop,
  /* 0xaa */ ccvm_instructions_nop,
  /* 0xab */ ccvm_instructions_nop,
  /* 0xac */ ccvm_instructions_nop,
  /* 0xad */ ccvm_instructions_nop,
  /* 0xae */ ccvm_instructions_nop,
  /* 0xaf */ ccvm_instructions_nop,
  /* 0xb0 */ ccvm_instructions_nop,
  /* 0xb1 */ ccvm_instructions_nop,
  /* 0xb2 */ ccvm_instructions_nop,
  /* 0xb3 */ ccvm_instructions_nop,
  /* 0xb4 */ ccvm_instructions_nop,
  /* 0xb5 */ ccvm_instructions_nop,
  /* 0xb6 */ ccvm_instructions_nop,
  /* 0xb7 */ ccvm_instructions_nop,
  /* 0xb8 */ ccvm_instructions_nop,
  /* 0xb9 */ ccvm_instructions_nop,
  /* 0xba */ ccvm_instructions_nop,
  /* 0xbb */ ccvm_instructions_nop,
  /* 0xbc */ ccvm_instructions_nop,
  /* 0xbd */ ccvm_instructions_nop,
  /* 0xbe */ ccvm_instructions_nop,
  /* 0xbf */ ccvm_instructions_nop,
  /* 0xc0 */ ccvm_instructions_nop,
  /* 0xc1 */ ccvm_instructions_nop,
  /* 0xc2 */ ccvm_instructions_nop,
  /* 0xc3 */ ccvm_instructions_nop,
  /* 0xc4 */ ccvm_instructions_nop,
  /* 0xc5 */ ccvm_instructions_nop,
  /* 0xc6 */ ccvm_instructions_nop,
  /* 0xc7 */ ccvm_instructions_nop,
  /* 0xc8 */ ccvm_instructions_nop,
  /* 0xc9 */ ccvm_instructions_nop,
  /* 0xca */ ccvm_instructions_nop,
  /* 0xcb */ ccvm_instructions_nop,
  /* 0xcc */ ccvm_instructions_nop,
  /* 0xcd */ ccvm_instructions_nop,
  /* 0xce */ ccvm_instructions_nop,
  /* 0xcf */ ccvm_instructions_nop,
  /* 0xd0 */ ccvm_instructions_nop,
  /* 0xd1 */ ccvm_instructions_nop,
  /* 0xd2 */ ccvm_instructions_nop,
  /* 0xd3 */ ccvm_instructions_nop,
  /* 0xd4 */ ccvm_instructions_nop,
  /* 0xd5 */ ccvm_instructions_nop,
  /* 0xd6 */ ccvm_instructions_nop,
  /* 0xd7 */ ccvm_instructions_nop,
  /* 0xd8 */ ccvm_instructions_nop,
  /* 0xd9 */ ccvm_instructions_nop,
  /* 0xda */ ccvm_instructions_nop,
  /* 0xdb */ ccvm_instructions_nop,
  /* 0xdc */ ccvm_instructions_nop,
  /* 0xdd */ ccvm_instructions_nop,
  /* 0xde */ ccvm_instructions_nop,
  /* 0xdf */ ccvm_instructions_nop,
  /* 0xe0 */ ccvm_instructions_nop,
  /* 0xe1 */ ccvm_instructions_nop,
  /* 0xe2 */ ccvm_instructions_nop,
  /* 0xe3 */ ccvm_instructions_nop,
  /* 0xe4 */ ccvm_instructions_nop,
  /* 0xe5 */ ccvm_instructions_nop,
  /* 0xe6 */ ccvm_instructions_nop,
  /* 0xe7 */ ccvm_instructions_nop,
  /* 0xe8 */ ccvm_instructions_nop,
  /* 0xe9 */ ccvm_instructions_nop,
  /* 0xea */ ccvm_instructions_nop,
  /* 0xeb */ ccvm_instructions_nop,
  /* 0xec */ ccvm_instructions_nop,
  /* 0xed */ ccvm_instructions_nop,
  /* 0xee */ ccvm_instructions_nop,
  /* 0xef */ ccvm_instructions_nop,
  /* 0xf0 */ ccvm_instructions_nop,
  /* 0xf1 */ ccvm_instructions_nop,
  /* 0xf2 */ ccvm_instructions_nop,
  /* 0xf3 */ ccvm_instructions_nop,
  /* 0xf4 */ ccvm_instructions_nop,
  /* 0xf5 */ ccvm_instructions_nop,
  /* 0xf6 */ ccvm_instructions_nop,
  /* 0xf7 */ ccvm_instructions_nop,
  /* 0xf8 */ ccvm_instructions_nop,
  /* 0xf9 */ ccvm_instructions_nop,
  /* 0xfa */ ccvm_instructions_nop,
  /* 0xfb */ ccvm_instructions_nop,
  /* 0xfc */ ccvm_instructions_nop,
  /* 0xfd */ ccvm_instructions_nop,
  /* 0xfe */ ccvm_instructions_nop,
  /* 0xff */ ccvm_instructions_syscall
};

CCVM ccvm_create_ccvm() {
    CCVM ret = {0};
    return ret;
}

void ccvm_program_load(CCVM* vm, char *filename) {
    // open file
    FILE *fp = fopen(filename, "rb");

    // error detection
    if (fp == NULL) {
        printf("[ERROR] could not open file: %s", filename);
        exit(1);
    }

    // get buffer size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // buffer allocation
    unsigned char *buffer = (unsigned char *) malloc(size);

    if(fread(buffer, sizeof *buffer, size, fp) != size) {
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
    uint8_t instruction = vm->bytecode[vm->pc + vm->headerSize];
    // printf("[DEBUG] doing instruction 0x%.2x\n", instruction);
    ccvm_instructionset[instruction](vm);
}

void ccvm_parse_header(CCVM* vm) {
    // Initialises headerSize to minimal header size, since all headers must end in 1d1d1d1d
    vm->headerSize = 4;

    // Loop through the bytecode and write it to the VM ram unless an ending header has been reached
    uint32_t i = 0;
    while(!(vm->bytecode[i] == 0x1d && vm->bytecode[i + 1] == 0x1d && vm->bytecode[i + 2] == 0x1d && vm->bytecode[i + 3] == 0x1d)) {
        ccvm_ram_write(vm->ram, i, vm->bytecode[i]);
        i++;
        vm->headerSize++;
    }
}

void ccvm_program_run(CCVM* vm) {
    
    // Initialises the VM Stack and RAM
    vm->stack = ccvm_stack_init();
    vm->ram = ccvm_ram_init();

    // Parses headers and loads them into the RAM
    ccvm_parse_header(vm);

    // While a flag to stop wasn't reached, execute the current step and move onto the next step
    while (!ccvm_flags_get(&vm->flags, ccvm_flag_stop)) {
        ccvm_program_step(vm);    
        vm->pc++;
    }
}

void ccvm_registers_debug(CCVM* vm) {
    printf("registers:\n\ta = %u\n\tb = %u\n\tc = %u\n\tc = %u\n", vm->registers[0], vm->registers[1], vm->registers[2], vm->registers[3]);
}
