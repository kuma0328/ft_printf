#include "ft_printf.h"

int write_lower_hex(unsigned long long num)
{
  if (num == 0) return (0);
  if (num % 16 <= 9) return write_lower_hex(num / 16) + print_char(num % 16 + '0');
  else return write_lower_hex(num / 16) + print_char(num % 16 - 10 + 'a');
}

int write_upper_hex(unsigned long long num)
{
  if (num == 0) return (0);
  if (num % 16 <= 9) return write_upper_hex(num / 16) + print_char(num % 16 + '0');
  else return write_upper_hex(num / 16) + print_char(num % 16 - 10 + 'A');
}

int print_lower_hex(unsigned int num)
{
  if (num == 0) return (print_char('0'));
  return (write_lower_hex(num));
}

int print_upper_hex(unsigned int num)
{
  if (num == 0) return (print_char('0'));
  return (write_upper_hex(num));
}

int write_int(long long num)
{
  if (num == 0) return (0);
  return write_int(num / 10) + print_char(num % 10 + '0');
}