/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_isvalid_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:17:14 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 14:38:16 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_isvalid(char *base)
{
	unsigned int i;
	unsigned int j;
	unsigned int base_len;

	i = 0;
	j = 1;
	base_len = ft_strlen(base);
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
