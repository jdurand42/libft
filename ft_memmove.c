/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:46:18 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/14 17:57:45 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*end_s;
	char	*end_d;

	d = (char *)dest;
	s = (char *)src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		end_s = s + (len - 1);
		end_d = d + (len - 1);
		while (len--)
			*end_d-- = *end_s--;
	}
	return (dest);
}
