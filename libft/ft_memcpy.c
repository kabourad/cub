/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:24:25 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/31 16:12:41 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;
	size_t			j;

	if (!dst || !src || !n)
		return (dst);
	f = (unsigned char *)src;
	j = 0;
	s = (unsigned char *)dst;
	while (j < n)
	{
		s[j] = f[j];
		j++;
	}
	return (dst);
}
