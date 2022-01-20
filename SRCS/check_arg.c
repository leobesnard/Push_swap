/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:39:31 by lbesnard          #+#    #+#             */
/*   Updated: 2022/01/20 19:27:07 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		if (argv[i][0] == '-' && !argv[i][1])
			return (1);
		if (argv[i][0] == '-' && argv[i][1])
			i++;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) <= INT_MIN || ft_atoi(argv[i]) >= INT_MAX)
				return (1);
		j = 0;
		i++;
	}
	return(0);
}

int	check_error(int argc, char **argv)
{
	if (check_arg(argc, argv))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	return (0);
}
