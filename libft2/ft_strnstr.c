/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:58:20 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/13 03:11:48 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *c, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*find;

	find = (char *)c;
	i = 0;
	if (needle[i] == 0)
		return (find);
	while (find[i] && i < len)
	{
		j = 0;
		while (find[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return (&find[i]);
			j++;
		}
		i++;
	}
	return (0);
}
