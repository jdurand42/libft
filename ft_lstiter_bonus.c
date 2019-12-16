/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:34:04 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/14 19:03:38 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*buffer;

	if (lst == NULL || !(*f))
		return ;
	buffer = lst;
	while (buffer != NULL)
	{
		f(buffer->content);
		buffer = buffer->next;
	}
}
