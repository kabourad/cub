/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:45:39 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/18 14:25:03 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"


static void	free_map(t_cub *cub)
{
	int		i;

	i = 0;
	while (cub->parse.map[i])
	{
		free(cub->parse.map[i]);
		i++;
	}
	free(cub->parse.map);
}

void	clear_game(t_cub *cub)
{
	int		i;

	cub->parse.paths.north ? free(cub->parse.paths.north) : 0;
	cub->parse.paths.south ? free(cub->parse.paths.south) : 0;
	cub->parse.paths.east ? free(cub->parse.paths.east) : 0;
	cub->parse.paths.west ? free(cub->parse.paths.west) : 0;
	cub->parse.paths.sprite ? free(cub->parse.paths.sprite) : 0;
	cub->parse.map ? free_map(cub) : 0;
	cub->parse.sprites ? free(cub->parse.sprites) : 0;
	if (cub->mlx)
	{
		// cub->image.img ? mlx_destroy_image(cub->mlx, cub->image.img) : 0;
		i = 0;
		while (i < 5)
			cub->text[i].img ? mlx_destroy_image(cub->mlx, cub->text[i++].img) :
					0;
	}
}