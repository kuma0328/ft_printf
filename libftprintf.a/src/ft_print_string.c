#include "ft_printf.h"

int print_string(char *s)
{
  int res;
  int print_size;
  size_t  i;

  res = 0;
  i = 0;
  if (s == NULL)
    return (write(1, "(null)", 6));
  while (s[i] != '\0')
  {
    print_size = print_char(s[i]);
    if (print_size == -1) return (-1);
    res += print_size;
    i++;
  }
  return (res);
}