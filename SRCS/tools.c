/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:14:36 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/25 16:41:26 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	size(t_stack **head)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = *head;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_value(int index, t_stack **head)
{
	t_stack	*stack;
	int		i;
	
	stack = *head;
	i = 0;
	if (!*head)
		return (0);
	while (i < index)
	{
		stack = stack->next;
		i++;
	}
	return (stack->num);
}

int	maxindex(t_stack **head)
{
	t_stack	*stack;
	int		max;
	int		index;
	int		i;

	stack = *head;
	i = 0;
	index = 0;
	if (!*head)
		return (0);
	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	minindex(t_stack **head)
{
	t_stack	*stack;
	int		min;
	int		index;
	int		i;

	stack = *head;
	i = 0;
	index = 0;
	if (!*head)
		return (0);
	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}
