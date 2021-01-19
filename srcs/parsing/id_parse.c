/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:06:31 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/19 16:36:41 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

static void	identifier_fill(int id, char **array, t_parse *stru)
{
	if (id == R_ID)
		stru->resolution = resolution_fill(array);
	else if (id == F_ID)
		stru->floor = color_fill(array[1]);
	else if (id == C_ID)
		stru->ceiling = color_fill(array[1]);
	else if (id == NO_ID)
		stru->paths.north = path_fill(array[1]);
	else if (id == SO_ID)
		stru->paths.south = path_fill(array[1]);
	else if (id == EA_ID)
		stru->paths.east = path_fill(array[1]);
	else if (id == WE_ID)
		stru->paths.west = path_fill(array[1]);
	else if (id == S_ID)
		stru->paths.sprite = path_fill(array[1]);
}

static void	id_seek_n_fill(char *line, t_parse *stru)
{
	char	**array;
	int		id;
	int		ln;

	array = ft_split_whitespaces(line);
	ln = ft_arrlen(array);
	id = is_id(array[0], stru->ids);
	if (!id || (id == 1 && ln != 3) || (id != 1 && ln != 2))
		quit("Identifier issue.", NULL);
	if (id == MP_ID)
		quit("Map must be last.", NULL);
	identifier_fill(id, array, stru);
	stru->ids |= id;
	array ? ft_arrdel(&array) : 0;
}

void		id_fill(int fd, t_parse *stru)
{
	char	*line;
	int		n;

	line = NULL;
	while (stru->ids < 255)
	{
		if ((n = get_next_line(fd, &line)) > 0)
			id_seek_n_fill(line, stru);
		if (!n && stru->ids < 255)
			quit("Incomplete file", NULL);
		line ? ft_strdel(&line) : 0;
	}
}
