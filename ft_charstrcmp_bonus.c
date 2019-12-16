/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstrcmp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:59:38 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/25 11:05:32 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charstrcmp(const char c, const void *s2)
{
	unsigned char	pc;
	unsigned char	*str2;

	pc = (unsigned char)c;
	str2 = (unsigned char *)s2;
	while (*str2 != 0)
	{
		if (pc != *str2)
			return (pc - *str2);
		str2++;
	}
	return (0);
}
