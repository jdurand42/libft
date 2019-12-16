/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:17:05 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:17:12 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islowercase(int c)
{
	unsigned char pc;

	pc = (unsigned char)c;
	if (!(pc >= 'a' && pc <= 'z'))
	{
		return (0);
	}
	return (1);
}
