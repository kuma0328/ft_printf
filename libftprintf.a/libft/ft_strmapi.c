/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:55:14 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/10 23:35:15 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	s_len = ft_strlen(s);
	i = 0;
	res = (char *)malloc((s_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < s_len)
	{
		res[i] = f((unsigned int)i, s[i]);
		i ++;
	}
	res[i] = '\0';
	return (res);
}
