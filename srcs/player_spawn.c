/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:23:47 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/12 18:56:24 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int			linked_list_len(t_mapll *map)
{
	t_mapll		*tmp;
	int			i;

	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_ingame	player_spawn(t_parse game)
{
	t_ingame	ret;
	t_mapll		*tmp;
	int			i;

	ret.player = game.player;
	i = linked_list_len(game.map) + 1;
	ret.map = (char**)malloc(sizeof(char*) * i);
	ret.map[i - 1] = NULL;
	tmp = game.map;
	i = 0;
	while (tmp)
		ret.map[i++] = ft_strdup(tmp->line);
	return (ret);
}
