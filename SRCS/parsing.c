/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:46:45 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/20 16:29:53 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*last;

	last = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
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
	
	i = 1;
	head = ft_stacknew(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		tmp = ft_stacknew(ft_atoi(argv[i]));
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	return (head);
}

t_stack	*init_stack_b(void)
{
	t_stack	*head;
	
	head = NULL;
	return (head);
}
