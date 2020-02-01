#include <stdio.h>
#include "morse_alphabet/morse_alphabet.h"


int main() {
  printf("This is cpimorse!\n");
  printf("Morse alphabet\n");
  print_alphabet(MorseAlphabet);
  printf("Morse code for A is : %s\n", get_morse_letter(MorseAlphabet, 'A'));
  const char* toto = get_morse_letter(MorseAlphabet, 'B');
  printf("Morse code for B is : %s\n", toto);
  printf("Morse symbol for B[%d] is %c\n", 3, get_morse_symbol(toto, 3));
  printf("Morse code for 8 is : %s\n", get_morse_letter(MorseAlphabet, '8'));
}
