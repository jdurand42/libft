/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:00:51 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:01:08 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			pc;
	unsigned int	len;

	pc = (char)c;
	str = (char *)s;
	len = ft_strlen(s);
	while (len && str[len] != pc)
		len--;
	if (str[len] == pc)
		return (&str[len]);
	else
		return (NULL);
}
