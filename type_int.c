/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:02:41 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 11:02:43 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_use_zero(int sign, t_opt *opt, long long n, int cnt)
{
	int wid;

	wid = opt->width;
	if (opt->minus == 0 && opt->zero == 0)
	{
		put_flag(cnt + sign, wid, ' ');
		if (sign == 1)
			ft_putchar('-');
		ft_putnbr(n, 10, 0);
		opt->cnt_len = wid;
	}
	else if (opt->minus == 0 && opt->zero == 1)
	{
		if (sign == 1)
			ft_putchar('-');
		put_flag(cnt + sign, wid, '0');
		ft_putnbr(n, 10, 0);
		opt->cnt_len = wid;
	}
	else if (opt->minus == 1)
	{
		ft_putnbr(n, 10, 0);
		put_flag(cnt + sign, wid, ' ');
		opt->cnt_len = wid;
	}
}

void	width_zero_int(int sign, t_opt *opt, long long n, int cnt)
{
	int pre;

	pre = opt->dot;
	if (sign == 1)
		ft_putchar('-');
	if (opt->dot_use == 1)
	{
		if (pre > cnt)
		{
			put_flag(cnt, pre, '0');
			ft_putnbr(n, 10, 0);
			opt->cnt_len = pre + sign;
		}
		else if (pre <= cnt)
		{
			ft_putnbr(n, 10, 0);
			opt->cnt_len = cnt + sign;
		}
	}
	else if (opt->dot_use == 0)
	{
		ft_putnbr(n, 10, 0);
		opt->cnt_len = cnt + sign;
	}
}

void	width_int(int sign, t_opt *opt, long long n, int cnt)
{
	if (opt->minus == 0 && opt->zero == 0)
	{
		if (opt->dot_use == 1)
			flg_blank_int(sign, opt, n, cnt);
		else if (opt->dot_use == 0)
			dot_use_zero(sign, opt, n, cnt);
	}
	else if (opt->minus == 0 && opt->zero == 1)
	{
		if (opt->dot_use == 1)
			flg_zero_int(sign, opt, n, cnt);
		else if (opt->dot_use == 0)
			dot_use_zero(sign, opt, n, cnt);
	}
	else if (opt->minus == 1)
	{
		if (sign == 1)
			ft_putchar('-');
		if (opt->dot_use == 1)
			flg_minus_int(sign, opt, n, cnt);
		else if (opt->dot_use == 0)
			dot_use_zero(sign, opt, n, cnt);
	}
}

int		type_int(t_opt *opt, va_list *ap)
{
	long long	n;
	int			sign;

	sign = 0;
	n = va_arg(*ap, int);
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	if (opt->dot_use == 1 && opt->dot == 0 && n == 0)
	{
		put_flag(0, opt->width, ' ');
		opt->cnt_len = opt->width;
		return (1);
	}
	if (opt->width <= cnt_nbr(n, 10) + sign)
		width_zero_int(sign, opt, n, cnt_nbr(n, 10));
	else if (opt->width > cnt_nbr(n, 10) + sign)
		width_int(sign, opt, n, cnt_nbr(n, 10));
	return (1);
}
