#include "ft_printf.h"

int print_upper_hex(unsigned int num)
{
  int res;

  if (num == 0)
    return (print_char('0'));
  res = write_upper_hex(num);
  if (res != get_hex_size(num))
    return (-1);
  return (res);
}

int print_lower_hex(unsigned int num)
{
  int res;

  if (num == 0) return (print_char('0'));
  res = write_lower_hex(num);
  if (res != get_hex_size(num))
    return (-1);
  return (res);
}

int write_lower_hex(unsigned long long num)
{
  if (num == 0)
    return (0);
  if (num % 16 <= 9)
    return (write_lower_hex(num / 16) + print_char(num % 16 + '0'));
  else
    return (write_lower_hex(num / 16) + print_char(num % 16 - 10 + 'a'));
}

int write_upper_hex(unsigned long long num)
{
  if (num == 0)
    return (0);
  if (num % 16 <= 9)
    return (write_upper_hex(num / 16) + print_char(num % 16 + '0'));
  else
    return (write_upper_hex(num / 16) + print_char(num % 16 - 10 + 'A'));
}

int get_hex_size(unsigned long long num)
{
  int res;

  res = 0;
  while (num / 16 != 0)
  {
    num /= 16;
    res++;
  }
  return (res + 1);
}