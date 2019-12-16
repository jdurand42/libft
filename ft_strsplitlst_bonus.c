/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:02:29 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 17:03:28 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[i] != 0)
	{
		if (i > 0 && (ft_cmp(s[i], c)) && !(ft_cmp(s[i - 1], c)))
			size++;
		i++;
	}
	if (i > 0 && !(ft_cmp(s[i - 1], c)))
		size++;
	return (size);
}

t_list		*ft_strsplitlst(char const *s, char c)
{
	unsigned int	i;
	unsigned int	st;
	t_list			*list;
	unsigned int	size;

	i = 0;
	list = NULL;
	st = 0;
	size = count_words(s, c);
	while (size--)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		st = i;
		while (s[i] != 0 && s[i] != c)
			i++;
		ft_lstadd_back(&list, ft_lstnew(ft_strndup(&s[st], i - st)));
	}
	return (list);
}
