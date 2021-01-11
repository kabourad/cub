/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:44:17 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 20:43:19 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *str, char c)
{
	int b;

	b = ft_strlen(str);
	while (b >= 0)
	{
		if (str[b] == c)
			return ((char *)str + b);
		b--;
	}
	return (NULL);
}
