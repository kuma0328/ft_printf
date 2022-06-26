/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:06:43 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/21 07:49:01 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	front;
	size_t	back;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1);
	while (s1[front] != '\0' && ft_strchr(set, s1[front]) != NULL)
		front ++;
	while (back > 0 && ft_strchr(set, s1[back - 1]) != NULL)
		back --;
	if (front >= back)
		return (ft_strdup(""));
	res = (char *)malloc((back - front + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + front, back - front + 1);
	return (res);
}
