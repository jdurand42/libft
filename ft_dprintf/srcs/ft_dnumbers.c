/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dnumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:07:29 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/17 12:56:59 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	dprint_numbers(char *s, t_dparams *data)
{
	size_t	len;
	char	buffer[1024];

	len = ft_strlen(s);
	dcheck_number(s, data, len);
	buffer[0] = 0;
	ft_strcat(buffer, s);
	if (data->width == -1 && data->prec == -1)
	{
		write(data->fd, s, len);
		data->count += len;
		return ;
	}
	if (data->prec >= 0)
		ddo_prec_number(data, s, buffer, (int)len);
	len = ft_strlen(buffer);
	if (data->width > 0 && !(data->flags & FLAG_MINUS))
		dprint_width_n(data, buffer, (int)len);
	len = ft_strlen(buffer);
	write(data->fd, buffer, len);
	data->count += len;
	if (data->width > 0 && (data->flags & FLAG_MINUS))
		dprint_width_n(data, buffer, (int)len);
}

void	dcheck_number(char *s, t_dparams *data, size_t len)
{
	if ((data->flags & FLAG_DOT) && (data->flags & FLAG_ZERO) &&
	data->prec >= 0)
		data->flags ^= FLAG_ZERO;
	if (s[0] == '-')
		data->flags |= 32;
	if ((data->prec < (int)len))
		data->prec = -1;
	if (data->width < (int)len)
		data->width = -1;
}

void	ddo_prec_number(t_dparams *data, char *s, char *b, size_t len)
{
	int		len_0;
	int		i;
	char	buffer[1024];

	i = 0;
	len_0 = 0;
	if (data->prec != -1)
		len_0 = data->prec - (int)len;
	if (data->flags & FLAG_NEG)
	{
		buffer[0] = '-';
		i++;
		s = s + 1;
		len_0 += 1;
	}
	if (data->prec >= 0)
	{
		while (len_0--)
		{
			buffer[i] = '0';
			i++;
		}
	}
	buffer[i] = 0;
	ft_strcpy(b, ft_strcat(buffer, s));
}

void	dprint_width_n(t_dparams *data, char *b, size_t len)
{
	int len_0;
	int i;

	i = 0;
	if (data->width < (int)len)
		return ;
	len_0 = data->width - (int)len;
	if (!(data->flags & FLAG_ZERO))
		while (len_0--)
		{
			ft_putchar_fd(data->fd, ' ');
			data->count++;
		}
	else if (data->flags & FLAG_ZERO)
	{
		if (data->flags & FLAG_NEG)
		{
			ft_putchar_fd(data->fd, '-');
			b = ft_strcpy(b, &b[1]);
			data->count += 1;
		}
		data->count += len_0;
		while (len_0--)
			ft_putchar_fd(data->fd, '0');
	}
}
