/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_us_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:03:42 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/30 21:07:00 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_bonus(long int nbr)
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

char		*ft_itoa_us(unsigned int n)
{
	int		nbrlen;
	char	*str;
	long	n2;

	n2 = (long)n;
	nbrlen = ft_nbrlen_bonus(n2);
	if (n < 0)
	{
		n2 = -n2;
		nbrlen++;
	}
	if (!(str = (char*)malloc((nbrlen + 1) * sizeof(char))))
		return (0);
	str[0] = '-';
	str[nbrlen--] = '\0';
	if (n2 == 0)
		str[nbrlen--] = '0';
	while (n2)
	{
		str[nbrlen--] = n2 % 10 + '0';
		n2 = n2 / 10;
	}
	return (str);
}
