/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:57:01 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/13 02:49:37 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i++;
	}
	if (c == 0)
		return (&temp[i]);
	return (0);
}
