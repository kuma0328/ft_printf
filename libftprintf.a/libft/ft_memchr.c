/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:37:19 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/10 23:41:29 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cast;
	size_t				i;

	s_cast = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == (unsigned char)c)
			return ((void *)s_cast + i);
		i ++;
	}
	return (NULL);
}
