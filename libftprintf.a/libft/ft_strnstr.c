/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:21:39 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/21 06:57:41 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
		return ((char *)haystack);
	while (len > 0 && haystack[i] != '\0' && i + needle_len <= len)
	{
		if (ft_memcmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
		i ++;
	}
	return (NULL);
}
