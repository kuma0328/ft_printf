/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:15:23 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/10 23:38:46 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cast;
	size_t			i;

	b_cast = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_cast[i] = (unsigned char)c;
		i ++;
	}
	return (b);
}
