/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 03:32:34 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/15 19:16:41 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == 0)
		return ((void *)0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) <= start)
	{
		if (!(str = (char *)malloc(sizeof(char) * 1)))
			return ((void *)0);
		str[0] = 0;
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return ((void *)0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
