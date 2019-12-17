/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinitialisations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:21:53 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/17 12:56:58 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void		ft_dinit_struct(t_dparams *data, int fd)
{
	data->count = 0;
	data->fd = fd;
	data->i = 0;
	data->j = 0;
}

char		*ft_dstrjoin_free(char const *s1, char const *s2)
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

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int			ft_atoi_pos(char const *str)
{
	int	i;
	int	resultat;

	resultat = 0;
	i = 0;
	while (str[i] != '\0' && (ft_iswhitespace(str[i])))
		i++;
	if ((str[i] != '\0' && str[i] == '-') || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (resultat);
}
