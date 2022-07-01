#include "ft_printf.h"

int print_int(int num)
{
  int res;

  if (num == 0)
    return (print_char('0'));
  if (num < 0) {
    res = print_char('-');
    res += write_int((long long)num * -1);
  } else
    res = write_int(num);
  if (res != get_int_size(num))
    return (-1);
  return (res);
}

int write_int(long long num)
{
  if (num == 0) return (0);
  return (write_int(num / 10) + print_char(num % 10 + '0'));
}

int get_int_size(int  num)
{
  int res;

	res = 0;
	if (num < 0)
		res++;
	while (num / 10 != 0)
	{
		res ++;
		num /= 10;
	}
	return (res + 1);
}