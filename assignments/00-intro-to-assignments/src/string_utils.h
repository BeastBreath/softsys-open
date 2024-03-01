#pragma once

#include <stddef.h>

/**
 * Find string length
 * 
 * @param str The string to find the length of
 * @returns The length of the string 
 */
size_t string_length(const char* str);

/**
 * Count number of vowels in text
 * 
 * @param text The text to count vowels in
 * @return The number of vowels in text
 */
size_t count_vowels(const char* text);

/**
 * Count number of digits in text
 * 
 * @param text The text to count digits in
 * @return The number of digits in text
 */
size_t count_digits(const char* text);

