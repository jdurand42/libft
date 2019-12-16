/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:17:17 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/30 19:16:29 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base(long nbr, int baselen)
{
	int	nbrlen;

	nbrlen = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		nbrlen++;
	}
	while (nbr >= baselen)
	{
		nbr /= baselen;
		nbrlen = nbrlen + 1;
	}
	return (nbrlen);
}

static int	get_baselen(char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen] != '\0')
		baselen++;
	return (baselen);
}

static int	base_is_valid_itoa(char *base, int baselen)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (baselen < 2)
		return (0);
	while (i < baselen)
	{
		if (!(base[i] >= 33 && base[i] <= 126) ||
				base[i] == '+' || base[i] == '-')
			return (0);
		while (j < baselen)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

char		*ft_itoa_base(long nbr, char *base)
{
	char		*str;
	int			nbrlen;
	int			baselen;

	baselen = get_baselen(base);
	if (!(base_is_valid_itoa(base, baselen)))
		return (0);
	nbrlen = ft_nbrlen_base(nbr, baselen);
	if (!(str = (char*)malloc((nbrlen + 1) * sizeof(char))))
		return (0);
	if (nbr < 0)
		nbr = -nbr;
	str[0] = '-';
	str[nbrlen--] = '\0';
	if (nbr == 0)
		str[nbrlen] = base[0];
	while (nbr)
	{
		str[nbrlen--] = base[nbr % baselen];
		nbr = nbr / baselen;
	}
	return (str);
}
