#include <stdio.h>
#include "morse_alphabet/morse_alphabet.h"


int main(int nb_args, char* argv[]) {
  if (nb_args != 2) {
    fprintf(stderr, "This program waits a string as argument!\n");
    return 1;
  } else {
    printf("Argument is %s\n", argv[1]);
  }
  printf("This is cpimorse!\n");
  printf("Morse alphabet\n");
  print_alphabet(MorseAlphabet);
  printf("Morse code for A is : %s\n", get_letter_from_morse_alphabet('A'));
  const char* toto = get_letter_from_morse_alphabet('B');
  printf("Morse code for B is : %s\n", toto);
  printf("Morse symbol for B[%d] is %c\n", 3, get_letter_from_string(toto, 3));
  printf("Morse code for 3 is : %s\n", get_letter_from_morse_alphabet('3'));
  printf("Morse code for ! is : %s\n", get_letter_from_morse_alphabet('!'));
}
