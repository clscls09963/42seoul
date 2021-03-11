/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:32:21 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/13 22:46:48 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*minnum(void)
{
	const char		*temp;
	char			*num;
	int				i;

	i = 0;
	temp = "-2147483648";
	num = (char *)malloc(12);
	if (num == 0)
		return (0);
	while (i < 12)
	{
		num[i] = temp[i];
		i++;
	}
	return (num);
}

char		*innbr(int n, int minus)
{
	int		i;
	int		j;
	char	temp[11];
	char	*num;

	i = 11;
	while (--i >= 0)
	{
		temp[i] = n % 10 + '0';
		n /= 10;
		if (n == 0)
		{
			if (minus)
				temp[--i] = '-';
			num = (char *)malloc(12 - i);
			if (num == 0)
				return (0);
			j = -1;
			while (++j < 11 - i)
				num[j] = temp[i + j];
			num[j] = 0;
			return (num);
		}
	}
	return (0);
}

char		*ft_itoa(int n)
{
	int		minus;

	minus = 0;
	if (n == -2147483648)
		return (minnum());
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	return (innbr(n, minus));
}
