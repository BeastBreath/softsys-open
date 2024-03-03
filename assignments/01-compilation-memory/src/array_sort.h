#pragma once

#include <stddef.h>
#include <stdio.h>

/**
 * Swap two integers
 * 
 * @param left_ptr Pointer to the first integer
 * @param right_ptr Pointer to the right integer
 */
void swap(int* left_ptr, int* right_ptr);

/**
 * Sort an array
 * 
 * @param numbers Array of integers to be sorted
 * @param array_size An integer for how long the array is
 */
void sort_inplace(int numbers[], size_t array_size);

/**
 * Create a sorted copy of an array
 * 
 * @param numbers Array of integers before being sorted
 * @param sorted An array to store the sorted integers
 * @param array_size An integer for how long the array is
 */
void sort_copy(const int numbers[], int sorted[], size_t array_size);
