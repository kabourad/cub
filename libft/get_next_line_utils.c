/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:00:06 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/11 18:25:56 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *str, char c)
{
	int b;

	b = 0;
	while (str[b])
	{
		if (str[b] == c)
			return ((char *)str + b);
		b++;
	}
	if (c == '\0')
		return ((char *)str + b);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*ess;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ess = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ess)
		return (NULL);
	while (s1[i])
	{
		ess[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		ess[i] = s2[i - len1];
		i++;
	}
	ess[len1 + len2] = '\0';
	return (ess);
}

char	*ft_strndup(const char *src, int n)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
