/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:05:41 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/24 16:58:48 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	find_min(t_stack *head)
{
	t_stack	*stack;
	int		min;
	int		index;
	int		i;

	stack = head;
	i = 1;
	index = 0;
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

int	find_max(t_stack *head)
{
	t_stack	*stack;
	int		max;
	int		index;
	int		i;

	stack = head;
	i = 1;
	index = 0;
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

int	totop(t_stack **head, int index, int nb, char c)
{
	int	i;

	i = 0;
	if (!(*head)->next)
		return (0);
	if (index <= ((nb / 2) + 1))
	{
		while (i < (index - 1))
		{
			rab(head);
			printf("r%c\n", c);
			//print_stack(*head, 'a');
			i++;
		}
	}
	else
	{
		i = nb;
		while (i > (index - 1))
		{
			rrab(head);
			printf("rr%c\n", c);
			//print_stack(*head, 'a');
			i--;
		}
	}
	return (0);
}

int	scantop(t_stack *head, int chunkmin, int chunkmax)
{
	t_stack	*stack;
	int		index;
	int		i;

	stack = head;
	i = 1;
	index = -1;
	while (stack)
	{
		if (stack->num >= chunkmin && stack->num <= chunkmax)
		{
			index = i;
			return (index);
		}
		i++;
		stack = stack->next;
	}
	return (index);
}
