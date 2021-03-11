/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:11:02 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/15 17:24:14 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*ptr;
	t_list		*temp;

	if (lst == 0 || del == 0)
		return ;
	temp = *lst;
	while (temp != 0)
	{
		ptr = temp->next;
		ft_lstdelone(temp, del);
		temp = ptr;
	}
	*lst = 0;
}
