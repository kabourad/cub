/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:45:55 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/19 16:30:33 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

static t_vec	fill_pos(int a, int b)
{
	t_vec	ret;

	ret.x = a;
	ret.y = b;
	return (ret);
}

static t_player	fill_player(t_parse *stru, t_mapll *tmp, char *line, int i)
{
	t_player	ret;

	stru->ids |= PL_ID;
	ret.pos = fill_pos(i, tmp->i + 1);
	if (line[i] == 'N')
	{
		ret.pln.x = -0.6;
		ret.dir.y = -1.0;
	}
	else if (line[i] == 'S')
	{
		ret.pln.x = 0.6;
		ret.dir.y = 1.0;
	}
	else if (line[i] == 'E')
	{
		ret.pln.y = -0.6;
		ret.dir.x = 1.0;
	}
	else if (line[i] == 'W')
	{
		ret.pln.y = 0.6;
		ret.dir.x = -1.0;
	}
	return (ret);
}

void			space_check(t_mapll *tmp, char *line, int i)
{
	if ((tmp && tmp->line[i] != '1' && tmp->line[i] != ' ') ||
			(line[i + 1] != '1' && line[i + 1] != ' '))
		quit("Error\nInvalid map", NULL);
}

void			twod_check(t_mapll *tmp, char *line, int i, t_parse *stru)
{
	if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			&& !(stru->ids & PL_ID))
		stru->player = fill_player(stru, tmp, line, i);
	else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W') && (stru->ids & PL_ID))
		quit("It's a single player game verify map.", NULL);
	if ((tmp && tmp->line[i] != '1' && !is_valid(tmp->line[i])) ||
			(line[i + 1] != '1' && !is_valid(line[i + 1])))
		quit("Invalid map.", NULL);
}

void			check_last_line(t_mapll *ptr)
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
			quit("Invalid map.", NULL);
		i++;
	}
}
