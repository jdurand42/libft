/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:05:48 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:06:26 by jdurand          ###   ########.fr       */
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

static char	*ft_count(char const *s, char const *set)
{
	int		i;
	int		char_nb;
	char	*b;

	i = 0;
	char_nb = 0;
	while (s[i] != 0)
	{
		if (!ft_charisset(s[i], set))
			char_nb++;
		i++;
	}
	if (!(b = (char *)malloc((char_nb + 1) * sizeof(char))))
		return (0);
	return (b);
}

char		*ft_strtrim_all(char const *s, char const *set)
{
	unsigned int	j;
	unsigned int	i;
	char			*b;

	i = 0;
	j = 0;
	if (!(b = ft_count(s, set)))
		return (0);
	while (s[i] != 0)
	{
		if (!ft_charisset(s[i], set))
		{
			b[j] = s[i];
			j++;
			i++;
		}
		else
			i++;
	}
	b[j] = 0;
	return (b);
}
