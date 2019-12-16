/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:15:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/12 16:47:17 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

typedef struct	s_params
{
	va_list		ap;
	size_t		count;
	size_t		i;
	size_t		j;
	int			flags;
	int			width;
	int			prec;
}				t_params;

int				ft_printf(char const *str, ...);
void			do_forrest_pf(char *s, t_params *data, char *s_flags);
void			put_forrest_pf(char *s, t_params *data);
void			bilbo_flaggings_pf(char *s_flags, t_params *data);
char			*get_flags_pf(char *s, t_params *data);
int				get_id_pf(char c);
void			flags_forrest_pf(char *s_flags, t_params *data);
void			parse_width_pf(char *s_flags, t_params *data, int *i);
void			parse_prec_pf(char *s_flags, t_params *data, int *i);
void			do_prec_s_pf(t_params *data, size_t *len);
void			do_neg_pf(t_params *data, char **s, size_t *len);
void			print_width_s_pf(t_params *data, size_t len);
void			check_number_pf(char *s, t_params *data, size_t len);
void			print_numbers_pf(char *s, t_params *data);
void			print_width_n_pf(t_params *data, char *b, size_t len);
void			do_prec_number_pf(t_params *data, char *s, char *b, size_t len);
int				ft_isflag_pf(char c);
void			ft_init_struct_pf(t_params *data);
char			*ft_strjoin_free_pf(char const *s1, char const *s2);
void			ft_putstr_pf(char *s, t_params *data);
void			print_char_pf(t_params *data);
void			print_str_pf(t_params *data);
void			print_void_pf(t_params *data);
void			print_int_pf(t_params *data);
void			print_usint_pf(t_params *data);
void			print_hexa_pf(t_params *data);
void			print_up_hexa_pf(t_params *data);
void			print_percent_pf(t_params *data);
void			print_random_char_pf(t_params *data, char c);
void			free_flags_pf(char *s_flags);

#endif
