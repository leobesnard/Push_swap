/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/25 22:03:15 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	print_struct(t_op *op)
{
	printf("rra %d\n", op->rra);
	printf("rrb %d\n", op->rrb);
	printf("ra %d\n", op->ra);
	printf("rb %d\n", op->rb);
}


int	filop(t_stack **head_a, t_stack **head_b, t_op *op, int cindex, int mindex)
{
	op->ra = 0;
	op->rb = 0;
	op->rra = 0;
	op->rrb = 0;
	if (mindex > ((size(head_a) / 2) + 1))
		op->rra = size(head_a) - mindex;
	else
		op->ra = mindex;
	if (cindex > ((size(head_b) / 2) + 1))
		op->rrb = size(head_b) - cindex;
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
	//print_struct(op);
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

int	is_sort(t_stack **head)
{
	t_stack	*stack;

	stack = *head;
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sorting(t_stack **head_a, t_stack **head_b)
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
		/*print_stack(*head_a, 'a');
		print_stack(*head_b, 'b');*/
	}
	return (0);
}