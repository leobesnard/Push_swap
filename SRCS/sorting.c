/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:15:52 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/21 19:50:08 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	size(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	sort(t_stack **head_a, t_stack **head_b)
{
	int		index;
	int		stacksize;
	int		chunkmax;
	int		chunkmin;

	chunkmin = find_min(*head_a);
	chunkmax = chunkmin + 19;
	while (*head_a)
	{
		while ((scantop(*head_a, chunkmin, chunkmax) >= 0))
		{
			stacksize = size(*head_a);
			index = scantop(*head_a, chunkmin, chunkmax);
			totop(head_a, index, stacksize);
			pab(head_b, head_a);
			printf("pb\n");
			//print_stack(*head_a, 'a');
		}
		chunkmin += 20;
		chunkmax += 20;
	}
	while (*head_b)
	{
		stacksize = size(*head_b);
		index = find_max(*head_b);
		totop(head_b, index, stacksize);
		pab(head_a, head_b);
		printf("pa\n");
	}
	return (0);
}
