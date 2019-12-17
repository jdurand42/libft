/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrings_printers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:44:34 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/17 12:56:46 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_dputstr_pf(char *s, t_dparams *data)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[0] == 0 && !(data->flags & FLAG_STR))
		len += 1;
	if (data->prec > -1)
		ddo_prec_s(data, &len);
	if (!(data->flags & FLAG_MINUS))
		dprint_width_s(data, len);
	write(data->fd, s, len);
	data->count += len;
	if (data->flags & FLAG_MINUS)
		dprint_width_s(data, len);
}

void	dput_forrest(char *s, t_dparams *data)
{
	if (data->flags & FLAG_NUMBER)
		dprint_numbers(s, data);
	else
		ft_dputstr_pf(s, data);
}

void	ddo_prec_s(t_dparams *data, size_t *len)
{
	if ((int)*len > data->prec)
		*len = (int)data->prec;
	return ;
}

void	dprint_width_s(t_dparams *data, size_t len)
{
	int len_width;

	if (data->width < 1 || data->width < (int)len)
		return ;
	len_width = data->width - (int)len;
	while (len_width--)
	{
		if (!(data->flags & FLAG_ZERO))
			ft_putchar_fd(data->fd, ' ');
		else
			ft_putchar_fd(data->fd, '0');
		data->count += 1;
	}
}
