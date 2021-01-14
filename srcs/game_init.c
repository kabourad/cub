/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:47:44 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/14 17:22:39 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

static t_parse	stru_init(void)
{
	t_parse		stru;

	stru.resolution.x = 0;
	stru.resolution.y = 0;
	stru.orientation.no = NULL;
	stru.orientation.so = NULL;
	stru.orientation.we = NULL;
	stru.orientation.ea = NULL;
	stru.sprite = NULL;
	stru.floor.r = 0;
	stru.floor.g = 0;
	stru.floor.b = 0;
	stru.ceiling.r = 0;
	stru.ceiling.g = 0;
	stru.ceiling.b = 0;
	stru.player.pos.x = 0;
	stru.player.pos.y = 0;
	stru.player.dir.x = 0;
	stru.player.dir.y = 0;
	stru.ids = 0;
	stru.map = NULL;
	return (stru);
}

t_parse			game_init(char *path)
{
    int			fd;
	t_parse		ret;

	ret = stru_init();
    if ((fd = open(path, O_RDONLY)) == -1) 
		put_and_quit("Opening file failed.");
	id_fill(fd, &ret);
	map_fill(fd, &ret);
	return (ret);
}