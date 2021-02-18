/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:06:31 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/18 01:28:33 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

static void	identifier_fill(int id, char **array, t_cub *cub)
{
	if (id == R_ID)
		cub->parse.res = res_fill(array);
	else if (id == F_ID)
		cub->parse.floor = color_fill(array[1], cub);
	else if (id == C_ID)
		cub->parse.ceiling = color_fill(array[1], cub);
	else if (id == NO_ID)
		cub->parse.paths.north = path_fill(array[1], cub);
	else if (id == SO_ID)
		cub->parse.paths.south = path_fill(array[1], cub);
	else if (id == EA_ID)
		cub->parse.paths.east = path_fill(array[1], cub);
	else if (id == WE_ID)
		cub->parse.paths.west = path_fill(array[1], cub);
	else if (id == S_ID)
		cub->parse.paths.sprite = path_fill(array[1], cub);
}

static void	id_seek_n_fill(char *line, t_cub *cub)
{
	char	**array;
	int		id;
	int		ln;

	array = ft_split_whitespaces(line);
	ln = ft_arrlen(array);
	id = is_id(array[0], cub->parse.ids);
	if (!id || (id == 1 && ln != 3) || (id != 1 && ln != 2))
	{
		array ? ft_arrdel(&array) : 0;
		quit("Identifier issue.", NULL, cub);
	}
	if (id == MP_ID)
	{
		array ? ft_arrdel(&array) : 0;
		quit("Map must be last.", NULL, cub);
	}
	identifier_fill(id, array, cub);
	cub->parse.ids |= id;
	array ? ft_arrdel(&array) : 0;
}

void		id_fill(int fd, t_cub *cub)
{
	char	*line;
	int		n;

	line = NULL;
	while (cub->parse.ids < 255)
	{
		if ((n = get_next_line(fd, &line)) > 0 && line && line[0])
			id_seek_n_fill(line, cub);
		if (!n && cub->parse.ids < 255)
		{
			line ? ft_strdel(&line) : 0;
			quit("Incomplete file", NULL, cub);
		}
		line ? ft_strdel(&line) : 0;
	}
}
