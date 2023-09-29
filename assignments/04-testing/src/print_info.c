/**
 * Print type size and max value for numeric types on this system.
 */
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Maximum int: %d\n", INT_MAX);
  printf("Size of float: %zu bytes\n", sizeof(float));
  printf("Maximum float: %f\n", FLT_MAX);
  printf("Size of double: %zu bytes\n", sizeof(double));
  printf("Maximum double: %lf\n", DBL_MAX);
  return 0;
}
