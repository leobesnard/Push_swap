/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/01 11:52:37 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int sort_three(t_stack **head_a)
{
    if (is_sort(head_a))
        return (0);
    else if (maxindex(head_a) == 1 && minindex(head_a) == 2)
        rrab(head_a, 'a');
    else if (maxindex(head_a) == 0 && minindex(head_a) == 1)
        rab(head_a, 'a');
    else if (maxindex(head_a) == 1 && minindex(head_a) == 0)
    {
        rrab(head_a, 'a');
        sab(head_a, 'a');
    }
    else if (maxindex(head_a) == 2 && minindex(head_a) == 1)
        sab(head_a, 'a');
    else if (maxindex(head_a) == 0 && minindex(head_a) == 2)
    {
        sab(head_a, 'a');
        rrab(head_a, 'a');
    }
    return (0);
}

int sort_five(t_stack **head_a, t_stack **head_b)
{
    if (is_sort(head_a))
        return (0);
    else
	{
        while (size(head_a) > 3)
            pab(head_b, head_a, 'b');
        sort_three(head_a);
        sorting(head_a, head_b);
        to_top(head_a, minindex(head_a));
	}
        return (0);
}

int sorting_small(t_stack **head_a, t_stack **head_b)
{
    if (size(head_a) == 2)
        if (!is_sort(head_a))
            sab(head_a, 'a');
    if (size(head_a) == 3)
        sort_three(head_a);
    if (size(head_a) < 6 && size(head_a) > 3)
        sort_five(head_a, head_b);
    return (0);
}

