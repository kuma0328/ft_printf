/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan <hnakatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 07:14:54 by hnakatan          #+#    #+#             */
/*   Updated: 2022/02/06 01:55:38 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_content;

	res = NULL;
	while (lst != NULL)
	{
		if (f != NULL)
			new_content = ft_lstnew(f(lst->content));
		else
			new_content = ft_lstnew(lst->content);
		if (new_content == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new_content);
		lst = lst->next;
	}
	return (res);
}
