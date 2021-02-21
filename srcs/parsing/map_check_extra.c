/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:52:17 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/21 16:42:47 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

int		is_valid(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

int		check_last_line(t_mapll *map)
{
	t_mapll	*tmp;
	int		i;

	if (!map)
		return (1);
	tmp = map;
	i = 0;
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (tmp && tmp->line && tmp->line[i])
	{
		if (is_valid(tmp->line[i]))
			return (1);
		i++;
	}
	return (0);
}
