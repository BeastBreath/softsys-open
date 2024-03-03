#include "array_sort.h"

void swap(int* left_ptr, int* right_ptr) {
  int left_int = *left_ptr;
  *left_ptr = *right_ptr;
  *right_ptr = left_int;
}

void sort_inplace(int numbers[], size_t array_size) {
  for (size_t j = 0; j < array_size; j++) {
    for (size_t k = j + 1; k < array_size; k++) {
      if (numbers[j] > numbers[k]) {
        swap(&numbers[j], &numbers[k]);
      }
    }
  }
}

void sort_copy(const int numbers[], int sorted[], size_t array_size) {
  for(size_t i = 0; i < array_size; i++) {
    int current_value = numbers[i];
    sorted[i] = current_value;
    size_t j = i;
    while (j > 0 && sorted[j] < sorted[j - 1]) {
      swap(&sorted[j], &sorted[j - 1]);
      j--;
    }
  }
}
