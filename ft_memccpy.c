/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:41:01 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/16 19:04:44 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		pc;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	pc = (unsigned char)c;
	while (n-- && *s != pc)
	{
		*d++ = *s++;
	}
	if (*s == pc && pc)
	{
		*d = pc;
		return (++d);
	}
	else
		return (NULL);
}
