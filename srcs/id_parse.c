/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:06:31 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/12 16:47:03 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	identifier_fill(int id, char **array, t_parse *stru)
{
	if (id == R_ID)
        stru->resolution = resolution_fill(array);
    else if (id == F_ID)
        stru->floor = color_fill(array[1]);
    else if (id == C_ID)
        stru->ceiling = color_fill(array[1]);
    else if (id == NO_ID )
        stru->orientation.no = path_fill(array[1]);
    else if (id == SO_ID )
        stru->orientation.so = path_fill(array[1]);
    else if (id == EA_ID )
        stru->orientation.ea = path_fill(array[1]);
    else if (id == WE_ID )
        stru->orientation.we = path_fill(array[1]);
    else if (id == S_ID )
        stru->sprite = path_fill(array[1]);
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
		put_and_quit("Identifier issue.");
	if (id == MP_ID)
		put_and_quit("Map must be last.");
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
			put_and_quit("Incomplete file");
		line ? ft_strdel(&line) : 0;
	}
}