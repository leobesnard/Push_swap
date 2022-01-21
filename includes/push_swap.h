/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:44:59 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/21 19:49:34 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int content);
t_stack	*init_stack_a(int argc, char **argv);
t_stack	*init_stack_b(void);
int		check_arg(int argc, char **argv);
int	check_error(int argc, char **argv);
int	ft_swap(int *a, int *b);
int	sab(t_stack **head);
int	pab(t_stack **head_to,t_stack **head_from);
int	rab(t_stack **head);
int	rrab(t_stack **head);
int	ss(t_stack **stack_a, t_stack **stack_b);
int	rr(t_stack **stack_a, t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);
int	ft_atoi(const char *nptr);
int	totop(t_stack **head, int index, int nb);
int	find_min(t_stack *head);
int	sort(t_stack **head_a, t_stack **head_b);
int	print_stack(t_stack *head, char c);
int	scantop(t_stack *head, int chunkmin, int chunkmax);
int	find_max(t_stack *head);

#endif
