/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:36:57 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 18:49:29 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (0);
}

int	ft_sab(t_list **head)
{
	t_list	*stack;

	stack = *head;
	if (stack && stack->next)
		swap(&stack->content, &stack->next->content);
	return (0);
}

int	ft_pab(t_list **head_to, t_list **head_from)
{
	t_list	*to;
	t_list	*from;

	to = *head_to;
	from = *head_from;
	if (from)
	{
		*head_from = from->next;
		from->next = to;
		*head_to = from;
	}
	return (0);
}

int	ft_rab(t_list **head)
{
	t_list	*stack;

	stack = *head;
	if (!*head)
		return (0);
	while (stack->next)
	{
		swap(&stack->content, &stack->next->content);
		stack = stack->next;
	}
	return (0);
}

int	ft_rrab(t_list **head)
{
	t_list	*last;
	t_list	*stack;

	stack = *head;
	while (stack->next->next)
	{
		stack = stack->next;
	}
	last = stack->next;
	stack->next = NULL;
	last->next = *head;
	*head = last;
	return (0);
}
