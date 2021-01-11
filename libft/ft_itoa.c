/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:41:38 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 20:24:08 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numblen(int n)
{
	int b;

	b = 0;
	if (n <= 0)
		b++;
	while (n)
	{
		n /= 10;
		b++;
	}
	return (b);
}

char			*ft_itoa(int n)
{
	char	*allocator;
	int		len;
	int		i;
	int		start;

	len = numblen(n);
	i = len - 1;
	start = 0;
	if (!(allocator = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		allocator[start++] = '-';
	while (i >= start)
	{
		allocator[i] = ((n % 10) >= 0 ? (n % 10) : -(n % 10)) + '0';
		n /= 10;
		i--;
	}
	allocator[len] = '\0';
	return (allocator);
}
