#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <gpiod.h>
#include "morse_alphabet/morse_alphabet.h"

#define IN  0
#define OUT 1

#define LOW  0
#define HIGH 1

#define POUT 21 /* P1-40 */
#define GPIOCHIP0 "/dev/gpiochip0"
#define EMITTER "CPiMorse"
#define ACTIVITY 0

/*------------------------------------------------------------------*/
/**
 * @brief Sleep during duration specified
 * 
 * @param duration : duration
 */
/*------------------------------------------------------------------*/
void wait(void* duration)
{
  unsigned int * delay_p = (unsigned int *) duration;
  sleep(*delay_p);
}

/*------------------------------------------------------------------*/
/**
 * @brief Get the pin status
 * 
 * @return int : 0 or 1 in case of success. -1 otherwise.
 */
/*------------------------------------------------------------------*/
int get_pin_status()
{
  return gpiod_ctxless_get_value(GPIOCHIP0, POUT, ACTIVITY, EMITTER);
}

/*------------------------------------------------------------------*/
/**
 * @brief Emit dash
 * 
 * @return int : 0 or 1 in case of success. -1 otherwise.
 */
/*------------------------------------------------------------------*/
int emit_dash()
{
  int res = gpiod_ctxless_set_value(GPIOCHIP0, POUT, HIGH, ACTIVITY, EMITTER,
                                    wait, (void*) &MorseDuration.dash);
  return res;
}

/*------------------------------------------------------------------*/
/**
 * @brief Emit dot
 * 
 * @return int : 0 or 1 in case of success. -1 otherwise.
 */
/*------------------------------------------------------------------*/
int emit_dot()
{
  int res = gpiod_ctxless_set_value(GPIOCHIP0, POUT, HIGH, ACTIVITY, EMITTER,
                                    wait, (void *) &MorseDuration.dot);
  return res;
}


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
  for (; emitted < length; ++emitted) {
    char current_symbol = morse_letter[emitted];
    if (current_symbol == 'S') {
      if (emit_dot() == -1) {
        fprintf(stderr, "Unable to emit dot for index %i of %s\n", (int)emitted, morse_letter);
        break;
      };
    } else if (current_symbol == 'L') {
      if (emit_dash() == -1) {
        fprintf(stderr, "Unable to emit dash for index %i of %s\n", (int)emitted, morse_letter);
        break;
      };
    } else {
      fprintf(stderr, "Unknown morse symbol %c\n", current_symbol);
      break;
    }
    if (emitted != length - 1)
      sleep(MorseDuration.space);
    if (emitted == length - 1) printf("\n");
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
        // Move forward till the next word
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
