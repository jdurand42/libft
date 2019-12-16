/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:56:00 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/12 17:04:57 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libbmp.h"

int		check_header(t_bmp *bmp)
{
	if (bmp->file_header->signature[0] != 'B' &&
			bmp->file_header->signature[1] != 'M')
		return (0);
	if (bmp->info_header->bm_headersize != 40)
		return (0);
	if (bmp->info_header->bpp != 24)
		return (0);
	return (1);
}
