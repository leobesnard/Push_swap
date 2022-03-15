/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:08:50 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/15 22:35:33 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

int	swap(int *a, int *b);
int	ft_sab(t_list **head);
int	ft_pab(t_list **head_to,t_list **head_from);
int	ft_rab(t_list **head);
int	ft_rrab(t_list **head);
int	ft_ss(t_list **stack_a, t_list **stack_b);
int	ft_rr(t_list **stack_a, t_list **stack_b);
int	ft_rrr(t_list **stack_a, t_list **stack_b);
int	check_double(t_list *head);
int	is_sort(t_list **head);

#endif
