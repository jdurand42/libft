/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_printers_pf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:44:34 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/07 15:54:52 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_pf(char *s, t_params *data)
{
	size_t	len;

	len = ft_strlen(s);
	if (s[0] == 0 && !(data->flags & FLAG_STR))
		len += 1;
	if (data->prec > -1)
		do_prec_s_pf(data, &len);
	if (!(data->flags & FLAG_MINUS))
		print_width_s_pf(data, len);
	write(1, s, len);
	data->count += len;
	if (data->flags & FLAG_MINUS)
		print_width_s_pf(data, len);
}

void	put_forrest_pf(char *s, t_params *data)
{
	if (data->flags & FLAG_NUMBER)
		print_numbers_pf(s, data);
	else
		ft_putstr_pf(s, data);
}

void	do_prec_s_pf(t_params *data, size_t *len)
{
	if ((int)*len > data->prec)
		*len = (int)data->prec;
	return ;
}

void	print_width_s_pf(t_params *data, size_t len)
{
	int len_width;

	if (data->width < 1 || data->width < (int)len)
		return ;
	len_width = data->width - (int)len;
	while (len_width--)
	{
		if (!(data->flags & FLAG_ZERO))
			ft_putchar(' ');
		else
			ft_putchar('0');
		data->count += 1;
	}
}
