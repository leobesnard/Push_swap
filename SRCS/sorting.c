/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:15:52 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/24 17:35:39 by lbesnard         ###   ########.fr       */
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
	int		max;

	chunkmin = min(*head_a);
	chunkmax = chunkmin + 19;
	max = ft_max(*head_a);
	while (*head_a && chunkmin <= max)
	{
		while ((scantop(*head_a, chunkmin, chunkmax) >= 0))
		{
			stacksize = size(*head_a);
			index = scantop(*head_a, chunkmin, chunkmax);
			totop(head_a, index, stacksize, 'a');
			pab(head_b, head_a);
			printf("pb\n");
		}
		chunkmin += 20;
		chunkmax += 20;
	}
	while (*head_b)
	{
		stacksize = size(*head_b);
		index = find_max(*head_b);
		totop(head_b, index, stacksize, 'b');
		pab(head_a, head_b);
		printf("pa\n");
	}
	return (0);
}
