/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:20:59 by hyeykim           #+#    #+#             */
/*   Updated: 2021/02/24 15:17:26 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct Option
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	char	type;
}			option;


#endif