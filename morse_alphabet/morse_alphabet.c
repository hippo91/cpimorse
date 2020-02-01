#include "morse_alphabet.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------*/
/**
 * \brief Get the letter at specific index in the string
 * 
 * @param string : string from which the letter should be extracted
 * @param index : index at twhich the letter is looked for 
 * @return char : the letter or '&' if the index is outside string limits
 */
/*------------------------------------------------------------------*/
char get_letter_from_string(const char* string, const unsigned int index) {
  const size_t max_size = strlen(string);
  if (index >= max_size) {
    fprintf(stderr, "Index error (%d >= %d)\n", index, (unsigned int)max_size);
    return '&';
  }
  char res = *(string + index);
  return res;
}


/*------------------------------------------------------------------*/
/**
 * @brief Get the correspondance of letter in the alphabet
 * 
 * @param alpha : alphabet
 * @param letter : letter to get the correspondance from
 * @return const char* : a string representing the letter in the alphabet
 *                       or null if none string is found
 */
/*------------------------------------------------------------------*/
const char* get_letter_from_alphabet(const ALPHABET alpha, const char letter){
  int index = 0;
  if (isupper(letter)) {
    const int ascii_code_A = 65;
    index = letter - ascii_code_A;
    if(index<0 || index>= (int)alpha.alpha_size) {
      fprintf(stderr, "Index error (%d > %d)\n", index, (int)alpha.alpha_size);
      return NULL;
    }
    return alpha.alpha_table[letter - ascii_code_A];
  } else if (isdigit(letter)) {
    const int ascii_code_0 = 48;
    index = letter - ascii_code_0;
    if (index<0 || index>= (int)alpha.digit_size) {
      fprintf(stderr, "Index error (%d > %d)\n", index, (int)alpha.digit_size);
      return NULL;
    }
    return alpha.digit_table[letter - ascii_code_0];
  } else {
    return NULL;
  }
}


/*------------------------------------------------------------------*/
/**
 * @brief Print the alphabet in argument
 * 
 * @param alpha : alphabet
 */
/*------------------------------------------------------------------*/
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

/*------------------------------------------------------------------*/
/**
 * @brief Get the letter from morse alphabet
 * 
 * @param letter : letter from which the morse translation is looked for
 * @return const char* : morse translation of the letter
 */
/*------------------------------------------------------------------*/
const char* get_letter_from_morse_alphabet(const char letter)
{
  return get_letter_from_alphabet(MorseAlphabet, letter);
}