/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:13:22 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:13:34 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmp(int c, int c2)
{
	unsigned char	pc;
	unsigned char	pc2;

	pc = (unsigned char)c;
	pc2 = (unsigned char)c2;
	if (pc == pc2)
		return (1);
	else
		return (0);
}
