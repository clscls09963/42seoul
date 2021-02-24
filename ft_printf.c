/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:11:16 by hyeykim           #+#    #+#             */
/*   Updated: 2021/02/24 17:23:23 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void check_flag(option *opt, const char *str, int *idx)
{
	char *flags;
	char *flag;

	flags = "-0";
	while(str[*idx])
	{
		flag = ft_strchr(flags, str[*idx]);
		
		if (flag == 0)
			return ;
		else if (*flag == '-')
			opt->minus = 1;
		else if (*flag == '0')
			opt->zero = 1;
		(*idx)++;
	}
}

void check_width(option *opt, const char *str, va_list *ap, int *idx)
{
	if (str[*idx])
	{
		if (str[*idx] >= '0' && str[*idx] <= '9')
		{
			opt->width = ft_atoi(&str[*idx]);
			while (str[*idx] >= '0' && str[*idx] <= '9')
				(*idx)++;
		}
		else if (str[*idx] == '*')
		{
			opt->width = va_arg(*ap, int);
			(*idx)++;
		}
	}
}

void check_dot(option *opt, const char *str, va_list *ap, int *idx)
{
	if (str[*idx] == '.')
	{
		(*idx)++;

		if (str[*idx] >= '0' && str[*idx] <= '9')
		{
			opt->dot = ft_atoi(&str[*idx]);
			while (str[*idx] >= '0' && str[*idx] <= '9')
				(*idx)++;	
		}
		else if (str[*idx] == '*')
		{
			opt->dot = va_arg(*ap, int);
			(*idx)++;
		}
	}
}

void check_type(option *opt, const char *str, int *idx)
{
	char c;

	c = str[*idx];

	if (c != 'd' && c != 'i' && c != 'u' && c!= 'x' && c != 'X' && c!= 'c' 
	&& c!= 's' && c != 'p' && c!= '%')
		return ;
	else
		opt->type = c;
}

int printf_argument(option *opt, va_list *ap, const char *str)
{
	int idx;

	idx = 0;
	check_flag(opt, str, &idx);
	check_width(opt, str, ap, &idx);
	check_dot(opt, str, ap, &idx);
	check_type(opt, str, &idx);

	/*printf ("flag '-': %d\n", opt->minus);
	printf ("flag '0': %d\n", opt->zero);
	printf ("width : %d\n", opt->width);
	printf ("dot : %d\n", opt->dot);
	printf ("type : %c\n", opt->type);
	*/
	return (idx);
}

void put_flag(int len, int size, char output)
{
	while (size > len)
	{
		write(1,&output, 1);
		size--;
	}
}

void sign_dec(option *opt, va_list *ap)
{
	int n;

	n = va_arg(*ap, int);

	if (opt->zero == 1 && opt->minus == 0)
		put_flag(ft_strlen(ft_itoa(n)), opt->width, '0');
	ft_putnbr_fd(n, 1);
	if (opt->minus == 1)
		put_flag(ft_strlen(ft_itoa(n)), opt->width, ' ');
}

/*void unsign_dec()
void small_hex()
void large_hex()*/


void printf_value(option *opt, va_list *ap)
{
	char c;

	c = opt->type;
	if (c == 'd' || c == 'i')
		sign_dec(opt, ap);

	/*
	else if(c == 'u')
		unsign_dec();

	else if (c == 'x')
		small_hex();
	else if (c == 'X')
	{
		large_hex();
	}
	*/
}

int putstr(va_list *ap, const char *format)
{
	int	i;
	int	cnt;
	const char *str;
	option  opt;

	str = format;
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_memset(&opt, 0, sizeof(opt));
			i += printf_argument(&opt, ap, &str[i]);
			printf_value(&opt, ap);
			cnt++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int	cnt;

	va_start(ap, format);
	cnt = putstr(&ap, format);
	va_end(ap);
	return (cnt);
}


int main()
{
	int a = 4;
	printf("ft_printf\n"); 
	ft_printf("%05d",a);
	printf("\nprintf\n"); 
	printf("%05d",a);
	return (0);
}