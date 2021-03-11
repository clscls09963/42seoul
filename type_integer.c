/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:45:44 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 12:45:45 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_use_zero_inte(t_opt *opt, unsigned long long n, int cnt)
{
	int wid;

	wid = opt->width;
	if (opt->minus == 0 && opt->zero == 0)
	{
		put_flag(cnt, wid, ' ');
		ft_putnbr(n, opt->base, opt->alphacase);
		opt->cnt_len = wid;
	}
	else if (opt->minus == 0 && opt->zero == 1)
	{
		put_flag(cnt, wid, '0');
		ft_putnbr(n, opt->base, opt->alphacase);
		opt->cnt_len = wid;
	}
	else if (opt->minus == 1)
	{
		ft_putnbr(n, opt->base, opt->alphacase);
		put_flag(cnt, wid, ' ');
		opt->cnt_len = wid;
	}
}

void	width_zero_integer(t_opt *opt, unsigned long long n, int cnt)
{
	int pre;

	pre = opt->dot;
	if (opt->dot_use == 1)
	{
		if (pre > cnt)
		{
			put_flag(cnt, pre, '0');
			ft_putnbr(n, opt->base, opt->alphacase);
			opt->cnt_len = pre;
		}
		else if (pre <= cnt)
		{
			ft_putnbr(n, opt->base, opt->alphacase);
			opt->cnt_len = cnt;
		}
	}
	else if (opt->dot_use == 0)
	{
		ft_putnbr(n, opt->base, opt->alphacase);
		opt->cnt_len = cnt;
	}
}

void	width_integer(t_opt *opt, unsigned long long n, int cnt)
{
	if (opt->minus == 0 && opt->zero == 0)
	{
		if (opt->dot_use == 1)
			flg_blank_inte(opt, n, cnt);
		else if (opt->dot_use == 0)
			dot_use_zero_inte(opt, n, cnt);
	}
	else if (opt->minus == 0 && opt->zero == 1)
	{
		if (opt->dot_use == 1)
			flg_zero_inte(opt, n, cnt);
		else if (opt->dot_use == 0)
			dot_use_zero_inte(opt, n, cnt);
	}
	else if (opt->minus == 1)
	{
		if (opt->dot_use == 1)
			flg_minus_inte(opt, n, cnt);
		else if (opt->dot_use == 0)
			dot_use_zero_inte(opt, n, cnt);
	}
}

int		type_integer(t_opt *opt, va_list *ap, int base, int alphacase)
{
	unsigned int	n;
	int				cnt;

	n = va_arg(*ap, unsigned int);
	cnt = cnt_nbr(n, base == 10 ? 10 : 16);
	opt->base = base;
	opt->alphacase = alphacase;
	if (opt->dot_use == 1 && opt->dot == 0 && n == 0)
	{
		put_flag(0, opt->width, ' ');
		opt->cnt_len = opt->width;
		return (1);
	}
	if (opt->width <= cnt)
		width_zero_integer(opt, n, cnt);
	else if (opt->width > cnt)
		width_integer(opt, n, cnt);
	return (1);
}
