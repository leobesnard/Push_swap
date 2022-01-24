/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:58:24 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/24 16:58:52 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(t_stack *head)
{
	t_stack	*stack;
	int		min;
	int		i;

	stack = head;
	i = 1;
	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
		}
		i++;
		stack = stack->next;
	}
	return (min);
}

int	ft_max(t_stack *head)
{
	t_stack	*stack;
	int		max;
	int		i;

	stack = head;
	i = 1;
	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
		}
		i++;
		stack = stack->next;
	}
	return (max);
}
