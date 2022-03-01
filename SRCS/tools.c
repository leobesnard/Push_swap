/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:14:36 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/01 18:02:38 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	size(t_list **head)
{
	int		i;
	t_list	*stack;

	i = 0;
	stack = *head;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_value(int index, t_list **head)
{
	t_list	*stack;
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
	return (stack->content);
}

int	maxindex(t_list **head)
{
	t_list	*stack;
	int		max;
	int		index;
	int		i;

	stack = *head;
	i = 0;
	index = 0;
	if (!*head)
		return (0);
	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	minindex(t_list **head)
{
	t_list	*stack;
	int		min;
	int		index;
	int		i;

	stack = *head;
	i = 0;
	index = 0;
	if (!*head)
		return (0);
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}
