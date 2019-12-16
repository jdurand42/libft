/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:52:01 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/07 15:53:09 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	print_char_pf(t_params *data)
{
	char c;
	char pc[2];

	c = va_arg(data->ap, int);
	pc[0] = c;
	pc[1] = 0;
	data->prec = -1;
	put_forrest_pf(pc, data);
}

void	print_percent_pf(t_params *data)
{
	char c;
	char pc[2];

	c = '%';
	pc[0] = c;
	pc[1] = 0;
	data->prec = -1;
	put_forrest_pf(pc, data);
}

void	print_random_char_pf(t_params *data, char c)
{
	char pc[2];

	pc[0] = c;
	pc[1] = 0;
	data->prec = -1;
	put_forrest_pf(pc, data);
}

void	print_str_pf(t_params *data)
{
	char *s_arg;

	s_arg = va_arg(data->ap, char*);
	if (!s_arg)
		s_arg = ("(null)");
	data->flags |= FLAG_STR;
	put_forrest_pf(s_arg, data);
}
