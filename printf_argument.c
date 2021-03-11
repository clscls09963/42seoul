/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:45:04 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 09:45:06 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flag(t_opt *opt, const char *str)
{
	char	*flags;
	char	*flag;
	char	*tmp;

	tmp = (char *)str;
	flags = "-0";
	while (tmp && ((flag = ft_strchr(flags, *tmp)) != 0))
	{
		if (flag == 0)
			return (0);
		else if (*flag == '-')
			opt->minus = 1;
		else if (*flag == '0')
			opt->zero = 1;
		tmp++;
	}
	if (tmp == 0)
		return (0);
	return (tmp);
}

int		number(va_list *ap, char **str)
{
	int		len;

	len = 0;
	if (**str && ('0' <= **str && **str <= '9'))
	{
		while ('0' <= **str && **str <= '9')
		{
			if (len > 2147483646)
				return (0);
			len = len * 10 + ((**str) - '0');
			if (!(++(*str)))
				return (0);
		}
	}
	else if (*str && **str == '*' && len == 0)
	{
		(*str)++;
		if ((len = va_arg(*ap, int)) > 2147483646)
			return (0);
	}
	return (len);
}

char	*check_width(t_opt *opt, const char *str, va_list *ap)
{
	char	*tmp;
	int		cnt;

	tmp = (char *)str;
	cnt = 0;
	cnt = number(ap, &tmp);
	if (cnt < 0)
	{
		opt->minus = 1;
		cnt *= -1;
	}
	opt->width = cnt;
	return (tmp);
}

char	*check_dot(t_opt *opt, const char *str, va_list *ap)
{
	char	*tmp;
	int		cnt;

	tmp = (char *)str;
	cnt = 0;
	opt->dot = 1;
	if (*tmp == '.')
	{
		opt->dot_use = 1;
		tmp++;
		if (tmp && *tmp == '-')
		{
			opt->dot = -1;
			tmp++;
			opt->dot_use = 0;
		}
		cnt = number(ap, &tmp);
	}
	if (cnt < 0)
	{
		opt->dot_use = 0;
		cnt *= -1;
	}
	opt->dot *= cnt;
	return (tmp);
}

char	*printf_argument(t_opt *opt, va_list *ap, const char *str)
{
	char	*tmp;

	if (!ap || !str)
		return (0);
	tmp = (char *)str;
	if ((tmp = check_flag(opt, tmp)) == 0)
		return (0);
	if ((tmp = check_width(opt, tmp, ap)) == 0)
		return (0);
	if ((tmp = check_dot(opt, tmp, ap)) == 0)
		return (0);
	return (tmp);
}
