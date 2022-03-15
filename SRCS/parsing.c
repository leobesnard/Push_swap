/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:46:45 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/15 19:43:52 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstaddd_back(t_list **alst, t_list *new)
{
	t_list	*last;

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

t_list	*ft_listnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*init_list_a(int argc, char **argv)
{
	int 	i;
	t_list	*head;
	t_list	*tmp;
	
	i = 1;
	head = ft_lstnew(ft_atoi(argv[i]));
	if (!head)
		return(NULL);
	i++;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		if (!tmp)
			return (NULL);
		ft_lstaddd_back(&head, tmp);
		i++;
	}
	return (head);
}

t_list	*init_list_b(void)
{
	t_list	*head;
	
	head = NULL;
	return (head);
}
