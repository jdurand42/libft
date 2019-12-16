/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:07:35 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/18 19:49:29 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(b = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (s)
		if (start < ft_strlen(s))
			while (s[start] != 0 && i < len)
				b[i++] = s[start++];
	b[i] = 0;
	return (b);
}
