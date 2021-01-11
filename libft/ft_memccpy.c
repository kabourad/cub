/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:24:25 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/30 08:17:22 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;
	size_t			j;

	f = (unsigned char *)src;
	j = 0;
	s = (unsigned char *)dst;
	while (j < n && f[j] != (unsigned char)c)
	{
		s[j] = f[j];
		j++;
	}
	if (j < n)
	{
		s[j] = (unsigned char)c;
		return (dst + j + 1);
	}
	return (NULL);
}
