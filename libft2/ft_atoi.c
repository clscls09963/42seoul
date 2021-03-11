/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:06:01 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/13 04:06:51 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			minus;
	long long	num;

	minus = 1;
	num = 0;
	while (*str >= 9 & *str <= 13 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = ((num * 10) + (*str - '0') * minus);
		if (minus == 1 && num < 0)
			return (-1);
		else if (minus == -1 && num > 0)
			return (0);
		str++;
	}
	return (num);
}
