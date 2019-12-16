/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:27:05 by jdurand           #+#    #+#             */
/*   Updated: 2019/12/12 17:02:36 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./ft_printf/includes/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./bmp/includes/libbmp.h"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
int				ft_cmp(int c, int c2);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			ft_memrev(void *tab, size_t elelen, size_t len);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_memswap(void *a, void *b);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl(char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
int				ft_biggerofthree(int a, int b, int c);
int				ft_fibonacci(int index);
int				ft_find_next_prime(int nb);
int				ft_is_prime(int nb);
int				ft_iterative_factorial(int nb);
int				ft_iterative_power(int nb, int power);
int				ft_rand(int min, int max, int seed);
int				ft_recursive_factorial(int nb);
int				ft_recursive_power(int nb, int power);
int				ft_smallerofthree(int a, int b, int c);
int				ft_sqrt(int nb);
double			ft_exp(double x);
int				ft_intlog(long int x, long int base);
int				ft_atoi_base(char const *str, char *base);
int				ft_atoi(char const *str);
char			*ft_itoa_base(long int nbr, char *base);
char			*ft_itoa_base_ul(unsigned long nbr, char *base);
char			*ft_itoa(int n);
char			*ft_itoa_us(unsigned int n);
int				ft_myatoi(char *str);
void			ft_putnbr_base(int nbr, char *base);
int				ft_nbrlen(long int nbr);
int				ft_base_isvalid(char *base);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islowercase(int c);
int				ft_isprint(int c);
int				ft_isuppercase(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			**ft_split_all(char *str, char *charset);
char			*ft_strcat(char *dest, char const *src);
char			*ft_strcpy(char *dest, char const *src);
char			*ft_strdup(char const *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, char const *src, size_t maxsize);
size_t			ft_strlcpy(char *dst, char const *src, size_t maxlen);
size_t			ft_strlen(char const *str);
char			*ft_strncat(char *dest, char const *src, size_t nb);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strndup(char const *src, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			**ft_split(char const *s, char c);
t_list			*ft_strsplitlst(char const *s, char c);
char			*ft_strtrim_all(char const *s, char const *set);
char			*ft_strtrim(char const *s, char const *set);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list			*ft_lstnew(const void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstfind(t_list *lst, unsigned char to_find);
void			ft_lstcpy(t_list **dest, t_list *lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lst_goto(t_list *lst, int indice);
t_list			*ft_lstlast(t_list *lst);
void			ft_sort_int_tab(int *tab, int size);
void			ft_intswap(int *a, int *b);
int				ft_charstrcmp(const char c, const void *s2);
char			*ft_file_str(int fd);
char			*ft_strncat_op(char *dest, char const *src, size_t n, size_t l);

#endif
