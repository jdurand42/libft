/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:07:29 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/07 15:50:06 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_numbers_pf(char *s, t_params *data)
{
	size_t	len;
	char	buffer[1024];

	len = ft_strlen(s);
	check_number_pf(s, data, len);
	buffer[0] = 0;
	ft_strcat(buffer, s);
	if (data->width == -1 && data->prec == -1)
	{
		write(1, s, len);
		data->count += len;
		return ;
	}
	if (data->prec >= 0)
		do_prec_number_pf(data, s, buffer, (int)len);
	len = ft_strlen(buffer);
	if (data->width > 0 && !(data->flags & FLAG_MINUS))
		print_width_n_pf(data, buffer, (int)len);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	data->count += len;
	if (data->width > 0 && (data->flags & FLAG_MINUS))
		print_width_n_pf(data, buffer, (int)len);
}

void	check_number_pf(char *s, t_params *data, size_t len)
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

void	do_prec_number_pf(t_params *data, char *s, char *b, size_t len)
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

void	print_width_n_pf(t_params *data, char *b, size_t len)
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
			ft_putchar(' ');
			data->count++;
		}
	else if (data->flags & FLAG_ZERO)
	{
		if (data->flags & FLAG_NEG)
		{
			ft_putchar('-');
			b = ft_strcpy(b, &b[1]);
			data->count += 1;
		}
		data->count += len_0;
		while (len_0--)
			ft_putchar('0');
	}
}
