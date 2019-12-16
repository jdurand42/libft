/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:19:30 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/16 12:26:46 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*buffer;

	if (alst == NULL)
		return ;
	buffer = *alst;
	if (new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
}
