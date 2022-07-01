#include "ft_printf.h"

int print_char(int c)
{
  return (write(1, &c, 1));
}

int print_percent()
{
  return (print_char('%'));
}
