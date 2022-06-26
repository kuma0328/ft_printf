/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:57:10 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/10 23:41:04 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cast;
	const unsigned char	*s2_cast;
	size_t				i;

	s1_cast = (const unsigned char *)s1;
	s2_cast = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cast[i] != s2_cast[i])
			return (s1_cast[i] - s2_cast[i]);
		i ++;
	}
	return (0);
}
