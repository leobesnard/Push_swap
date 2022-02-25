/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:57:39 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/25 17:28:52 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	print_struct(t_op *op)
{
	printf("rra %d\n", op->rra);
	printf("rrb %d\n", op->rrb);
	printf("ra %d\n", op->ra);
	printf("rb %d\n", op->rb);
}*/

int	print_stack(t_stack *head, char c)
{
	t_stack	*stack;
	
	stack = head;
	printf("stack %c : ", c);
	while (stack)
	{
		printf("%i ", stack->num);
		stack = stack->next;
	}
	printf("\n");
	return (0);
}

int main()
{

	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_op	op;

	stack_a = NULL;
	stack_b = NULL;
	//op.ra = 0;
	//op.rb = 0;
	//op.rra = 0;
	//op.rrb = 0;
	ft_lstadd_back(&stack_a, ft_stacknew(11));
	ft_lstadd_back(&stack_a, ft_stacknew(5));
	ft_lstadd_back(&stack_a, ft_stacknew(3));
	ft_lstadd_back(&stack_a, ft_stacknew(6));
	ft_lstadd_back(&stack_a, ft_stacknew(14));
	ft_lstadd_back(&stack_a, ft_stacknew(9));
	ft_lstadd_back(&stack_a, ft_stacknew(10));
	ft_lstadd_back(&stack_a, ft_stacknew(1));
	ft_lstadd_back(&stack_a, ft_stacknew(17));
	ft_lstadd_back(&stack_a, ft_stacknew(16));
	ft_lstadd_back(&stack_a, ft_stacknew(15));
	ft_lstadd_back(&stack_a, ft_stacknew(2));
	ft_lstadd_back(&stack_b, ft_stacknew(7));
	ft_lstadd_back(&stack_b, ft_stacknew(8));
	ft_lstadd_back(&stack_b, ft_stacknew(13));
	ft_lstadd_back(&stack_b, ft_stacknew(12));
	ft_lstadd_back(&stack_b, ft_stacknew(0));
	/*printf("lowcost: %d\n", find_lowcost(&stack_a, &stack_b));
	numop(&stack_a, &stack_b, find_lowcost(&stack_a, &stack_b), &op);
	print_struct(&op);
	execop(&stack_a, &stack_b, &op);*/
	//printf("mediane : %d\n", find_med(&stack_a));
	sorting(&stack_a, &stack_b);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	return (0);
}
