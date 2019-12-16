/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgoto_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:16 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:20:39 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgoto(t_list *lst, int indice)
{
	int		i;
	t_list	*buffer;

	i = 0;
	if (indice < 0 || lst == NULL)
		return (lst);
	buffer = lst;
	while (i < indice && buffer != NULL)
	{
		buffer = buffer->next;
		i++;
	}
	if (i == indice)
		return (buffer);
	else
		return (lst);
}
