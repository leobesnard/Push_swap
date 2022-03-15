/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:44:59 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/15 17:46:52 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_op
{
	int	ra;
	int	rb; 
	int	rra;
	int	rrb;
}	t_op;

t_list	*ft_listnew(int content);
t_list	*init_list_a(int argc, char **argv);
t_list	*init_list_b(void);
int		check_arg(int argc, char **argv);
int	check_error(int argc, char **argv);
int	ft_swap(int *a, int *b);
int	sab(t_list **head, char c);
int	pab(t_list **head_to,t_list **head_from, char c);
int	rab(t_list **head, char c);
int	rrab(t_list **head, char c);
int	ss(t_list **stack_a, t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);
int	ft_atoi(const char *nptr);
int	totop(t_list **head, t_list**head_b, int index, int nb, char c, int chunkmax);
int	find_min(t_list *head);
int	sort(t_list **head_a, t_list **head_b);
int	print_list(t_list *head, char c);
int	scantop(t_list *head, int chunkmin, int chunkmax);
int	find_max(t_list *head);
int	min(t_list *head);
int	ft_max(t_list *head);
int	size(t_list **head);
int	scanbot(t_list *head, int chunkmin, int chunkmax);
int	tototop(t_list **head_a, int index, int nb, char c);
int	comp(t_list *head);
int	find_sup(int value, t_list **head);
int	maxindex(t_list **head);
int	minindex(t_list **head);
int	get_value(int index, t_list **head);
int	find_lowcost(t_list **head_a, t_list **head_b);
void	ft_lstaddd_back(t_list **alst, t_list *new);
int	find_sup(int value, t_list **head);
int	numop(t_list **head_a, t_list **head_b, int index, t_op *op);
void	execop(t_list **head_a, t_list **head_b, t_op *op);
int	find_med(t_list **head);
int	range(t_list **head_a, int index);
int	is_sort(t_list **head);
int	push_med(t_list **head_a, t_list **head_b);
int	sorting(t_list **head_a, t_list **head_b);
int	to_top(t_list **head, int index);
int sort_five(t_list **head_a, t_list **head_b);
int sort_three(t_list **head_a);
int sorting_small(t_list **head_a, t_list **head_b);

#endif
