#include "absolute.h"

int absolute_value(int n) {
  if (n < 0) {
    return -1 * n;
  }
  return n;
}
