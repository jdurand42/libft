/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:27:19 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/10 18:20:50 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer;
	t_list	*buffernext;

	if (!(*del))
		return ;
	if (lst == NULL)
		return ;
	buffer = *lst;
	while (buffer != NULL)
	{
		buffernext = buffer->next;
		del(buffer->content);
		free(buffer);
		buffer = buffernext;
	}
	*lst = NULL;
}
