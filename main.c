#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "morse_alphabet/morse_alphabet.h"

/*------------------------------------------------------------------*/
/**
 * @brief Emit the morse letter in argument
 * 
 * @param morse_letter : morse letter to be emitted
 * @return size_t : number of symbols really emitted
 */
/*------------------------------------------------------------------*/
size_t emit_morse_letter(const char* morse_letter) {
  const size_t length = strlen(morse_letter);
  size_t emitted = 0;
  for (size_t j=0; j < length; ++j) {
    char current_symbol = morse_letter[j];
    if (current_symbol == 'S') {
      printf(" Emitting .");
    }
    else if (current_symbol == 'L') {
      printf(" Emitting -");
    } else {
      fprintf(stderr, "Unknown morse symbol %c\n", current_symbol);
      return emitted;
    }
    ++emitted;
    if (j != length - 1)
      sleep(MorseDuration.space);
    if (j == length - 1) printf("\n");
  }
  return emitted;
}

int main(int nb_args, char* argv[]) {
  if (nb_args != 2) {
    fprintf(stderr, "This program waits a string as argument!\n");
    return 1;
  }
  setbuf(stdout, NULL);
  printf("Argument is %s\n", argv[1]);
  char* message = argv[1];
  for (size_t i=0; i< strlen(message); ++i) {
    char current = message[i];
    char next = '\n';
    if (i < strlen(message) - 1)
      next = message[i+1];
    printf("Emitting : %c (next is %c)\n", current, next);
    const char* morse_letter = get_letter_from_morse_alphabet(current);
    if (!morse_letter) {
      fprintf(stderr, "Unable to code morse for letter %c\n", current);
      return 2;
    }
    size_t done = emit_morse_letter(morse_letter);
    if (done != strlen(morse_letter)) {
      fprintf(stderr, "Only %i/%i symbol emitted!\n", (int)done, (int)strlen(morse_letter));
      return 3;
    }
    if (next != '\n') {
      if (isalnum(next))
        sleep(MorseDuration.inter_letter);
      else
        sleep(MorseDuration.inter_word);
        while (next != '\n' && !isalnum(next)) {
          ++i;
          current = message[i];
          next = '\n';
          if (i < strlen(message) - 1)
            next = message[i+1];
        }
    }
  }
}
