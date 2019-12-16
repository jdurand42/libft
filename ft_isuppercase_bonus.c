/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:56:07 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/14 19:06:05 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isuppercase(int c)
{
	unsigned char pc;

	pc = (unsigned char)c;
	if (!(pc >= 'A' && pc <= 'Z'))
	{
		return (0);
	}
	return (1);
}
