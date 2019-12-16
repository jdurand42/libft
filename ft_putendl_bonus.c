/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:59:48 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/17 16:36:30 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *s)
{
	unsigned int i;

	i = 0;
	if (!s)
	{
		ft_putchar('\n');
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}
