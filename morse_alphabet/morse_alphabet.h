#include <stdlib.h>

struct ALPHABET_T {
    const size_t alpha_size;
    const char** alpha_table;
    const size_t digit_size;
    const char** digit_table;
};
typedef struct ALPHABET_T ALPHABET;

#define MORSE_ALPHA_SIZE 26
const char* MorseAlphaTable[MORSE_ALPHA_SIZE] = {
// A       B      C       D     E     F       G      H       I
  "SL", "LSSS", "LSLS", "LSS", "S", "SSLS", "LLS", "SSSS", "SS",
// J       K      L       M     N      O      P       Q       R
  "SLLL", "LSL", "SLSS", "LL", "LS", "LLL", "SLLS", "LLSL", "SLS",
// S      T     U       V      W      X       Y       Z
  "SSS", "L", "SSL", "SSSL", "SLL", "LSSL", "LSLL", "LLSS"};
#define MORSE_DIGIT_SIZE 10
const char* MorseDigitTable[MORSE_DIGIT_SIZE] = {
// 0          1         2        3        4       5         6
  "LLLLL", "SLLLL", "SSLLL", "SSSLL", "SSSSL", "SSSSS", "LSSSS",
// 7         8        9
  "LLSSS", "LLLSS", "LLLLS"};

const ALPHABET MorseAlphabet = {MORSE_ALPHA_SIZE, MorseAlphaTable,
                                MORSE_DIGIT_SIZE, MorseDigitTable};

char get_letter_from_string(const char* string, const unsigned int index);

const char* get_letter_from_alphabet(const ALPHABET alpha, const char letter);

void print_alphabet(const ALPHABET alpha);

const char* get_letter_from_morse_alphabet(char letter);
