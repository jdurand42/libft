/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:01:36 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/18 19:00:25 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_cmp_bonus(int c, int c2)
{
	unsigned char	pc;
	unsigned char	pc2;

	pc = (unsigned char)c;
	pc2 = (unsigned char)c2;
	if (pc == pc2)
		return (1);
	else
		return (0);
}

static char		**count_words(char const *s, char c, unsigned int *size)
{
	unsigned int	i;
	char			**tab;

	i = 0;
	*size = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	while (s[i] != 0)
	{
		if (i > 0 && (ft_cmp_bonus(s[i], c)) && !(ft_cmp_bonus(s[i - 1], c)))
			*size += 1;
		i++;
	}
	if (i > 0 && !(ft_cmp_bonus(s[i - 1], c)))
		*size += 1;
	if (!(tab = (char **)malloc((*size + 1) * sizeof(char*))))
		return (NULL);
	tab[*size] = 0;
	return (tab);
}

static char		*ft_strndup_bonus(char const *src, size_t n)
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

static void		free_split(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j--]);
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	st;
	char			**tab;
	unsigned int	size;
	unsigned int	j;

	i = 0;
	j = 0;
	st = 0;
	if (!(tab = count_words(s, c, &size)))
		return (NULL);
	while (j < size)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		st = i;
		while (s[i] != 0 && s[i] != c)
			i++;
		if (!(tab[j++] = ft_strndup_bonus(&s[st], i - st)))
		{
			free_split(tab, j);
			return (NULL);
		}
	}
	return (tab);
}
