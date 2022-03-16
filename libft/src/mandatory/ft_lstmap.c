/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:28:49 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 18:13:02 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_new_back(t_list *lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (0);
	ft_lstadd_back(&lst, new);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, t_con (*f)(t_con), void (*del)(t_con))
{
	t_list	*head;

	if (!lst)
		return (0);
	head = ft_lstnew((*f)(lst->content));
	while (lst->next)
	{
		lst = lst->next;
		if (!ft_new_back(head, (*f)(lst->content)))
		{
			ft_lstclear(&head, del);
			return (0);
		}
	}
	return (head);
}
