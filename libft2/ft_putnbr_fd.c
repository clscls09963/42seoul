/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:42:54 by hyeykim           #+#    #+#             */
/*   Updated: 2021/02/25 23:18:10 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		output_select(int idx, char *str)
{
	return (str[idx]);
}

void		ft_putnbr(unsigned int n, int base, int alphacase)
{
	if (n < (unsigned int)base)
	{
		if (base == 10)
			ft_putchar('0' + n);
		else if (alphacase == 1)
			ft_putchar(output_select(n, "0123456789abcdef"));
		else
			ft_putchar(output_select(n, "0123456789ABCDEF"));
	}
	else
	{
		ft_putnbr(n / base, base, alphacase);
		ft_putnbr(n % base, base, alphacase);
	}
}
