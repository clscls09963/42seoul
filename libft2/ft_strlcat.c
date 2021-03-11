/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:57:57 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/13 01:31:47 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	des_len;
	unsigned int	src_len;

	des_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = des_len;
	while ((src[i] != '\0') && i + j + 1 < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (des_len > size)
		return (src_len + size);
	else
		return (des_len + src_len);
}
