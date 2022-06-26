/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:10:57 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/03 03:13:11 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	size_t	i;

	res = NULL;
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char )c)
			res = (char *)s + i;
		i ++;
	}
	return (res);
}
