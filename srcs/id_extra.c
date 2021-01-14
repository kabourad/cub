/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:46:23 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/14 17:22:36 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

static int	map_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != '2'
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
				&& line[i] != 'W')
			return (1);
        if (line[i] == 'W' && line[i + 1] == 'E')
			return (1);
        if (line[i] == 'S' && !line[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int			is_id(char *c, int ids)
{
	int		ret;

	ret = 0;
	ret = !ft_strcmp(c, "R") && !(ids & R_ID) ? R_ID : ret;
	ret = !ft_strcmp(c, "S") && !(ids & S_ID) ? S_ID : ret;
	ret = !ft_strcmp(c, "C") && !(ids & C_ID) ? C_ID : ret;
	ret = !ft_strcmp(c, "F") && !(ids & F_ID) ? F_ID : ret;
	ret = !ft_strcmp(c, "NO") && !(ids & NO_ID) ? NO_ID : ret;
	ret = !ft_strcmp(c, "SO") && !(ids & SO_ID) ? SO_ID : ret;
	ret = !ft_strcmp(c, "WE") && !(ids & WE_ID) ? WE_ID : ret;
	ret = !ft_strcmp(c, "EA") && !(ids & EA_ID) ? EA_ID : ret;
	ret = !map_line(c) ? MP_ID : ret;
	return (ret);
}