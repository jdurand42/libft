/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:22:46 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 15:23:11 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, unsigned char to_find)
{
	t_list			*buffer;
	unsigned char	*find;

	if (lst == NULL)
		return (NULL);
	buffer = lst;
	while (buffer != NULL)
	{
		find = buffer->content;
		if (*find == to_find)
			return (buffer);
		buffer = buffer->next;
	}
	return (NULL);
}
