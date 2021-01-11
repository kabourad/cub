/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:41:49 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 20:42:19 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*t;

	if (!s1 || !s2)
		return (0);
	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	i = 0;
	while (i < n && s[i] && t[i] && s[i] == t[i])
		i++;
	if (i != n)
		return (s[i] - t[i]);
	return (0);
}
