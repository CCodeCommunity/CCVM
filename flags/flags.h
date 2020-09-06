#pragma once

// the names of all the flags
// in the CCVM
typedef enum ccvm_flagset_flags {
	ccvm_flag_equal,
	ccvm_flag_not_equal,
	ccmv_flag_greater,
	ccmv_flag_smaller,
	ccmv_flag_overflow,
	ccmv_flag_stop
} ccvm_flagset_flags;

// the struct to store the states
// of the flags compacted in a single char
typedef struct ccvm_flagset {
	char values;
} ccvm_flagset;

// ccvm_flags_set takes a flagset, a index from the ccvm_flagset_flags
// enum and a boolean value, it will then assign the value to the flag
void ccvm_flags_set(ccvm_flagset*, ccvm_flagset_flags, char);

// ccvm_flags_get takes the index of a flag from ccvm_flagset_flags
// and returns the current value of that flag
char ccvm_flags_get(ccvm_flagset*, ccvm_flagset_flags);