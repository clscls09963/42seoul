/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:20:59 by hyeykim           #+#    #+#             */
/*   Updated: 2021/02/25 20:25:44 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct	s_opt
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			dot_use;
	int			alphacase;
	int			base;
	int			cnt_len;
}				t_opt;

int			ft_printf(const char *format, ...);

int			putstr(va_list *ap, const char *format);

char		*printf_argument(t_opt *opt, va_list *ap, const char *str);

const char	*check_type(t_opt *opt, const char *str, va_list *ap);

int			type_percent(t_opt *opt);

int			type_point(t_opt *opt, va_list *ap);

void		ft_putptr(unsigned long long n);

int			type_str(t_opt *opt, va_list *ap);

int			type_char(t_opt *opt, va_list *ap);

int			type_integer(t_opt *opt, va_list *ap, int base, int alphacase);

int			type_int(t_opt *opt, va_list *ap);

int			cnt_nbr(unsigned long long n, int base);

void		put_flag(int len, int size, char output);

char		*check_dot(t_opt *opt, const char *str, va_list *ap);

char		*check_width(t_opt *opt, const char *str, va_list *ap);

int			number(va_list *ap, char **str);

char		*check_flag(t_opt *opt, const char *str);

void		flg_blank_int(int sign, t_opt *opt, long long n, int cnt);

void		flg_zero_int(int sign, t_opt *opt, long long n, int cnt);

void		flg_minus_int(int sign, t_opt *opt, long long n, int cnt);

void		dot_use_zero(int sign, t_opt *opt, long long n, int cnt);

void		width_zero_int(int sign, t_opt *opt, long long n, int cnt);

void		width_int(int sign, t_opt *opt, long long n, int cnt);

void		flg_blank_inte(t_opt *opt, unsigned long long n, int cnt);

void		flg_zero_inte(t_opt *opt, unsigned long long n, int cnt);

void		flg_minus_inte(t_opt *opt, unsigned long long n, int cnt);

void		dot_use_zero_inte(t_opt *opt, unsigned long long n, int cnt);

void		width_zero_integer(t_opt *opt, unsigned long long n, int cnt);

void		width_integer(t_opt *opt, unsigned long long n, int cnt);

#endif
