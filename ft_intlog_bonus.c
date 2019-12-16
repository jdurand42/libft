/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlog_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:21:49 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 14:43:17 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlog(long int x, long int base)
{
	long int	log;
	long int	res;

	res = 1;
	log = 0;
	if (x > 0 && base > 1)
	{
		while (res < x)
		{
			res = res * base;
			log++;
		}
		if (res == x)
			return (log);
		else if (res > x)
			return (log - 1);
	}
	return (0);
}
