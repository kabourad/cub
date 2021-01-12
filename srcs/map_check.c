/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:45:55 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/12 18:49:19 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static t_player	fill_player(t_parse *stru, t_mapll *tmp, char *line, int i)
{
	t_player	ret;
	
	stru->ids |= PL_ID;
	ret.pos.x = i;
	ret.pos.y = tmp->i + 1;
	if (line[i] == 'N')
		ret.dir.y = -1;
	else if (line[i] == 'S')
		ret.dir.y = 1;
	else if (line[i] == 'E')
		ret.dir.x = 1;
	else if (line[i] == 'W')
		ret.dir.x = -1;
}

void	space_check(t_mapll *tmp, char *line, int i)
{
	if ((tmp && tmp->line[i] != '1' && tmp->line[i] != ' ') ||
			(line[i + 1] != '1' && line[i + 1] != ' '))
		put_and_quit("Error\nInvalid map");
}

int		is_valid(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	twod_check(t_mapll *tmp, char *line, int i, t_parse *stru)
{
	if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			&& !(stru->ids & PL_ID))
		stru->player = fill_player(stru, tmp, line, i);
	else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			&& (stru->ids & PL_ID))
		put_and_quit("It's a single player game verify map.");
	if ((tmp && tmp->line[i] != '1' && !is_valid(tmp->line[i])) ||
			(line[i + 1] != '1' && !is_valid(line[i + 1])))
		put_and_quit("Invalid map.");
}

void	check_last_line(t_mapll *ptr)
{
	t_mapll	*tmp;
	int		i;

	i = 0;
	tmp = ptr;
	while (tmp->next)
		tmp = tmp->next;
	i = 0;
	while (tmp->line[i])
	{
		if (tmp->line[i] != '1' && tmp->line[i] != ' ')
			put_and_quit("Invalid map.");
		i++;
	}
}
