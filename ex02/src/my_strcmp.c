#include <stdio.h>

int my_strcmp(char *str1, char *str2) {
  while ((*str1 == *str2) && (*str1 != '\0')) {
    str1++;
    str2++;
  }

  if (*str1 > *str2)
    return 1;
  if (*str1 < *str2)
    return -1;
  return 0;
}

