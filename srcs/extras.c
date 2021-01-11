/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 00:02:46 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/11 18:36:18 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/cub3d.h"

void	ft_strdel(char **as)
{
	if (as)
	{
		free((void*)*as);
		*as = NULL;
	}
}

int     ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

void    ft_arrdel(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

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

void	put_and_quit(char *msg)
{
	ft_putendl_fd(msg, 2);
        exit(1);
}
