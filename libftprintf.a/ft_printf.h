#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>
int print_char(int c);
int print_string(char *s);
int write_upper_hex(unsigned long long num);
int write_lower_hex(unsigned long long num);
int print_pointer(uintptr_t num);
int print_int(int num);
int print_hex(unsigned int num);
int print_lower_hex(unsigned int num);
int print_upper_hex(unsigned int num);
int write_int(long long num);
int write_unsigned_int(unsigned long long num);
int print_unsigned_int(unsigned int num);
int print_percent();
int format_branch(char format, va_list list);
int get_print_size(const char *s, va_list list);
int ft_printf(const char *s,...);

#endif