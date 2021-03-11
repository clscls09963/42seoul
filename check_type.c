/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:35 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 10:48:37 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_flag(int len, int size, char output)
{
	while (size > len)
	{
		write(1, &output, 1);
		size--;
	}
}

void		ft_putptr(unsigned long long n)
{
	if (n < 16)
	{
		ft_putchar(output_select(n, "0123456789abcdef"));
	}
	else
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
}

void		width_point(int cnt, int wid, unsigned long long n, t_opt *opt)
{
	if (opt->minus == 0)
	{
		put_flag(cnt, wid, ' ');
		ft_putstr_fd("0x", 1, 2);
		ft_putptr(n);
	}
	else if (opt->minus == 1)
	{
		ft_putstr_fd("0x", 1, 2);
		ft_putptr(n);
		put_flag(cnt, wid, ' ');
	}
	opt->cnt_len = wid;
}

int			type_point(t_opt *opt, va_list *ap)
{
	unsigned long long	n;
	int					cnt;
	int					wid;

	n = va_arg(*ap, unsigned long long);
	cnt = cnt_nbr(n, 16) + 2;
	wid = opt->width;
	if (wid <= cnt)
	{
		ft_putstr_fd("0x", 1, 2);
		ft_putptr(n);
		opt->cnt_len = cnt;
		return (1);
	}
	else if (wid > cnt)
	{
		width_point(cnt, wid, n, opt);
		return (1);
	}
	return (0);
}

const char	*check_type(t_opt *opt, const char *str, va_list *ap)
{
	int check;

	check = 0;
	if (*str == 'd' || *str == 'i')
		check = type_int(opt, ap);
	else if (*str == 'u')
		check = type_integer(opt, ap, 10, 0);
	else if (*str == 'x')
		check = type_integer(opt, ap, 16, 1);
	else if (*str == 'X')
		check = type_integer(opt, ap, 16, 0);
	else if (*str == 'c')
		check = type_char(opt, ap);
	else if (*str == 's')
		check = type_str(opt, ap);
	else if (*str == 'p')
		check = type_point(opt, ap);
	else if (*str == '%')
		check = type_percent(opt);
	else
		return (0);
	if (!check)
		return (0);
	return (str);
}
