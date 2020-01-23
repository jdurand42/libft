/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:24:18 by jdurand           #+#    #+#             */
/*   Updated: 2020/01/23 16:37:37 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int		ft_cmp_set(char c, char *set)
{
	unsigned char	pc;
	int				i;

	i = 0;
	pc = (unsigned char)c;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char		**count_words(char const *s, char *set, unsigned int *size)
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
		if (i > 0 && (ft_cmp_set(s[i], set)) && !(ft_cmp_set(s[i - 1], set)))
			*size += 1;
		i++;
	}
	if (i > 0 && !(ft_cmp_set(s[i - 1], set)))
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

char			**ft_split_set(char const *s, char *set)
{
	unsigned int	i;
	unsigned int	st;
	char			**tab;
	unsigned int	size;
	unsigned int	j;

	i = 0;
	j = 0;
	st = 0;
	if (!(tab = count_words(s, set, &size)))
		return (NULL);
	while (j < size)
	{
		while (s[i] != 0 && ft_cmp_set(s[i], set))
			i++;
		st = i;
		while (s[i] != 0 && !ft_cmp_set(s[i], set))
			i++;
		if (!(tab[j++] = ft_strndup_bonus(&s[st], i - st)))
		{
			free_split(tab, j);
			return (NULL);
		}
	}
	return (tab);
}
