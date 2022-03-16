/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:10:25 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 18:46:43 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_double(t_list *head)
{
	t_list	*list;
	t_list	*tmp;

	list = head;
	while (list)
	{
		tmp = list;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (list->content == tmp->content)
			{
				write(2, "Error\n", 6);
				ft_lstclear(&head, NULL);
				return (1);
			}
		}
		list = list->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	if (check_error(argc, argv))
		return (0);
	head_a = init_list_a(argc, argv);
	head_b = init_list_b();
	if ((!head_a))
		return (0);
	if (check_double(head_a))
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
	return (0);
}
