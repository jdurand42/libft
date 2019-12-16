/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:07:17 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/07 16:02:10 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	free_flags_pf(char *s_flags)
{
	if (s_flags)
	{
		free(s_flags);
		s_flags = NULL;
	}
}

void	do_forrest_pf(char *s, t_params *data, char *s_flags)
{
	bilbo_flaggings_pf(s_flags, data);
	if (s[data->i] == 'c')
		print_char_pf(data);
	else if (s[data->i] == 's')
		print_str_pf(data);
	else if (s[data->i] == 'p')
		print_void_pf(data);
	else if (s[data->i] == 'd' || s[data->i] == 'i')
		print_int_pf(data);
	else if (s[data->i] == 'u')
		print_usint_pf(data);
	else if (s[data->i] == 'x')
		print_hexa_pf(data);
	else if (s[data->i] == 'X')
		print_up_hexa_pf(data);
	else if (s[data->i] == '%')
		print_percent_pf(data);
	else if (s[data->i] != 0)
		print_random_char_pf(data, s[data->i]);
	free_flags_pf(s_flags);
	if (s[data->i] == 0)
		return ;
	data->i += 1;
}

int		ft_isflag_pf(char c)
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

char	*get_flags_pf(char *s, t_params *data)
{
	char	*s_flags;

	s_flags = NULL;
	data->i += 1;
	data->j = data->i;
	while (ft_isflag_pf(s[data->j]) || ft_isdigit(s[data->j]) ||
	s[data->j] == ' ')
		data->j += 1;
	s_flags = ft_strndup(&s[data->i], data->j - data->i);
	data->i = data->j;
	data->flags = 0;
	return (s_flags);
}

int		ft_printf(const char *str, ...)
{
	char		*s;
	t_params	data;

	ft_init_struct_pf(&data);
	va_start(data.ap, str);
	s = (char *)str;
	if (s[data.i] == 0)
		return (0);
	while (s[data.i])
	{
		if (s[data.i] != '%')
		{
			ft_putchar(s[(data.i)++]);
			data.count += 1;
		}
		else
			do_forrest_pf(s, &data, get_flags_pf(s, &data));
	}
	va_end(data.ap);
	return (data.count);
}
