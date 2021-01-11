/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:02:46 by kabourad          #+#    #+#             */
/*   Updated: 2019/11/06 15:18:59 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_space(const char *str)
{
	while ((*str) != '\0')
	{
		if ((*str) == '\t' || (*str) == '\n' || (*str) == '\v' ||
		(*str) == '\f' || (*str) == '\r' || (*str) == ' ')
			str++;
		else
			return ((char *)str);
	}
	return ((char *)str);
}

int				ft_atoi(const char *str)
{
	long long	res;
	long long	neg;

	str = ft_space(str);
	neg = 1;
	res = 0;
	if ((*str) == '+')
		str++;
	else if ((*str) == '-')
	{
		neg = -1;
		str++;
	}
	while (((*str) >= '0' && (*str) <= '9') && (*str) != '\0')
	{
		if (res * 10 + (*str - '0') < res)
			return (neg == -1 ? 0 : -1);
		res = res * 10 + *str - '0';
		str++;
	}
	return ((int)(res * neg));
}
