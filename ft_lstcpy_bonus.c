/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:28:19 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/14 19:02:36 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcpy(t_list **dest, t_list *lst)
{
	t_list	*buffer;
	t_list	*bdest;

	if (dest == NULL)
		return ;
	if (lst == NULL)
	{
		*dest = NULL;
		return ;
	}
	buffer = lst;
	bdest = *dest;
	while (buffer != NULL)
	{
		ft_lstadd_back(&bdest, ft_lstnew(buffer->content));
		buffer = buffer->next;
	}
	*dest = bdest;
}
