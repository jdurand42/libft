/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:04 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/17 14:44:47 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b)
{
	unsigned char	buffer;
	unsigned char	*pa;
	unsigned char	*pb;

	pa = (unsigned char *)a;
	pb = (unsigned char *)b;
	buffer = *pb;
	*pb = *pa;
	*pa = buffer;
}
