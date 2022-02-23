/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/23 23:03:14 by lbesnard         ###   ########.fr       */
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
