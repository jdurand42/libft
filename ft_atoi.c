/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:52:11 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/31 11:08:03 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int			ft_atoi(char const *str)
{
	int	i;
	int	neg;
	int	resultat;

	resultat = 0;
	i = 0;
	neg = 1;
	while (str[i] != '\0' && (ft_iswhitespace(str[i])))
		i++;
	if ((str[i] != '\0' && str[i] == '-') || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (neg * resultat);
}
