/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:53:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 15:53:59 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	pc;

	d = (unsigned char *)dest;
	pc = (unsigned char)c;
	while (n--)
	{
		*d++ = pc;
	}
	return (dest);
}
