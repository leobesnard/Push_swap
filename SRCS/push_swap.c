/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:10:25 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/18 21:41:07 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_error(argc, argv);
	stack_a = init_stack_a(argc, argv);
	stack_b = init_stack_b(argc);
	if ((!stack_a) || (!stack_b))
		return (0);
	
}
