/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:38:15 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 15:38:22 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*buffer;
	t_list	*revlst;
	t_list	*buffernext;

	buffer = *alst;
	revlst = NULL;
	while (buffer != NULL)
	{
		ft_lstadd_front(&revlst, ft_lstnew(buffer->content));
		buffernext = buffer->next;
		free(buffer);
		buffer = buffernext;
	}
	*alst = revlst;
}
