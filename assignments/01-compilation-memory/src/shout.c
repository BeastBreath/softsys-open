
#include "shout.h"

#include <ctype.h>
#include <stdio.h>

void shout(void) {
  char inputString[BUFFER_SIZE + 1];
  (void)fgets(inputString, BUFFER_SIZE + 1, stdin);
  for (int i = 0; i < BUFFER_SIZE + 1; i++) {
    inputString[i] = toupper(inputString[i]);
    if (inputString[i] == '\n') {
      inputString[i] = '\0';
    }
  }
  printf("%s\n", inputString);
}
