/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:59:07 by hnakatan          #+#    #+#             */
/*   Updated: 2022/03/01 02:53:58 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d_cast;
	const unsigned char	*s_cast;

	d_cast = (unsigned char *)dst;
	s_cast = (const unsigned char *)src;
	if (d_cast == NULL && s_cast == NULL)
		return (dst);
	if (d_cast < s_cast)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			d_cast[len - 1] = s_cast[len - 1];
			len --;
		}
	}
	return (dst);
}
