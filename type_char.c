/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:57:30 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 10:57:32 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_char(t_opt *opt, va_list *ap)
{
	if (opt->width > 1)
	{
		if (opt->minus == 0)
		{
			put_flag(1, opt->width, ' ');
			ft_putchar(va_arg(*ap, int));
		}
		else if (opt->minus == 1)
		{
			ft_putchar(va_arg(*ap, int));
			put_flag(1, opt->width, ' ');
		}
		opt->cnt_len = opt->width;
		return (1);
	}
	ft_putchar(va_arg(*ap, int));
	opt->cnt_len = 1;
	return (1);
}

int	type_str(t_opt *opt, va_list *ap)
{
	char	*str;
	int		len;
	int		wid;

	wid = opt->width;
	if ((str = va_arg(*ap, char *)) == NULL)
		str = "(null)";
	len = ft_strlen(str);
	opt->cnt_len = 0;
	if (opt->dot < len && opt->dot_use == 1)
		len = opt->dot;
	if (wid > len)
	{
		if (opt->minus == 0 && opt->zero == 1)
			put_flag(len, wid, '0');
		else if (opt->minus == 0 && opt->zero == 0)
			put_flag(len, wid, ' ');
		opt->cnt_len += wid - len;
	}
	ft_putstr_fd(str, 1, len);
	opt->cnt_len += len;
	if (opt->minus == 1)
		put_flag(len, wid, ' ');
	return (1);
}

int	type_percent(t_opt *opt)
{
	if (opt->width > 1)
	{
		if (opt->minus == 0 && opt->zero == 0)
		{
			put_flag(1, opt->width, ' ');
			ft_putchar('%');
		}
		else if (opt->minus == 0 && opt->zero == 1)
		{
			put_flag(1, opt->width, '0');
			ft_putchar('%');
		}
		else if (opt->minus == 1)
		{
			ft_putchar('%');
			put_flag(1, opt->width, ' ');
		}
		opt->cnt_len = opt->width;
		return (1);
	}
	ft_putchar('%');
	opt->cnt_len = 1;
	return (1);
}
