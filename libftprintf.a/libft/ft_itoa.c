/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:07:48 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/02 01:22:21 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
