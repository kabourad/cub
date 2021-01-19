/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 05:54:56 by awali-al          #+#    #+#             */
/*   Updated: 2021/01/19 16:35:58 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

int		plane(t_parse *game, int i)
{
	t_vec	ray;
	double	camx;

	camx = 2 * i / game->resolution.width - 1;
	ray.x = game->player.dir.x + game->player.pln.x * camx;
	ray.y = game->player.dir.y + game->player.pln.y * camx;
	// drawing a ray
}

int		ray_cast(t_parse game)
{
	int		i;

	i = 0;
	while (i < game.resolution.width)
	{
		plane(&game, i);
	}
}
