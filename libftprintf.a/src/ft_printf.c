#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdint.h>
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

int write_lower_hex(unsigned long long num)
{
  if (num != 0) {
    if (num % 16 <= 9) return write_lower_hex(num / 16) + print_char(num % 16 + '0');
    else return write_lower_hex(num / 16) + print_char(num % 16 - 10 + 'a');
  }
}

int write_upper_hex(unsigned long long num)
{
  if (num != 0) {
    if (num % 16 <= 9) return write_upper_hex(num / 16) + print_char(num % 16 + '0');
    else return write_upper_hex(num / 16) + print_char(num % 16 - 10 + 'A');
  }
}

int print_pointer(uintptr_t num)
{
  int print_size;
  char  *hex_num;

  print_size = print_string("0x");
  print_size += write_lower_hex(num);
  return (print_size);
}

int write_int(long long num)
{
  if (num != 0) return write_int(num / 10) + print_char(num % 10 + '0');
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

int print_unsigned_int(unsigned int num)
{
  return (print_int(num));
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
  if (format == 'p') print_size += print_pointer(va_arg(list, uintptr_t));
  if (format == 'd') print_size += print_int(va_arg(list, int));
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

int main(){
  int *i;
  int ppp = printf("%s, %c, %d, %u, %X %%\n%p\n","abbvc",'b',-199,100, 1000 ,&i);
  int print_size = ft_printf("%s, %c, %d, %u, %X %%\n%p\n","abbvc",'b',-199,100,1000,&i);

  // write_pointer(&i);
  printf("%d %d\n",print_size,ppp);
}