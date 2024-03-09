#include "string_utils.h"

#include <string.h>

int startswith(const char* str, const char* substr) {
  if (strlen(str) < strlen(substr)) {
    return 0;
  }
  for (int i = 0; i < strlen(str) && i < strlen(substr); i++) {
    if (str[i] != substr[i]) {
      return 0;
    }
  }
  return 1;
}

int endswith(const char* str, const char* substr) {
  int strLen = strlen(str);
  int substrLen = strlen(substr);
  if (strLen < substrLen) {
    return 0;
  }
  for (int i = 0; i < substrLen; i++) {
    if (str[i + (strLen - substrLen)] != substr[i]) {
      return 0;
    }
  }
  return 1;
}

size_t count(const char* str, const char* substr) {
  size_t strLen = strlen(str);
  size_t substrLen = strlen(substr);
  if (substrLen == 0) {
    return strLen + 1;
  }
  size_t instances = 0;
  size_t index = 0;
  while (index < strLen) {
    if (startswith(str + index, substr) == 1) {
      instances++;
      index += substrLen;
    }
    else {
      index++;
    }
  }

  return instances;  // Replace this line with your implementation.
}

void strip(const char* src, char* dst, const char* chars) {
  if (chars == NULL) {
    chars = WHITESPACE;
  }
  int start_index;
  int end_index = strlen(src) - 1;
  for(start_index = 0; start_index < end_index; start_index++) {
    char current_char[2];
    current_char[1] = '\0';
    current_char[0] = src[start_index];
    if (count(chars, current_char) == 0) {
      break;
    }
  }
  for(;end_index > 0; end_index--) {
    char current_char[2];
    current_char[1] = '\0';
    current_char[0] = src[end_index];
    if (count(chars, current_char) == 0) {
      break;
    }
  }
  if (start_index > end_index) {
    strncpy(dst, src, 0);
  }
  strncpy(dst, src + start_index, end_index - start_index + 1);
  dst[end_index - start_index + 1] = '\0';
}

void split(const char* src, char* dst[], const char* sep) {
  // Replace this line with your implementation.
}
