/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:42:09 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/24 16:19:32 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	pc;

	ps = (unsigned char *)s;
	pc = (unsigned char)c;
	while (n--)
	{
		if (*ps == pc)
			return (ps);
		ps++;
	}
	return (NULL);
}
