#include "ft_printf.h"

int print_pointer(uintptr_t num)
{
  int res;

  res = print_string("0x");
  if (res == -1)
    return (-1);
  if (num == 0)
    res += print_char('0');
  else
    res += write_pointer(num);
  if (res != get_pointer_size(num) + 2)
    return (-1);
  return (res);
}

int write_pointer(uintptr_t num)
{
  if (num == 0)
    return (0);
  if (num % 16 <= 9)
    return (write_pointer(num / 16) + print_char(num % 16 + '0'));
  else
    return (write_pointer(num / 16) + print_char(num % 16 - 10 + 'a'));
}

int get_pointer_size(uintptr_t num)
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