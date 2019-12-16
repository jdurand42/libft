/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <jdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:25:50 by jdurand           #+#    #+#             */
/*   Updated: 2019/11/09 14:09:16 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

static char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t			megasize;
	char			*b;
	size_t			len_1;

	if (!s1 && s2)
		return (ft_strndup(s2, n));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	megasize = len_1 + n;
	if (!(b = (char *)malloc((megasize + 1) * sizeof(char))))
		return (NULL);
	b[0] = 0;
	ft_strcpy(b, s1);
	free((char*)s1);
	ft_strncat_op(b, s2, n, len_1);
	return (b);
}

static int	parse_line2(char *buffer, char *b_el, char **line, char *b_line)
{
	if (!(*line = ft_strnjoin(b_line, buffer, b_el - buffer)))
		return (-1);
	ft_strcpy(buffer, b_el + 1);
	b_line = NULL;
	return (1);
}

static int	parse_line(char *buffer, char *buffer_el, char **line, char *b_line)
{
	if (!(*line = ft_strndup(b_line, buffer_el - b_line)))
		return (-1);
	ft_strcpy(buffer, buffer_el + 1);
	free(b_line);
	b_line = NULL;
	return (1);
}

static int	parse_line3(char **line, char *b_line)
{
	if (!(*line = strdup(b_line)))
		return (-1);
	free(b_line);
	b_line = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		buffer_nul[1];
	char		*b_line;
	char		*buffer_el;
	int			ret;

	if (fd < 0 || read(fd, buffer_nul, 0) < 0 ||
		!(b_line = ft_strndup(buffer, BUFFER_SIZE)))
		return (-1);
	if ((buffer_el = ft_strchr(b_line, '\n')) != NULL)
		return (parse_line(buffer, buffer_el, line, b_line));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if ((buffer_el = ft_strchr(buffer, '\n')) != NULL)
			return (parse_line2(buffer, buffer_el, line, b_line));
		if (!(b_line = ft_strnjoin(b_line, buffer, BUFFER_SIZE)))
			return (-1);
	}
	buffer[ret] = 0;
	return (parse_line3(line, b_line));
}
