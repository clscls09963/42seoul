/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:18:51 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 12:18:52 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flg_blank_int(int sign, t_opt *opt, long long n, int cnt)
{
	if (opt->dot > cnt)
	{
		put_flag(opt->dot + sign, opt->width, ' ');
		if (sign == 1)
			ft_putchar('-');
		put_flag(cnt, opt->dot, '0');
		ft_putnbr(n, 10, 0);
		if (opt->width <= opt->dot + sign)
			opt->cnt_len = opt->dot + sign;
		else if (opt->width > opt->dot + sign)
			opt->cnt_len = opt->width;
	}
	else if (opt->dot <= cnt)
	{
		put_flag(cnt + sign, opt->width, ' ');
		if (sign == 1)
			ft_putchar('-');
		ft_putnbr(n, 10, 0);
		opt->cnt_len = opt->width;
	}
}

void	flg_zero_int(int sign, t_opt *opt, long long n, int cnt)
{
	if (opt->dot > cnt)
	{
		put_flag(opt->dot + sign, opt->width, ' ');
		if (sign == 1)
			ft_putchar('-');
		put_flag(cnt, opt->dot, '0');
		ft_putnbr(n, 10, 0);
		if (opt->width <= opt->dot + sign)
			opt->cnt_len = opt->dot + sign;
		else if (opt->width > opt->dot + sign)
			opt->cnt_len = opt->width;
	}
	else if (opt->dot <= cnt)
	{
		put_flag(cnt + sign, opt->width, ' ');
		if (sign == 1)
			ft_putchar('-');
		ft_putnbr(n, 10, 0);
		opt->cnt_len = opt->width;
	}
}

void	flg_minus_int(int sign, t_opt *opt, long long n, int cnt)
{
	if (opt->dot > cnt)
	{
		put_flag(cnt, opt->dot, '0');
		ft_putnbr(n, 10, 0);
		opt->cnt_len = opt->dot + sign;
		if (opt->width <= opt->dot + sign)
			return ;
		else if (opt->width > opt->dot + sign)
		{
			put_flag(opt->dot + sign, opt->width, ' ');
			opt->cnt_len += opt->width - (opt->dot + sign);
		}
	}
	else if (opt->dot <= cnt)
	{
		ft_putnbr(n, 10, 0);
		put_flag(cnt + sign, opt->width, ' ');
		opt->cnt_len = opt->width;
	}
}

int		cnt_nbr(unsigned long long n, int base)
{
	int cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}
