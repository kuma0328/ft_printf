/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:43:15 by hnakatan          #+#    #+#             */
/*   Updated: 2022/08/04 17:19:50 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(char *s)
{
	size_t	i;

	if (s == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
		i++;
	if (i > INT_MAX)
		return (-1);
	return (write(1, s, i));
}