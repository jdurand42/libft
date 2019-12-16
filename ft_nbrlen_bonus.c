/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:17:32 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 15:58:15 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long int nbr)
{
	int	nbrlen;

	nbrlen = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 10)
	{
		nbr /= 10;
		nbrlen = nbrlen + 1;
	}
	return (nbrlen);
}
