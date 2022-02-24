/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/24 15:03:46 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	filop(t_stack **head_a, t_stack **head_b, t_op *op, int cindex, int mindex)
{
		if (mindex > ((size(head_a) / 2) + 1))
			op->rra = size(head_a) + 1 - mindex;
		else
			op->ra = mindex;
		if (cindex > ((size(head_b) / 2) + 1))
			op->rrb = size(head_b) + 1 - cindex;
		else 
			op->rb = cindex;
		return (0);
}

int	numop(t_stack **head_a, t_stack **head_b, int index, t_op *op)
{
	if (get_value(index, head_b) > get_value(maxindex(head_a), head_a))
		filop(head_a, head_b, op, index, minindex(head_a));
	else
		filop(head_a, head_b, op, index, find_sup(get_value(index, head_b), head_a));
	return (0);
}

void	execop(t_stack **head_a, t_stack **head_b, t_op *op)
{
	while (op->ra && op->rb)
	{
		rr(head_a, head_b);
		op->ra--;
		op->rb--;
	}
	while (op->rra && op->rrb)
	{
		rrr(head_a, head_b);
		op->rra--;
		op->rrb--;
	}
	while (op->ra--)
		rab(head_a, 'a');
	while (op->rb--)
		rab(head_b, 'b');
	while (op->rra--)
		rrab(head_a, 'a');
	while (op->rrb--)
		rrab(head_b, 'b');	
}

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

/*int	sorting(t_stack **head_a, t_stack **head_b)
{
	while (!is_sort(head_a))
	{
		find_med(head_a);
	}
}*/
