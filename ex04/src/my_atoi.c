#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *nptr) {
  int num = 0;
  int i = 0;
  int neg = 1;

  if (*nptr == '\0')
  return 0;

  if (nptr[i] == '-')
  {
    neg = -1;
    i++;
  }
  while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return num * neg;
}
