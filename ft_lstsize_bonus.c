/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:57 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/14 19:04:52 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*buffer;
	int		size;

	size = 0;
	if (lst == NULL)
		return (0);
	buffer = lst;
	while (buffer != NULL)
	{
		buffer = buffer->next;
		size++;
	}
	return (size);
}
