/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:39:46 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/19 20:58:11 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sab(t_stack **head)
{
	t_stack	*stack;
	
	stack = *head;
	if (stack && stack->next)
		ft_swap(&stack->num, &stack->next->num);
	return (0);
}

int	pab(t_stack **head_to,t_stack **head_from)
{
	t_stack	*to;
	t_stack	*from;
	
	if (from)
	{
		to = *head_to;
		from = *head_from;
		*head_from = from->next;
		from->next = to;
		*head_to = from;
	}
	return (0);
}

int	rab(t_stack **head)
{
	t_stack	*stack;

	stack = *head;
	if (!*head)
		return (0);
	while (stack->next)
	{
		ft_swap(stack->num,stack->next->num);
		stack = stack->next;
	}
	return (0);
}

int	rrab(t_stack **head)
{
	t_stack	*last;
	t_stack	*stack;
	
	stack = *head;
	while(stack->next->next)
	{
		stack = stack->next;
	}
	last = stack->next;
	stack->next = NULL;
	last->next = *head;
	*head = last;
}
