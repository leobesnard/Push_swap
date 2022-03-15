/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:57:39 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/15 18:26:37 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_struct(t_op *op)
{
	printf("rra %d\n", op->rra);
	printf("rrb %d\n", op->rrb);
	printf("ra %d\n", op->ra);
	printf("rb %d\n", op->rb);
}*/

int	print_list(t_list *head, char c)
{
	t_list	*stack;
	
	stack = head;
	ft_printf("stack %c : ", c);
	while (stack)
	{
		ft_printf("%i ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
	return (0);
}

int main()
{

	t_list	*stack_a;
	t_list	*stack_b;
	//t_op	op;

	stack_a = NULL;
	stack_b = NULL;
	//op.ra = 0;
	//op.rb = 0;
	//op.rra = 0;
	//op.rrb = 0;
	ft_lstadd_back(&stack_a, ft_listnew(3));
	ft_lstadd_back(&stack_a, ft_listnew(2));
	ft_lstadd_back(&stack_a, ft_listnew(1));
	ft_lstadd_back(&stack_a, ft_listnew(6));
	ft_lstadd_back(&stack_a, ft_listnew(14));
	/*ft_lstadd_back(&stack_a, ft_listnew(9));
	ft_lstadd_back(&stack_a, ft_listnew(10));
	ft_lstadd_back(&stack_a, ft_listnew(1));
	ft_lstadd_back(&stack_a, ft_listnew(17));
	ft_lstadd_back(&stack_a, ft_listnew(16));
	ft_lstadd_back(&stack_a, ft_listnew(15));
	ft_lstadd_back(&stack_a, ft_listnew(2));
	ft_lstadd_back(&stack_b, ft_listnew(7));
	ft_lstadd_back(&stack_b, ft_listnew(8));
	ft_lstadd_back(&stack_b, ft_listnew(13));
	ft_lstadd_back(&stack_b, ft_listnew(12));
	ft_lstadd_back(&stack_b, ft_listnew(0));*/
	/*printf("lowcost: %d\n", find_lowcost(&stack_a, &stack_b));
	numop(&stack_a, &stack_b, find_lowcost(&stack_a, &stack_b), &op);
	print_struct(&op);
	execop(&stack_a, &stack_b, &op);*/
	//printf("mediane : %d\n", find_med(&stack_a));
	//sorting(&stack_a, &stack_b);
	sorting_small(&stack_a, &stack_b);
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	return (0);
}
