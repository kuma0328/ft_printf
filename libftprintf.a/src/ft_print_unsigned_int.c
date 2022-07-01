#include "ft_printf.h"

int print_unsigned_int(unsigned int num)
{
  int res;

  if (num == 0)
    return print_char('0');
  res = write_unsigned_int(num);
  if (res != get_unsigned_int_size(num))
    return (-1);
  return (res);
}

int write_unsigned_int(unsigned long long num)
{
  if (num == 0)
    return (0);
  return (write_unsigned_int(num / 10) + print_char(num % 10 + '0'));
}

int get_unsigned_int_size(unsigned int  num)
{
  int res;

	res = 0;
	while (num / 10 != 0)
	{
		res ++;
		num /= 10;
	}
	return (res + 1);
}