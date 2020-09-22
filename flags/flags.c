#include "flags.h"
#include <stdio.h>
#include <stdlib.h>

#include "../CCVM.h"

/*
	we must get the index'th bit of the values of fs
	to do that, we first bitshift left by index-1 so that
	the bit we are interested in gets positioned as the last bit

	example:
	index = 3 (decimal)
	values = 10111010 (binary)

	before the bitshift:
	10111010
	   ^

	after the bitshift:
	00001011
	       ^

	now to get the left bit and ditch the rest, we bitwise and it
	with 0x01, 0x01 in binary is 00000001 and this will act as a "mask"

	11010000 && 10000000 = 00000001 = 1

	so then we will end up with 1
*/
char ccvm_flags_get(ccvm_flagset* fs, ccvm_flagset_flags index) {
	return (fs->values >> (7- index)) & 1U;
}

/*
	to get the new values of the flags, we must take the value we want to
	insert at some index, and bitshift it to the left by 7-index bits

	this makes sure that the bit we gave in as the value is in the right position
	to be bitwise xor'ed

	the xor operation will toggle the at the index we want to set to 0 or 1 depending
	on the value operation
*/
void ccvm_flags_set(ccvm_flagset* fs, ccvm_flagset_flags index, char value) {
	fs->values ^= (-value ^ fs->values) & (1UL << (7 - index));
}

void ccvm_flags_debug(CCVM* vm) {
	printf("flags:\n\tequal: %d\n\tnot equal: %d\n\tgreater: %d\n\tsmaller: %d\n\toverflow: %d\n\tstop: %d\n\t", ccvm_flags_get(&vm->flags, ccvm_flag_equal), ccvm_flags_get(&vm->flags, ccvm_flag_not_equal), ccvm_flags_get(&vm->flags, ccvm_flag_greater), ccvm_flags_get(&vm->flags, ccvm_flag_smaller), ccvm_flags_get(&vm->flags, ccvm_flag_overflow), ccvm_flags_get(&vm->flags, ccvm_flag_stop));
}
