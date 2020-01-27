/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:02:29 by jdurand           #+#    #+#             */
/*   Updated: 2020/01/24 12:15:42 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp_set(char c, char *set)
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

static int	count_words(char const *s, char *set)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[i] != 0)
	{
		if (i > 0 && (ft_cmp_set(s[i], set)) && !(ft_cmp_set(s[i - 1], set)))
			size++;
		i++;
	}
	if (i > 0 && !(ft_cmp_set(s[i - 1], set)))
		size++;
	return (size);
}

t_list		*ft_splitlst(char const *s, char *set)
{
	unsigned int	i;
	unsigned int	st;
	t_list			*list;
	unsigned int	size;

	i = 0;
	list = NULL;
	st = 0;
	size = count_words(s, set);
	while (size--)
	{
		while (s[i] != 0 && ft_cmp_set(s[i], set))
			i++;
		st = i;
		while (s[i] != 0 && !ft_cmp_set(s[i], set))
			i++;
		ft_lstadd_back(&list, ft_lstnew(ft_strndup(&s[st], i - st)));
	}
	return (list);
}
