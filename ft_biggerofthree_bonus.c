/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggerofthree_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:11:56 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:12:03 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_biggerofthree(int a, int b, int c)
{
	int bigger;

	bigger = a;
	if (bigger < c)
		bigger = c;
	if (bigger < b)
		bigger = b;
	return (bigger);
}
