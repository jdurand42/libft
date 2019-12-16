/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:34:49 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/18 12:35:16 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list *buffer;
	t_list *buffer_next;
	t_list *new;
	t_list *new_ele;

	if (!f || !del)
		return (lst);
	buffer = lst;
	new = NULL;
	while (buffer != NULL)
	{
		buffer_next = buffer->next;
		if (!(new_ele = ft_lstnew(f(buffer->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, new_ele);
		buffer = buffer_next;
	}
	return (new);
}
