/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:28:33 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/31 16:13:23 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tracer(const char *s1, const char *s2, size_t i, size_t len)
{
	int j;

	j = 0;
	while (s2[j] != '\0' && i < len)
	{
		if (s2[j] == s1[i])
		{
			j++;
			i++;
			if (s2[j] == '\0')
			{
				return (1);
			}
		}
		else
		{
			break ;
		}
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		res;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			res = ft_tracer(haystack, needle, i, len);
			if (res == 1)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
