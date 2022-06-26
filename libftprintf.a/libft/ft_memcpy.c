/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:07:15 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/10 23:40:09 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d_cast;
	const unsigned char	*s_cast;
	size_t				i;

	d_cast = (unsigned char *)dst;
	s_cast = (const unsigned char *)src;
	i = 0;
	if (d_cast == NULL && s_cast == NULL)
		return (dst);
	while (i < n)
	{
		d_cast[i] = s_cast[i];
		i ++;
	}
	return (dst);
}
