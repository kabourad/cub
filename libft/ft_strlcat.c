/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:38:44 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 17:04:53 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_mini(size_t a, size_t b)
{
	return (a < b ? a : b);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t v;

	i = 0;
	v = ft_strlen(dst);
	if (!dst || !src || !size)
		return (ft_strlen(src) + ft_mini(size, v));
	while (src[i] && v + i < size - 1)
	{
		dst[v + i] = src[i];
		i++;
	}
	dst[v + i] = '\0';
	return (ft_strlen(src) + ft_mini(size, v));
}
