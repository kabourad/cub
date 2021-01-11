/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:59:40 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 20:44:11 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *str, char c)
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
