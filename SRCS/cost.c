/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:13:49 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/15 18:26:04 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_sup(int value, t_list **head)
{
	int		diff;
	int		index;
	int		i;
	t_list	*stack;
	
	i = 0;
	diff = 2000;
	stack = *head;
	index = 0;
	if (!head)
		return (0);
	if (size(head) == 1)
		return (0);
	while (stack)
	{
		if ((stack->content - value < diff) && ((stack->content - value) > 0))
		{
			diff = stack->content - value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	range(t_list **head_a, int index)
{
	int	cost;

	cost = 0;
	if (index > ((size(head_a) / 2) + 1))
		cost += size(head_a) - index;
	else
		cost += index;
	return (cost);
}

int	cost(t_list **head_a, t_list **head_b, int index)
{
	int	cost;
	int	supindex;
	
	if (get_value(index, head_b) > get_value(maxindex(head_a), head_a))
		cost = range(head_a, minindex(head_a)) + range(head_b, index);
	else 
	{
		supindex = find_sup(get_value(index, head_b), head_a);
		cost = range(head_a, supindex)  + range(head_b, index);
	}
	return (cost);
}

int	find_lowcost(t_list **head_a, t_list **head_b)
{
	int		lowcost;
	int		index;
	int		i;
	t_list	*stack;
	
	stack = *head_b;
	i = 0;
	lowcost = cost(head_a, head_b, i);
	index = 0;
	while (stack)
	{
		if (cost(head_a, head_b, i) < lowcost)
		{
			lowcost = cost(head_a, head_b, i);
			index = i;
		}
		stack = stack->next;
		i++;	
	}
	return (index);
}
