#include <unistd.h>
#include <stdarg.h>

int poww(int n, int k)
{
  if(k == 0) return 1;
  return n * poww(n, k-1);
}

int my_length(const char* s)
{
  int i = 0;
  while(s[i] != '\0')
    i++;
  return i;
}

int my_length1(const int num)
{
  int temp = num;
  int i = 0;
  while(temp != 0)
  {
    i++;
    temp = temp / 10;
  }
  return i;
}

void print_int(int num, int padding, char ch)
{
  int len = my_length1(num);
  for(int i = 0; i < padding - len; i++)
  {
    write(1, &ch, 1);
  }
  char ch1;
  for (int i = len; i > 0 ; i--)
  {
    ch1 = num / poww(10, i-1) + 48;
    write(1, &ch1, 1);
    num = num % poww(10, i-1);
  }
}

void print_string(char* s, int padding, char ch)
{
  int j = 0;
  int len = my_length(s);
  for(int i = 0; i < (padding - len); i++)
     write(1, &ch, 1);
  while(s[j] != '\0')
  {
    write(1, &s[j], 1);
    j++;
  }
}

int find_padding(const char* format, int* pos)
{
  int pad = 0;
  while(format[*pos]>='0' && format[*pos]<='9')
  {
    pad = pad * 10 + (format[*pos]-48);
    ( *pos)++;
  }
  return pad;
}

int my_printf(const char *format, ...)
{
  int i = 0;
  va_list valist;
  va_start(valist, format);
  while(format[i] != '\0')
  {
    if(format[i] == '%')
    {
      switch (format[i+1])
      {
        case 'd':
          {
            print_int(va_arg(valist, int), 0, ' ');
            i= i + 2;
            break;
          }
        case 's':
          {
            print_string(va_arg(valist, char*), 0, ' ');
            i= i + 2;
            break;
          }
        case '%':
          {
            write(1, "%", 1);
            i = i + 2;
            break;
          }
        case '0':
          {
            i++;
            int pad = find_padding(format, &i);
            if(format[i] == 's')
               print_string(va_arg(valist, char*), pad, '0');
            else
               print_int(va_arg(valist, int), pad, '0');

            i++;
            break;
         }
        default:
          {
            i++;
            int pad = find_padding(format, &i);
            if(format[i] == 's')
              print_string(va_arg(valist, char*), pad, ' ');
            else
              print_int(va_arg(valist, int), pad, ' ');

            i++;
          }
      }
    } else
    {
      write(1, &format[i], 1);
      i++;
    }
  }
  va_end(valist);
  return 0;
}
