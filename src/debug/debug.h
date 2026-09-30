#include "types.h"
#define IS_DEBUGGING_NS 1 //New symbols
#define IS_DEBUGGING_PARSED_S 0 //Parsed Symbols
#define IS_DEBUGGING_PARSED_P 0 //Parsed Probabilities
#define IS_DEBUGGING_PARSED_FREQ 0 //Parsed Frequencies
#define IS_DEBUGGING_WRITEOUT 1 //Write out symbols




void debug_NS_value(CompressInfo* file_info);
void debug_parsed_symbols(CompressInfo* file_info);
void debug_parsed_probabilities(CompressInfo* file_info);