#include <pthread.h>
#include <semaphore.h>

#include "weave.h"

int main(void) {
  start_threads(3);
  return 0;
}
