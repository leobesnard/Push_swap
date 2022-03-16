/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:33:33 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 18:51:22 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int	is_sort(t_list **head)
{
	t_list	*stack;

	stack = *head;
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_double(t_list *head)
{
	t_list	*list;
	t_list	*tmp;

	list = head;
	while (list)
	{
		tmp = list;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (list->content == tmp->content)
			{
				write(2, "Error\n", 6);
				ft_lstclear(&head, NULL);
				return (1);
			}
		}
		list = list->next;
	}
	return (0);
}
