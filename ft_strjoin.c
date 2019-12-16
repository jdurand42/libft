/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:50:45 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/09 13:59:41 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat_bonus(char *dest, char const *src, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = len;
	j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t			megasize;
	char			*b;
	size_t			len_1;
	size_t			len_2;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	megasize = len_1 + len_2;
	if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
		return (NULL);
	b[0] = 0;
	ft_strcat_bonus(b, s1, 0);
	ft_strcat_bonus(b, s2, len_1);
	return (b);
}
