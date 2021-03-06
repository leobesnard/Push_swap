/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:05:36 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/17 19:23:23 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med(t_list **head)
{
	int		i;
	int		*tab;
	int		tmp;
	int		ret;
	t_list	*stack;

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

int	to_top(t_list **head, int index)
{
	if (index < ((size(head) / 2) + 1))
	{
		while (index > 0)
		{
			rab(head, 'a');
			index--;
		}
	}
	else
	{
		while (index < size(head))
		{
			rrab(head, 'a');
			index++;
		}
	}
	return (0);
}

void	med_top(t_list **head_a, int med)
{
	int		i;
	int		first_med;
	int		last_med;
	t_list	*stack;

	first_med = -1;
	last_med = -1;
	i = 0;
	stack = *head_a;
	while (stack)
	{
		if (stack->content <= med)
		{
			if (first_med == -1)
				first_med = i;
			else
				last_med = i;
		}
		stack = stack->next;
		i++;
	}
	med_top2(first_med, last_med, head_a);
}

int	under_med(t_list **head, int med)
{
	t_list	*stack;

	stack = *head;
	while (stack)
	{
		if (stack->content < med)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	push_med(t_list **head_a, t_list **head_b)
{
	t_list	*stack;
	int		med;

	stack = *head_a;
	med = find_med(&stack);
	while (!is_sort(head_a))
	{
		while (under_med(head_a, med))
		{
			med_top(head_a, med);
			pab(head_b, head_a, 'b');
		}
		if (!size(head_a))
			return (0);
		med = find_med(head_a);
	}
	return (0);
}
