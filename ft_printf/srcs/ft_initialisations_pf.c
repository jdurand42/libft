/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:21:53 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/07 15:49:35 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_init_struct_pf(t_params *data)
{
	data->count = 0;
	data->i = 0;
	data->j = 0;
}

char		*ft_strjoin_free_pf(char const *s1, char const *s2)
{
	unsigned int	megasize;
	char			*b;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	megasize = ft_strlen(s1) + ft_strlen(s2);
	if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
		return (NULL);
	b[0] = 0;
	ft_strcat(b, s1);
	ft_strcat(b, s2);
	free((char*)s2);
	return (b);
}
