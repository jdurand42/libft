/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:04:28 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/18 12:23:38 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charisset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strndup_bonus(char const *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (src[i] != '\0' && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

char		*ft_strtrim(char const *s, char const *set)
{
	unsigned int	j;
	unsigned int	i;
	char			*b;

	j = 0;
	if (!s)
		return (NULL);
	if (!set)
		return (ft_strndup_bonus(s, ft_strlen(s)));
	while (s[j] != 0 && ft_charisset(s[j], set))
		j++;
	i = j;
	while (s[i] != 0)
		i++;
	if (i != 0)
		if (j != (i -= 1))
			while (i >= j && ft_charisset(s[i], set))
				i--;
	if (!(b = ft_strndup_bonus(&s[j], i - j + 1)))
		return (NULL);
	if (j == i)
		return (b);
	return (b);
}
