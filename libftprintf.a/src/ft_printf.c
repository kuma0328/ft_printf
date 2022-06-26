#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>

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
    print_string("(null)");
  while (s[i] != '\0')
  {
    print_size += print_char(s[i]);
    i++;
  }
  return (print_size);
}

size_t get_hex_size(unsigned long long num)
{
  int res;

  res = 0;
  while (num)
  {
    num /= 16;
    res++;
  }
  return (res);
}

// void write_pointer(unsigned long long num)
// {
//   if (num >= 16)
//     write_pointer(num / 16);
//   if (num % 16 <= 9)
//     print_char(num % 16 + '0');
//   else 
//     print_char(num % 16 - 10 + 'a');
// }

char  *to_num_hex_string(unsigned long long num)
{
  char  *res;
  size_t  i;

  i = get_hex_size(num);
  res = (char *)malloc((i + 1) * sizeof(char));
  if (res == NULL)
    return (NULL);
  res[i] = '\0';
  while (i > 0)
  {
    int n = num % 16;
    if (n >= 10) res[i - 1] = n - 10 + 'a';
    else res[i - 1] = n + '0';;  
    num /= 16;
    i--; 
  }
  return (res);
}

int print_pointer(unsigned long long num)
{
  int print_size;
  char  *hex_num;

  print_size = print_string("0x");
  hex_num = to_num_hex_string(num);
  print_size += print_string(hex_num);
  free(hex_num);
  return (print_size);
}

// libft------------------------------------- 
static	size_t	ft_get_digit(int n)
{
	size_t	res;

	res = 0;
	if (n < 0)
		res ++;
	while (n / 10 != 0)
	{
		res ++;
		n /= 10;
	}
	return (res + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	digit;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	digit = ft_get_digit(n);
	res = (char *)malloc((digit + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[digit] = '\0';
	while (digit > 0)
	{
		res[digit - 1] = n % 10 * sign + '0';
		n /= 10;
		digit --;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
// libft ----------------------------------------------

int print_int(int num)
{
  return (print_string(ft_itoa(num)));
}

int print_unsigned_int(unsigned int num)
{
  return (print_string(ft_itoa(num)));
}

int print_hex(unsigned int num)
{
  char  *hex_num;
  int print_size;

  hex_num = to_num_hex_string(num);
  print_size = print_string(hex_num);
  free(hex_num);
  return (print_size);
}

int print_percent()
{
  return (print_char('%'));
}

int format_branch(char format, va_list list)
{
  int print_size;

  print_size = 0;
  if (format == 'c') print_size += print_char(va_arg(list, int));
  if (format == 's') print_size += print_string(va_arg(list, char *));
  if (format == 'p') print_size += print_pointer(va_arg(list, unsigned long long));
  if (format == 'd') print_size += print_int(va_arg(list, int));
  if (format == 'u') print_size += print_unsigned_int(va_arg(list, unsigned int));
  if (format == 'x' || format == 'X') print_size += print_hex(va_arg(list, unsigned int));
  if (format == '%') print_size += print_percent();
  return (print_size);
}

int get_print_size(const char *s, va_list list)
{
  size_t  i;
  int print_size;

  i = 0;
  print_size = 0;
  while (s[i] != '\0')
  {
    if (s[i] == '%')
    {
      print_size += format_branch(s[++i], list);
    } else print_size += print_char(s[i]);
    i++;
  }
  return (print_size);
}

int ft_printf(const char *s,...)
{
  va_list list;
  int print_size;

  va_start(list, s);
  print_size = get_print_size(s, list);
  va_end(list);
  return (print_size);
}

int main()
{
  int *i;
  int ppp = printf("%s, %c, %d, %u, %x %%\n%p\n","abbvc",'b',-199,199, 78 ,&i);
  int print_size = ft_printf("%s, %c, %d, %u, %x %%\n%p\n","abbvc",'b',-199,199,78,&i);
  printf("%d %d\n",print_size,ppp);
}