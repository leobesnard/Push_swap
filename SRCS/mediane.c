/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:05:36 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/25 18:09:00 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_med(t_stack **head)
{
	int		i;
	int		*tab;
	int		tmp;
	int		ret;
	t_stack *stack;
	
	i = 0;
	stack = *head;
	tmp = 0;
	tab = malloc(sizeof(*tab) * size(head));
	if (!tab)
		return (0);
	tab[i] = get_value(minindex(&stack), &stack);
	while (i + 1 < size(&stack))
	{
		tmp = tab[i];
		i++;
		tab[i] = get_value(find_sup(tmp, &stack), &stack);
	}
	i = size(&stack) / 2;
	ret = tab [i];
	free(tab);
	return (ret);
}

int	to_top(t_stack **head, int index)
{
	if (index < ((size(head) / 2) + 1))
		while (index > 0)
		{
			rab(head, 'a');
			index--;
		}
	else
		while (index < size(head))
		{
			rrab(head, 'a');
			index++;
		}
	return (0);
}

int	med_top(t_stack **head_a, int med)
{
	t_stack *stack;
	int		i;
	int		first_med;
	int		last_med;

	stack = *head_a;
	first_med = -1;
	last_med = -1;
	i = 0;
	while (stack)
	{
		if (stack->num <= med)
		{
			if (first_med == -1)
				first_med = i;
			else
				last_med = i;
		}
		stack = stack->next;
		i++;
	}
	if (last_med == -1)
		to_top(head_a, first_med);
	else if (range(head_a, first_med) <= range(head_a, last_med))
		to_top(head_a, first_med);
	else
		to_top(head_a, last_med);
	return (0);
}

int	under_med(t_stack **head, int med)
{
	t_stack	*stack;

	stack = *head;
	while (stack)
	{
		if (stack->num < med)
			return (1);
		stack = stack->next;
	}
	return(0);
}

int	push_med(t_stack **head_a, t_stack **head_b)
{
	t_stack	*stack;
	int		med;

	stack = *head_a;
	med = find_med(&stack);
	while (!is_sort(head_a))
	{
		while(under_med(head_a, med))
		{
			med_top(head_a, med);
			pab(head_b, head_a, 'b');
		}
		if (!size(head_a))
			return (0);
		med = find_med(head_a);
	}
	return(0);
}
