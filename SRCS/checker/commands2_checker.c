/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:43:01 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/17 12:35:47 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return (0);
	ft_sab(stack_a);
	ft_sab(stack_b);
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return (0);
	ft_rab(stack_a);
	ft_rab(stack_b);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return (0);
	ft_rrab(stack_a);
	ft_rrab(stack_b);
	return (0);
}
