/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:47:44 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/20 14:52:15 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

void	parsing(char *path, t_cub *cub)
{
	int			fd;

	cub->parse = stru_init();
	if ((fd = open(path, O_RDONLY)) == -1)
		quit("Opening file failed.", NULL, cub);
	id_fill(fd, cub);
	map_fill(fd, cub);
	close(fd);
}
