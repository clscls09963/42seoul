/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeykim <hyeykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:31:53 by hyeykim           #+#    #+#             */
/*   Updated: 2021/01/15 18:14:29 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*temp;
	t_list		*new;
	t_list		*head;

	if (lst == 0 || f == 0)
		return (0);
	if (!(head = ft_lstnew(f(lst->content))))
		return (0);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		temp->next = new;
		temp = new;
		lst = lst->next;
	}
	return (head);
}
