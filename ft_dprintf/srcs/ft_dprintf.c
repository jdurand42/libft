/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:07:17 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/17 12:56:48 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	dfree_flags(char *s_flags)
{
	if (s_flags)
	{
		free(s_flags);
		s_flags = NULL;
	}
}

void	ddo_forrest(char *s, t_dparams *data, char *s_flags)
{
	dbilbo_flaggings(s_flags, data);
	if (s[data->i] == 'c')
		dprint_char(data);
	else if (s[data->i] == 's')
		dprint_str(data);
	else if (s[data->i] == 'p')
		dprint_void(data);
	else if (s[data->i] == 'd' || s[data->i] == 'i')
		dprint_int(data);
	else if (s[data->i] == 'u')
		dprint_usint(data);
	else if (s[data->i] == 'x')
		dprint_hexa(data);
	else if (s[data->i] == 'X')
		dprint_up_hexa(data);
	else if (s[data->i] == '%')
		dprint_percent(data);
	else if (s[data->i] != 0)
		dprint_random_char(data, s[data->i]);
	dfree_flags(s_flags);
	if (s[data->i] == 0)
		return ;
	data->i += 1;
}

int		dft_isflag(char c)
{
	int		i;
	char	*str;

	str = "-0.*";
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*dget_flags(char *s, t_dparams *data)
{
	char	*s_flags;

	s_flags = NULL;
	data->i += 1;
	data->j = data->i;
	while (dft_isflag(s[data->j]) || ft_isdigit(s[data->j]) ||
	s[data->j] == ' ')
		data->j += 1;
	s_flags = ft_strndup(&s[data->i], data->j - data->i);
	data->i = data->j;
	data->flags = 0;
	return (s_flags);
}

int		ft_dprintf(int fd, const char *str, ...)
{
	char		*s;
	t_dparams	data;

	if (fd < 0)
		return (0);
	ft_dinit_struct(&data, fd);
	va_start(data.ap, str);
	s = (char *)str;
	if (s[data.i] == 0)
		return (0);
	while (s[data.i])
	{
		if (s[data.i] != '%')
		{
			ft_putchar_fd(data.fd, s[(data.i)++]);
			data.count += 1;
		}
		else
			ddo_forrest(s, &data, dget_flags(s, &data));
	}
	va_end(data.ap);
	return (data.count);
}
