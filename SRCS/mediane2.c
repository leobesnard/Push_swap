/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:50:06 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/17 18:53:42 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	med_top2(int first_med, int last_med, t_list **head_a)
{
	if (last_med == -1)
		to_top(head_a, first_med);
	else if (range(head_a, first_med) <= range(head_a, last_med))
		to_top(head_a, first_med);
	else
		to_top(head_a, last_med);
}
