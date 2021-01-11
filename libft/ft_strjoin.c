/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:17:41 by kabourad          #+#    #+#             */
/*   Updated: 2019/10/28 20:27:38 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*ess;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ess = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ess)
		return (NULL);
	while (s1[i])
	{
		ess[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		ess[i] = s2[i - len1];
		i++;
	}
	ess[len1 + len2] = '\0';
	return (ess);
}
