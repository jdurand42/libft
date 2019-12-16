/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:39:52 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:22:18 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strlen_us(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int			base_is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	base_len;

	i = 0;
	j = 1;
	base_len = ft_strlen_us(base);
	if (base_len < 2)
		return (0);
	while (i < base_len)
	{
		if (!(base[i] >= 33 && base[i] <= 126) ||
				base[i] == '+' || base[i] == '-')
			return (0);
		while (j < base_len)
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

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	base_div;
	unsigned int	resultat;

	base_div = 1;
	resultat = 0;
	base_len = ft_strlen_us(base);
	if (base_is_valid(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		while ((nbr / base_div) >= base_len)
			base_div = base_div * base_len;
		while (base_div > 0)
		{
			resultat = (nbr / base_div) % base_len;
			ft_putchar(base[resultat]);
			base_div = base_div / base_len;
		}
	}
		else return ;
}
