/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:30:59 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/09 18:21:57 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_recursive_factorial(int nb)
{
	int resultat;

	resultat = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (resultat = nb * ft_recursive_factorial(nb - 1));
}
