/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:54:09 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/19 02:06:38 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_get_size(char const *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i ++;
		if (s[i] == '\0')
			return (res);
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (res + 1);
			i ++;
		}
		if (s[i] == '\0')
			return (res + 1);
		res ++;
		i ++;
	}
	return (res);
}

static	char	**ft_free_all(char	**res, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(res[i]);
		i ++;
	}
	free(res);
	return (NULL);
}

static	size_t	ft_get_index(char const *s, char c, size_t i, int flg)
{
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (flg == -1)
				return (i);
			while (s[i] == c)
				i ++;
			return (i);
		}
		else
		{
			if (flg == 1)
				return (i);
		}
		i ++;
	}
	return (i);
}

static	char	**ft_next_sp(char **res, char const *s, char c, size_t res_size)
{
	size_t	front;
	size_t	back;
	size_t	i;

	back = 0;
	i = 0;
	while (i < res_size)
	{
		front = ft_get_index(s, c, back, 1);
		back = ft_get_index(s, c, front, -1);
		res[i] = (char *)malloc((back - front + 1) * sizeof(char));
		if (res[i] == NULL)
			return (ft_free_all(res, i));
		ft_strlcpy(res[i], s + front, back - front + 1);
		i ++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	res_size;

	if (s == NULL)
		return (NULL);
	res_size = ft_get_size(s, c);
	res = (char **)malloc((res_size + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (ft_next_sp(res, s, c, res_size));
}
