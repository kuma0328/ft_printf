#include "ft_printf.h"

int print_char(int c)
{
  int print_size;

  print_size = write(1, &c, 1);
  if (print_size == -1) return (0);
  return (print_size);
}

int print_string(char *s)
{
  int print_size;
  size_t  i;

  print_size = 0;
  i = 0;
  if (s == NULL)
    return print_string("(null)");
  while (s[i] != '\0')
  {
    print_size += print_char(s[i]);
    i++;
  }
  return (print_size);
}

int print_int(int num)
{
  long long n = num;
  int print_size;

  if (n == 0) return (print_char('0'));
  print_size = 0;
  if (n < 0)
  {
    n *= -1;
    print_size += print_char('-');
  }
  print_size += write_int(n);
  return (print_size);
}

int print_pointer(uintptr_t num)
{
  int print_size;
  char  *hex_num;

  print_size = print_string("0x");
  if (num == 0) print_size += print_char('0');
  else print_size += write_lower_hex(num);
  return (print_size);
}

int print_percent()
{
  return (print_char('%'));
}
