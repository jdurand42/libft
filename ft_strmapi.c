/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:18:22 by jdurand           #+#    #+#             */
/*   Updated: 2019/10/17 13:30:44 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*b;

	i = 0;
	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	len = ft_strlen(s);
	if (len < 0)
		return (NULL);
	if (!(b = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		b[i] = f(i, s[i]);
		i++;
	}
	b[i] = 0;
	return (b);
}
