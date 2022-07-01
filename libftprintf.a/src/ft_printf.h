#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>

int print_char(int c);
int print_percent();
int print_upper_hex(unsigned int num);
int print_lower_hex(unsigned int num);
int write_hex(unsigned long long num, char c);
int get_hex_size(unsigned long long num);
int print_int(int num);
int write_int(long long num);
int get_int_size(int  num);
int print_unsigned_int(unsigned int num);
int write_unsigned_int(unsigned long long num);
int get_unsigned_int_size(unsigned int  num);
int print_pointer(uintptr_t num);
int write_pointer(uintptr_t num);
int get_pointer_size(uintptr_t num);
int print_string(char *s);
int format_branch(char format, va_list list);
int get_print_size(const char *s, va_list list);
int ft_printf(const char *s,...);

#endif