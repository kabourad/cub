/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:18:27 by kabourad          #+#    #+#             */
/*   Updated: 2019/11/01 14:34:42 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		ret++;
	}
	return (ret);
}

static char		*get_str(char const *s, int i, int j)
{
	int		k;
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	k = 0;
	while (i < j)
		ret[k++] = s[i++];
	ret[k] = '\0';
	return (ret);
}

static void		leakprotector(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		in;
	char	**ret;

	if (!s || !(ret = (char **)ft_calloc((word_count(s, c) + 1),
	sizeof(char *))))
		return (NULL);
	i = 0;
	in = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] && s[j] != c && s[j] != '\0')
			j++;
		if (s[i] && !(ret[in++] = get_str(s, i, j)))
		{
			leakprotector(ret, in);
			return (NULL);
		}
		i = j;
	}
	return (ret);
}
