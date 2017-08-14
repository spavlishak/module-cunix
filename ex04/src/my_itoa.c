#include <stdio.h>
#include <stdlib.h>

int length(int sign, int nmb) {
  int len = 0;
	while (nmb /= 10)
		len++;
	len += sign;
	return len;
}

char *my_itoa(int nmb) {
  int len;
  int sign = 0;
  char *str;

  if (nmb < 0) {
    sign = 1;
    nmb = -nmb;
  }
  
  len = length(sign, nmb) + 2;
	if ((str = (char*)malloc(sizeof(char) * (len))) == NULL)
		return 0;
	str[--len] = '\0';
	while (len--)
	{
		str[len] = nmb % 10 + '0';
		nmb /= 10;
	}
	if (sign)
		str[0] = '-';
	return str;
}
