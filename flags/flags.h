#ifndef ccvm_flags_guard
#define ccvm_flags_guard

typedef struct CCVM CCVM;

// the names of all the flags
// in the CCVM
typedef enum ccvm_flagset_flags {
	ccvm_flag_equal,
	ccvm_flag_not_equal,
	ccvm_flag_greater,
	ccvm_flag_smaller,
	ccvm_flag_overflow,
	ccvm_flag_stop
} ccvm_flagset_flags;

// the struct to store the states
// of the flags compacted in a single char
typedef struct ccvm_flagset {
	char values;
} ccvm_flagset;

// ccvm_flags_set takes a flagset, a index from the ccvm_flagset_flags
// enum and a boolean value, it will then assign the value to the flag
void ccvm_flags_set(ccvm_flagset* fs, ccvm_flagset_flags index, char value);

// ccvm_flags_get takes the index of a flag from ccvm_flagset_flags
// and returns the current value of that flag
char ccvm_flags_get(ccvm_flagset* fs, ccvm_flagset_flags index);
#endif