/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:32:00 by hyeykim           #+#    #+#             */
/*   Updated: 2021/03/11 09:32:04 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putstr(va_list *ap, const char *format)
{
	int			cnt;
	const char	*str;
	t_opt		opt;

	str = format;
	cnt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_memset(&opt, 0, sizeof(opt));
			if (!(str = (const char *)printf_argument(&opt, ap, str)))
				return (-1);
			if (!(str = check_type(&opt, str, ap)))
				return (-1);
			cnt += opt.cnt_len;
		}
		else
			cnt += ft_putchar(*str);
		str++;
	}
	return (cnt);
}
