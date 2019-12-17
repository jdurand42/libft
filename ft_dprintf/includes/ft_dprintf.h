/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:15:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/17 12:56:07 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "../../libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define HEXA "0123456789abcdef"
# define BIG_HEXA "0123456789ABCDEF"
# define FLAG_MINUS 1
# define FLAG_WC 2
# define FLAG_DOT 4
# define FLAG_ZERO 8
# define FLAG_NUMBER 16
# define FLAG_NEG 32
# define FLAG_STR 64

typedef struct	s_dparams
{
	va_list		ap;
	size_t		count;
	size_t		i;
	size_t		j;
	int			flags;
	int			width;
	int			prec;
	int			fd;
}				t_dparams;

int				ft_dprintf(int fd, char const *str, ...);
void			ddo_forrest(char *s, t_dparams *data, char *s_flags);
void			dput_forrest(char *s, t_dparams *data);
void			dbilbo_flaggings(char *s_flags, t_dparams *data);
char			*dget_flags(char *s, t_dparams *data);
int				dget_id(char c);
void			dflags_forrest(char *s_flags, t_dparams *data);
void			dparse_width(char *s_flags, t_dparams *data, int *i);
void			dparse_prec(char *s_flags, t_dparams *data, int *i);
void			ddo_prec_s(t_dparams *data, size_t *len);
void			ddo_neg(t_dparams *data, char **s, size_t *len);
void			dprint_width_s(t_dparams *data, size_t len);
void			dcheck_number(char *s, t_dparams *data, size_t len);
void			dprint_numbers(char *s, t_dparams *data);
void			dprint_width_n(t_dparams *data, char *b, size_t len);
void			ddo_prec_number(t_dparams *data, char *s, char *b, size_t len);
int				dft_isflag(char c);
void			ft_dinit_struct(t_dparams *data, int fd);
char			*ft_dstrjoin_free(char const *s1, char const *s2);
int				ft_atoi_pos(char const *str);
void			ft_dputstr_pf(char *s, t_dparams *data);
void			dprint_char(t_dparams *data);
void			dprint_str(t_dparams *data);
void			dprint_void(t_dparams *data);
void			dprint_int(t_dparams *data);
void			dprint_usint(t_dparams *data);
void			dprint_hexa(t_dparams *data);
void			dprint_up_hexa(t_dparams *data);
void			dprint_percent(t_dparams *data);
void			dprint_random_char(t_dparams *data, char c);
void			dfree_flags(char *s_flags);

#endif
