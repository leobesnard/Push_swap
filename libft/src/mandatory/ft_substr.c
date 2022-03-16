/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:33:45 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/16 18:56:19 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *str, int start, size_t len)
{
	size_t	sublen;
	char	*ret;

	if (!str)
		return (NULL);
	if (start > (int)ft_strlen(str))
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	sublen = ft_strlen(str + start);
	if (sublen > len)
		sublen = len;
	ret = malloc(sizeof(*ret) * (sublen + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str + start, sublen + 1);
	return (ret);
}
