/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:46:45 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/18 21:43:26 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	return (new);
}

t_stack	*init_stack_a(int argc, char **argv)
{
	int 	i;
	t_stack	*head;
	t_stack	*tmp;
	
	i = 2;
	head = ft_stacknew(ft_atoi(argv[i]));
	i++;
	while (i <= argc)
	{
		tmp = ft_stacknew(ft_atoi(argv[i]));
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	return (head);
}

t_stack	*init_stack_b(int argc)
{
	int 	i;
	t_stack	*head;
	t_stack	*tmp;
	
	i = 2;
	head = ft_stacknew(NULL);
	i++;
	while (i <= argc)
	{
		tmp = ft_stacknew(NULL);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	return (head);
}
