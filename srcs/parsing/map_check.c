/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:45:55 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/18 00:59:30 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

static t_vec	fill_pos(int a, int b)
{
	t_vec	ret;

	ret.x = a + 0.5;
	ret.y = b + 0.5;
	return (ret);
}

static t_player	fill_player(t_parse *stru, t_mapll *tmp, char *line, int i)
{
	t_player	ret;

	stru->ids |= PL_ID;
	ret.pos = fill_pos(i, tmp->i + 1);
	if (line[i] == 'N')
	{
		ret.pln.x = 0.66;
		ret.dir.y = -1.0;
	}
	else if (line[i] == 'S')
	{
		ret.pln.x = -0.66;
		ret.dir.y = 1.0;
	}
	else if (line[i] == 'E')
	{
		ret.pln.y = 0.66;
		ret.dir.x = 1.0;
	}
	else if (line[i] == 'W')
	{
		ret.pln.y = -0.66;
		ret.dir.x = -1.0;
	}
	return (ret);
}

void			space_check(t_mapll *tmp, char *line, int i, t_cub *cub)
{
	if ((tmp && tmp->line[i] != '1' && tmp->line[i] != ' ') ||
			(line[i + 1] != '1' && line[i + 1] != ' '))
		quit("Error\nInvalid map", NULL, cub);
}

void			twod_check(t_mapll *tmp, char *line, int i, t_cub *cub)
{
	if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			&& !(cub->parse.ids & PL_ID))
		cub->parse.ply = fill_player(&(cub->parse), tmp, line, i);
	else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W') && (cub->parse.ids & PL_ID))
		quit("It's a single player game verify map.", NULL, cub);
	if (line[i] == '2')
		cub->parse.spr_num++;
	if ((tmp && tmp->line[i] != '1' && !is_valid(tmp->line[i])) ||
			(line[i + 1] != '1' && !is_valid(line[i + 1])))
		quit("Invalid map.", NULL, cub);
}

int				check_last_line(t_mapll *ptr)
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
			return (1);
		i++;
	}
	return (0);
}
