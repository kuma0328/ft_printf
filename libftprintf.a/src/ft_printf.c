#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdint.h>
#include "ft_printf.h"

int print_unsigned_int(unsigned int num)
{
  if (num == 0) return print_char('0');
  return (write_unsigned_int(num));
}

int write_unsigned_int(unsigned long long num)
{
  if (num == 0) return (0);
  return write_int(num / 10) + print_char(num % 10 + '0');
}

int format_branch(char format, va_list list)
{
  int print_size;

  print_size = 0;
  if (format == 'c') print_size += print_char(va_arg(list, int));
  if (format == 's') print_size += print_string(va_arg(list, char *));
  if (format == 'p') print_size += print_pointer(va_arg(list, uintptr_t));
  if (format == 'd' || format == 'i') print_size += print_int(va_arg(list, int));
  if (format == 'u') print_size += print_unsigned_int(va_arg(list, unsigned int));
  if (format == 'x') print_size += print_lower_hex(va_arg(list, unsigned int));
  if (format == 'X') print_size += print_upper_hex(va_arg(list, unsigned int));
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
    if (s[i] == '%') print_size += format_branch(s[++i], list);
    else print_size += print_char(s[i]);
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

// int main(){
//   int *i;
//   // int ppp = printf("%s, %c, %d, %u, %X %%\n%p\n","abbvc",'b',-199,100, 1000 ,&i);
//   // int print_size = ft_printf("%s, %c, %d, %u, %X %%\n%p\n","abbvc",'b',-199,100,1000,&i);
//   ft_printf("%s\n",NULL);
//   printf("%u %x\n",-1,-1);
//   ft_printf("%u %x\n",-1,-1);
//   // write_pointer(&i);
//   // printf("%d %d\n",print_size,ppp);
// }