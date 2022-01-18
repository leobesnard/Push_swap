/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:44:59 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/18 21:34:57 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "limits.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int content);
t_stack	*init_stack_a(int argc, char **argv);
t_stack	*init_stack_b(int argc);
int		check_arg(int argc, char **argv);
void	check_error(int argc, char **argv);

#endif
