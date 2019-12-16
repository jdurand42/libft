/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 01:02:46 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/09 19:50:09 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (!(ft_is_prime(nb)))
	{
		nb++;
	}
	return (nb);
	return (0);
}
