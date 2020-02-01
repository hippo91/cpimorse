#include <stdlib.h>

struct ALPHABET_T {
    const size_t alpha_size;
    const char** alpha_table;
    const size_t digit_size;
    const char** digit_table;
};
typedef struct ALPHABET_T ALPHABET;

struct DURATION_T {
  const unsigned int dot;
  const unsigned int dash;
  const unsigned int space;
  const unsigned int inter_letter;
  const unsigned int inter_word;
};
typedef struct DURATION_T DURATION;


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

#define DOT_DURATION 1
#define DASH_DURATION DOT_DURATION * 2
#define SPACE_DURATION DOT_DURATION
#define INTER_LETTER_DURATION DOT_DURATION * 3
#define INTER_WORD_DURATION DOT_DURATION * 7
const DURATION MorseDuration = {DOT_DURATION, DASH_DURATION,
                                SPACE_DURATION, INTER_LETTER_DURATION,
                                INTER_WORD_DURATION};