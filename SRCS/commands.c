/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:39:46 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/25 15:40:35 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	ft_swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
	return (0);
}

int	sab(t_stack **head)
{
	t_stack	*stack;
	
	stack = *head;
	if (stack && stack->next)
		ft_swap(&stack->num, &stack->next->num);
	return (0);
}

int	pab(t_stack **head_to,t_stack **head_from, char c)
{
	t_stack	*to;
	t_stack	*from;
	
	to = *head_to;
	from = *head_from;
	if (from)
	{
		*head_from = from->next;
		from->next = to;
		*head_to = from;
	}
	printf("p%c\n", c);
	return (0);
}

int	rab(t_stack **head, char c)
{
	t_stack	*stack;

	stack = *head;
	if (!*head)
		return (0);
	while (stack->next)
	{
		ft_swap(&stack->num,&stack->next->num);
		stack = stack->next;
	}
	if (c == 'r')
		printf("rr\n");
	else if (c == 'd')
		return (0);
	else
		printf("r%c\n", c);
	return (0);
}

int	rrab(t_stack **head, char c)
{
	t_stack	*last;
	t_stack	*stack;
	
	stack = *head;
	while(stack->next->next)
	{
		stack = stack->next;
	}
	last = stack->next;
	stack->next = NULL;
	last->next = *head;
	*head = last;
	if (c == 'r')
		printf("rrr\n");
	else if (c == 'd')
		return (0);
	else
		printf("rr%c\n",c);
	return (0);
}
