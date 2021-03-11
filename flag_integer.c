/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:45:53 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 12:45:54 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flg_blank_inte(t_opt *opt, unsigned long long n, int cnt)
{
	if (opt->dot > cnt)
	{
		put_flag(opt->dot, opt->width, ' ');
		put_flag(cnt, opt->dot, '0');
		ft_putnbr(n, opt->base, opt->alphacase);
		if (opt->width <= opt->dot)
			opt->cnt_len = opt->dot;
		else if (opt->width > opt->dot)
			opt->cnt_len = opt->width;
	}
	else if (opt->dot <= cnt)
	{
		put_flag(cnt, opt->width, ' ');
		ft_putnbr(n, opt->base, opt->alphacase);
		opt->cnt_len = opt->width;
	}
}

void	flg_zero_inte(t_opt *opt, unsigned long long n, int cnt)
{
	if (opt->dot > cnt)
	{
		put_flag(opt->dot, opt->width, ' ');
		put_flag(cnt, opt->dot, '0');
		ft_putnbr(n, opt->base, opt->alphacase);
		if (opt->width <= opt->dot)
			opt->cnt_len = opt->dot;
		else if (opt->width > opt->dot)
			opt->cnt_len = opt->width;
	}
	else if (opt->dot <= cnt)
	{
		put_flag(cnt, opt->width, ' ');
		ft_putnbr(n, opt->base, opt->alphacase);
		opt->cnt_len = opt->width;
	}
}

void	flg_minus_inte(t_opt *opt, unsigned long long n, int cnt)
{
	if (opt->dot > cnt)
	{
		put_flag(cnt, opt->dot, '0');
		ft_putnbr(n, opt->base, opt->alphacase);
		opt->cnt_len = opt->dot;
		if (opt->width <= opt->dot)
			return ;
		else if (opt->width > opt->dot)
		{
			put_flag(opt->dot, opt->width, ' ');
			opt->cnt_len += opt->width - (opt->dot);
		}
	}
	else if (opt->dot <= cnt)
	{
		ft_putnbr(n, opt->base, opt->alphacase);
		put_flag(cnt, opt->width, ' ');
		opt->cnt_len = opt->width;
	}
}
