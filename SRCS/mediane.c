/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:05:36 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/24 18:23:17 by lbesnard         ###   ########.fr       */
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
	tab = malloc(sizeof(*tab) * size(&stack));
	tab[i] = get_value(minindex(&stack), &stack);
	while (i < size(&stack))
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
			rrab(head, 'q');
			index++;
		}
	return (0);
}

int	med_top(t_stack **head_a)
{
	t_stack *stack;
	int		i;
	int		first_med;
	int		last_med;

	stack = *head_a;
	first_med = -1;
	while (stack)
	{
		if (stack->num < find_med(&head_a))
		{
			if (first_med == -1)
				first_med = i;
			else
				last_med = i;
		}
		stack = stack->next;
	}
	if (range(head_a, first_med) <= range(head_a, last_med))
		to_top(head_a, first_med);
	else
		to_top(head_a, last_med);
}

int	push_med(t_stack **head_a, t_stack **head_b)
{
	t_stack	*stack;
	int		med;
	int		i;

	stack = *head_a;
	med = find_med(&stack);
	i = 0;
	while (!is_sort(head_a))
	{
		while(under_med(head_a, med))
		{
			if (stack->num <= med)
			{
				
			}
			stack = stack->next;
		}
		med = find_med(head_a);
	}
	return(0);
}
