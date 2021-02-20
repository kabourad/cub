/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:54:19 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/20 14:52:53 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	if (*st1 == '\0' && *st2 == '\0')
		return (0);
	if (*st1 == *st2)
		return (ft_strcmp(s1 + 1, s2 + 1));
	else
		return (*st1 - *st2);
}
