/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:26:27 by lbesnard          #+#    #+#             */
/*   Updated: 2022/02/23 22:49:01 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	sab(stack_a);
	sab(stack_b);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	rab(stack_a, 'r');
	rab(stack_b, 'd');
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a, 'r');
	rrab(stack_b, 'd');
	return (0);
}
