/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:47:44 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/18 02:44:10 by awali-al         ###   ########.fr       */
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
