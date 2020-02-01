#include "morse_alphabet.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>


char get_morse_symbol(const char* morse_letter, const unsigned int index) {
  const size_t max_size = strlen(morse_letter);
  if (index >= max_size) {
    printf("Index error (%d >= %d)\n", index, (unsigned int)max_size);
    return '&';
  }
  char res = *(morse_letter + index);
  return res;
}


const char* get_morse_letter(const ALPHABET alpha, char letter){
  if (isupper(letter)) {
    const int ascii_code_A = 65;
    return alpha.alpha_table[letter - ascii_code_A];
  } else if (isdigit(letter)) {
    const int ascii_code_0 = 48;
    return alpha.digit_table[letter - ascii_code_0];
  } else {
    return NULL;
  }
}


void print_alphabet(const ALPHABET alpha) {
  printf("---- LETTERS ----\n");
  for (unsigned int i = 0; i < alpha.alpha_size; ++i) {
    printf("%d : %s\n", i, alpha.alpha_table[i]);
  }
  printf("---- DIGITS ----\n");
  for (unsigned int i = 0; i < alpha.digit_size; ++i) {
    printf("%d : %s\n", i, alpha.digit_table[i]);
  }
}