/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:52:01 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/17 12:57:01 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include <stdio.h>

void	dprint_char(t_dparams *data)
{
	char c;
	char pc[2];

	c = va_arg(data->ap, int);
	pc[0] = c;
	pc[1] = 0;
	data->prec = -1;
	dput_forrest(pc, data);
}

void	dprint_percent(t_dparams *data)
{
	char c;
	char pc[2];

	c = '%';
	pc[0] = c;
	pc[1] = 0;
	data->prec = -1;
	dput_forrest(pc, data);
}

void	dprint_random_char(t_dparams *data, char c)
{
	char pc[2];

	pc[0] = c;
	pc[1] = 0;
	data->prec = -1;
	dput_forrest(pc, data);
}

void	dprint_str(t_dparams *data)
{
	char *s_arg;

	s_arg = va_arg(data->ap, char*);
	if (!s_arg)
		s_arg = ("(null)");
	data->flags |= FLAG_STR;
	dput_forrest(s_arg, data);
}
