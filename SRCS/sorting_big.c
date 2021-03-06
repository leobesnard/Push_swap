/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 19:11:16 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	filop(t_s head, t_op *op, int cindex, int mindex)
{
	op->ra = 0;
	op->rb = 0;
	op->rra = 0;
	op->rrb = 0;
	if (mindex > ((size(head.a) / 2) + 1))
		op->rra = size(head.a) - mindex;
	else
		op->ra = mindex;
	if (cindex > ((size(head.b) / 2) + 1))
		op->rrb = size(head.b) - cindex;
	else
		op->rb = cindex;
	return (0);
}

int	numop(t_list **head_a, t_list **head_b, int index, t_op *op)
{
	if (get_value(index, head_b) > get_value(maxindex(head_a), head_a))
		filop((t_s){head_a, head_b}, op, index, minindex(head_a));
	else
		filop((t_s){head_a, head_b}, op, index,
			find_sup(get_value(index, head_b), head_a));
	return (0);
}

void	execop(t_list **head_a, t_list **head_b, t_op *op)
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

int	is_sort(t_list **head)
{
	t_list	*stack;

	stack = *head;
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sorting(t_list **head_a, t_list **head_b)
{
	t_op	op;

	op.ra = 0;
	op.rb = 0;
	op.rra = 0;
	op.rrb = 0;
	while (*head_b)
	{
		numop(head_a, head_b, find_lowcost(head_a, head_b), &op);
		execop(head_a, head_b, &op);
		pab(head_a, head_b, 'a');
	}
	return (0);
}
