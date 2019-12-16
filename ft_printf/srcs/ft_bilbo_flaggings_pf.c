/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilbo_flaggings_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:19:26 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/07 16:02:42 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	bilbo_flaggings_pf(char *s_flags, t_params *data)
{
	int id;
	int i;

	i = 0;
	data->width = -1;
	data->prec = -1;
	if (s_flags)
	{
		if (s_flags[i] && s_flags[i] == '0')
			data->flags |= (1 << 3);
		while (s_flags[i])
		{
			id = get_id_pf(s_flags[i]);
			if (id != -1)
				data->flags |= (1 << id);
			i++;
		}
	}
	if (data->flags & FLAG_DOT)
		data->prec = 0;
	flags_forrest_pf(s_flags, data);
	if ((data->flags & FLAG_ZERO) && (data->flags & FLAG_MINUS))
		data->flags ^= FLAG_ZERO;
}

int		get_id_pf(char c)
{
	char	*flags_set;
	int		i;

	i = 0;
	flags_set = "-*.";
	while (flags_set[i])
	{
		if (flags_set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	flags_forrest_pf(char *s_flags, t_params *data)
{
	int i;

	i = 0;
	while (s_flags[i] == '0' || s_flags[i] == '-')
		i++;
	parse_width_pf(s_flags, data, &i);
	if (data->flags & FLAG_DOT)
	{
		if (s_flags[i] == '.')
			i++;
		parse_prec_pf(s_flags, data, &i);
	}
}

void	parse_width_pf(char *s_flags, t_params *data, int *i)
{
	while (s_flags[*i] != 0 && s_flags[*i] != '.')
	{
		if (s_flags[*i] == '*')
		{
			data->width = va_arg(data->ap, int);
			if (data->width < 0)
			{
				data->flags |= (1 << 0);
				data->width = -data->width;
			}
			*i += 1;
		}
		else if (ft_isdigit(s_flags[*i]))
		{
			data->width = ft_atoi(&s_flags[*i]);
			while (ft_isdigit(s_flags[*i]))
				*i += 1;
		}
		else
			*i += 1;
	}
}

void	parse_prec_pf(char *s_flags, t_params *data, int *i)
{
	while (s_flags[*i] != 0 && (data->flags & FLAG_DOT))
	{
		if (ft_isdigit(s_flags[*i]))
		{
			data->prec = ft_atoi(&s_flags[*i]);
			while (ft_isdigit(s_flags[*i]))
				*i += 1;
		}
		else if (s_flags[*i] != 0 && s_flags[*i] == '*')
		{
			data->prec = va_arg(data->ap, int);
			*i += 1;
		}
		else
			*i += 1;
	}
}
