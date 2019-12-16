/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:52:19 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:21:12 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *tab, size_t elelen, size_t len)
{
	unsigned char	*t;
	unsigned char	*e;
	int				b;
	size_t			i;

	t = (unsigned char *)tab;
	e = (unsigned char *)tab + (len - elelen);
	i = 0;
	while (i < len / 2)
	{
		b = *t;
		*t = *e;
		*e = b;
		t = t + elelen;
		e = e - elelen;
		i = i + elelen;
	}
}
