/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:32:41 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/11 18:26:03 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*s_stock(char *a, char *b)
{
	char	*p;

	p = a;
	a = ft_strjoin(p, b);
	free(p);
	return (a);
}

static char	*s_free(char *s, int i)
{
	char	*temp;

	temp = s;
	s = temp + i ? ft_strdup(temp + i) : NULL;
	free(temp);
	return (s);
}

static int	cut(char **chr, char **arr, char **line)
{
	if (!(*chr))
		*chr = ft_strchr(*arr, '\n');
	if (**arr == '\0')
	{
		free(*arr);
		*line = NULL;
		return (!(*line = ft_strdup("")));
	}
	if (*chr)
	{
		*line = ft_strndup(*arr, *chr - *arr);
		*arr = s_free(*arr, *chr - *arr + 1);
	}
	else
	{
		*line = ft_strdup(*arr);
		free(*arr);
		*arr = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	char		*chr;
	int			ret;
	static char	*arr = NULL;

	chr = NULL;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!arr)
	{
		arr = (char *)malloc(sizeof(char));
		*arr = '\0';
	}
	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || !buf)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		arr = s_stock(arr, buf);
		if ((chr = ft_strchr(arr, '\n')))
			break ;
	}
	free(buf);
	return (cut(&chr, &arr, line));
}
