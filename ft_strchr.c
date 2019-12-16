/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:35:28 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/19 14:50:09 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			pc;
	char			*str;

	str = (char *)s;
	i = 0;
	pc = (char)c;
	while (str[i] != 0)
	{
		if (str[i] == pc)
			return (&str[i]);
		i++;
	}
	if (str[i] == 0 && pc == 0)
		return (&str[i]);
	else
		return (NULL);
}
