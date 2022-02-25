/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:10:25 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/25 17:57:08 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (check_error(argc, argv))
		return (0);
	head_a = init_stack_a(argc, argv);
	head_b = init_stack_b();
	if ((!head_a))
		return (0);
	//print_stack(head_a, 'a');
	//print_stack(head_b, 'b');
	sorting(&head_a, &head_b);
	to_top(&head_a, minindex(&head_a));
	/* print_stack(head_a, 'a');
	print_stack(head_b, 'b'); */
	return (0);
}
