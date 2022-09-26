/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:55:06 by hnakatan          #+#    #+#             */
/*   Updated: 2022/08/04 17:12:40 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_unsigned_int(unsigned int	num)
{
	if (num == 0)
		return (0);
	return (write_unsigned_int(num / 10) + print_char(num % 10 + '0'));
}

static int	get_unsigned_int_size(unsigned int	 num)
{
	int	res;

	res = 0;
	while (num / 10 != 0)
	{
		res ++;
		num /= 10;
	}
	return (res + 1);
}

int	print_unsigned_int(unsigned int	num)
{
	int	res;

	if (num == 0)
		return (print_char('0'));
	res = write_unsigned_int(num);
	if (res != get_unsigned_int_size(num))
		return (-1);
	return (res);
}

