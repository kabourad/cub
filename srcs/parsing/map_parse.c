/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:20:33 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/19 16:32:29 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

static t_mapll	*new_node(char *line, t_mapll *prv)
{
	t_mapll	*ret;

	ret = (t_mapll*)malloc(sizeof(t_mapll));
	ret->next = NULL;
	if (prv)
		ret->i = prv->i + 1;
	else
		ret->i = 0;
	ret->line = ft_strdup(line);
	return (ret);
}

static void		check_store(char *line, t_parse *stru, t_mapll **map)
{
	t_mapll	*tmp;
	int		i;

	tmp = *map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			space_check(tmp, line, i);
		else if (is_valid(line[i]))
			twod_check(tmp, line, i, stru);
		else if (line[i] != '1')
			quit("Error\nInvalid map", NULL);
		i++;
	}
	if (tmp)
		tmp->next = new_node(line, tmp);
	else
		*map = new_node(line, tmp);
}

static char		**map_convert(t_mapll *map)
{
	t_mapll	*tmp;
	char	**ret;
	int		i;

	i = ft_listlen(map) + 1;
	ret = (char**)malloc(sizeof(char*) * i);
	ret[i - 1] = NULL;
	i = 0;
	while (map)
	{
		tmp = map->next;
		ret[i] = ft_strdup(map->line);
		ft_strdel(&map->line);
		free(map);
		map = tmp;
		i++;
	}
	return (ret);
}

void			map_fill(int fd, t_parse *stru)
{
	t_mapll	*map;
	char	*line;
	int		n;
	int		i;

	line = NULL;
	map = NULL;
	i = 0;
	while ((n = get_next_line(fd, &line)) >= 0)
	{
		if (line && line[0])
		{
			check_store(line, stru, &map);
			ft_strdel(&line);
		}
		else if ((!line || !line[0]) && map)
			quit("The map shouldn't contain empty lines", NULL);
		if (!n)
			break ;
	}
	check_last_line(map);
	stru->map = map_convert(map);
	stru->ids |= MP_ID;
}
