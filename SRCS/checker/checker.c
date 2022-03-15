/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:02:18 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/15 23:49:24 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static int	operation(t_list **head_a, t_list **head_b, char *line)
{
	if (!ft_strncmp(line, "ra", 3))
		ft_rab(head_a);
	else if (!ft_strncmp(line, "rb", 3))
		ft_rab(head_b);
	else if (!ft_strncmp(line, "rr", 3))
		ft_rr(head_a, head_b);
	else if (!ft_strncmp(line, "rra", 4))
		ft_rrab(head_a);
	else if (!ft_strncmp(line, "rrb", 4))
		ft_rrab(head_b);
	else if (!ft_strncmp(line, "rrr", 4))
		ft_rrr(head_a, head_b);
	else if (!ft_strncmp(line, "pb", 3))
		ft_pab(head_b, head_a);
	else if (!ft_strncmp(line, "pa", 3))
		ft_pab(head_a, head_b);
	else if (!ft_strncmp(line, "sa", 3))
		ft_sab(head_a);
	else if (!ft_strncmp(line, "sb", 3))
		ft_sab(head_b);
	else if (!ft_strncmp(line, "ss", 3))
		ft_ss(head_a, head_b);
	else 
		return (write (2, "Error\n", 6));
	return (0);
}

int	checker(t_list **head_a, t_list **head_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (operation(head_a, head_b, line))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

void	verdict(t_list **head_a, t_list **head_b)
{
	if (*head_b != NULL || !is_sort(head_a))
	{
		ft_printf("KO\n");
		return;
	}
	ft_printf("OK\n");
	return;
}

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
	if (checker(&head_a, &head_b))
	{
		ft_lstclear(&head_a, NULL);
		ft_lstclear(&head_b, NULL);
		return (0);
	}
	verdict(&head_a, &head_b);
	print_list(head_a, 'a');
	print_list(head_b, 'b');
	ft_lstclear(&head_a, NULL);
	ft_lstclear(&head_b, NULL);
	return (0);
	
}
