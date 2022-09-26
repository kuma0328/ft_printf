/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:36:49 by hnakatan          #+#    #+#             */
/*   Updated: 2022/08/04 17:10:43 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_branch(char	format, va_list	list)
{
	int	res;

	if (format == 'c')
		res = print_char(va_arg(list, int));
	if (format == 's')
		res = print_string(va_arg(list, char *));
	if (format == 'p')
		res = print_pointer(va_arg(list, uintptr_t));
	if (format == 'd' || format == 'i')
		res = print_int(va_arg(list, int));
	if (format == 'u')
		res = print_unsigned_int(va_arg(list, unsigned int));
	if (format == 'x')
		res = print_lower_hex(va_arg(list, unsigned int));
	if (format == 'X')
		res = print_upper_hex(va_arg(list, unsigned int));
	if (format == '%')
		res = print_percent();
	return (res);
}

static int	get_print_size(const char	*s, va_list	list)
{
	size_t	i;
	int		res;
	int		print_size;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			print_size = format_branch(s[++i], list);
		else
			print_size = print_char(s[i]);
		if (print_size == -1 || res > INT_MAX - print_size)
			return (-1);
		res += print_size;
		i++;
	}
	return (res);
}

int	ft_printf(const char	*s, ...)
{
	va_list	list;
	int		res;

	va_start(list, s);
	res = get_print_size(s, list);
	va_end(list);
	return (res);
}

int main()
{
	ft_printf("%s %s %s\n","ii","oo","dd");
}