/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:10:25 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/01 18:08:24 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	if (check_error(argc, argv))
		return (0);
	head_a = init_list_a(argc, argv);
	head_b = init_list_b();
	if ((!head_a))
		return (0);
	if (size(&head_a) < 6)
		sorting_small(&head_a, &head_b);
	else
	{
		if (size(&head_a) > 101)
			push_med(&head_a, &head_b);
		else 
			while (!is_sort(&head_a) || size(&head_a) == 2)
				pab(&head_b, &head_a, 'b');
		sorting(&head_a, &head_b);
		to_top(&head_a, minindex(&head_a));
	}
	ft_lstclear(&head_a, NULL);
	//ft_lstclear(&head_b, NULL);
	/* print_list(head_a, 'a');
	print_list(head_b, 'b'); */
	return (0);
}
