/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:59:48 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/18 12:10:02 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
