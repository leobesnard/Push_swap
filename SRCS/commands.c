/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:39:46 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 18:48:36 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (0);
}

int	sab(t_list **head, char c)
{
	t_list	*stack;

	stack = *head;
	if (stack && stack->next)
		ft_swap(&stack->content, &stack->next->content);
	ft_printf("s%c\n", c);
	return (0);
}

int	pab(t_list **head_to, t_list **head_from, char c)
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
	ft_printf("p%c\n", c);
	return (0);
}

int	rab(t_list **head, char c)
{
	t_list	*stack;

	stack = *head;
	if (!*head)
		return (0);
	while (stack->next)
	{
		ft_swap(&stack->content, &stack->next->content);
		stack = stack->next;
	}
	if (c == 'r')
		ft_printf("rr\n");
	else if (c == 'd')
		return (0);
	else
		ft_printf("r%c\n", c);
	return (0);
}

int	rrab(t_list **head, char c)
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
	if (c == 'r')
		ft_printf("rrr\n");
	else if (c == 'd')
		return (0);
	else
		ft_printf("rr%c\n", c);
	return (0);
}
