/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallerofthree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:01 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/09 18:22:01 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_smallerofthree(int a, int b, int c)
{
	int smaller;

	smaller = a;
	if (smaller > c)
		smaller = c;
	if (smaller > b)
		smaller = b;
	return (smaller);
}
