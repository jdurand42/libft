/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:47:31 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/11 17:50:53 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *buffer;

	buffer = lst;
	if (buffer == NULL)
		return (NULL);
	while (buffer->next != NULL)
		buffer = buffer->next;
	return (buffer);
}
