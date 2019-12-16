/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:59:25 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/13 16:59:51 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	needlelen;

	if (*needle == 0)
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	while (*haystack != 0 && n-- >= needlelen)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, needlelen) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
