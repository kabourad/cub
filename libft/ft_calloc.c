/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:59:22 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 20:32:14 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	char	*p;
	size_t	i;

	if (!(ret = (char *)(malloc(count * size))))
		return (NULL);
	i = 0;
	p = (char *)ret;
	while (i < count * size)
	{
		*(p + i) = 0;
		i++;
	}
	return (ret);
}
