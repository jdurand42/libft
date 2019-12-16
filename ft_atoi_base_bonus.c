/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:48:10 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/14 17:55:01 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

int			ft_atoi_base(char const *str, char *base)
{
	int				i;
	int				neg;
	int				resultat;
	int				base_len;

	if (!(base_len = ft_base_isvalid(base)))
		return (0);
	resultat = 0;
	i = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] != '\0' && is_base(str[i], base) != -1)
	{
		resultat = resultat * base_len + is_base(str[i], base);
		i++;
	}
	return (neg * resultat);
}
