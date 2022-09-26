/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:02:32 by hnakatan          #+#    #+#             */
/*   Updated: 2022/08/04 17:31:13 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hex(unsigned int	num, char	c)
{
	if (num == 0)
		return (0);
	if (num % 16 <= 9)
		return (write_hex(num / 16, c) + print_char(num % 16 + '0'));
	else
		return (write_hex(num / 16, c) + print_char(num % 16 - 10 + c));
}

static int	get_hex_size(unsigned int	num)
{
	int	res;

	res = 0;
	while (num / 16 != 0)
	{
		num /= 16;
		res++;
	}
	return (res + 1);
}

int	print_upper_hex(unsigned int	num)
{
	int	res;

	if (num == 0)
		return (print_char('0'));
	res = write_hex(num, 'A');
	if (res != get_hex_size(num))
		return (-1);
	return (res);
}

int	print_lower_hex(unsigned int	num)
{
	int	res;

	if (num == 0)
		return (print_char('0'));
	res = write_hex(num, 'a');
	if (res != get_hex_size(num))
		return (-1);
	return (res);
}


