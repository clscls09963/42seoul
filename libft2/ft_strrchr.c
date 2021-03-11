/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:59:18 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/13 02:09:19 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char *start;

	start = (char *)s;
	while (*s)
		s++;
	while (s != start && *s != (char)c)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}
