/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 05:54:56 by awali-al          #+#    #+#             */
/*   Updated: 2021/01/26 16:48:43 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

void	rayon(t_parse *game, t_cam *cam, t_vec ray)
{
	cam->mapx = (int)(game->player.pos.x);
	cam->mapy = (int)game->player.pos.y;
	if (ray.x < 0)
	{
		cam->stepx = -1;
		cam->sidedist.x = ((int)(game->player.pos.x) - cam->mapx) *
				cam->deltadist.x;
	}
	else
	{
		cam->stepx = 1;
		cam->sidedist.x = (cam->mapx + 1.0 - game->player.pos.x) *
				cam->deltadist.x;
	}
	if (ray.y < 0)
	{
		cam->stepy = -1;
		cam->sidedist.y = (game->player.pos.y - cam->mapy) * cam->deltadist.y;
	}
	else
	{
		cam->stepy = 1;
		cam->sidedist.y = (cam->mapy + 1.0 - game->player.pos.y) *
				cam->deltadist.y;
	}
}

int		plane(t_parse *game, int i, t_cam *cam)
{
	t_vec	ray;
	double	camx;

	camx = 2 * i / game->res.w - 1;
	ray.x = game->player.dir.x + game->player.pln.x * camx;
	ray.y = game->player.dir.y + game->player.pln.y * camx;
	if (ray.y == 0)
		cam->deltadist.x = 0;
	else if (ray.x == 0)
		cam->deltadist.x = 1;
	else
		cam->deltadist.x = abs(1 / ray.x);
	if (ray.x == 0)
		cam->deltadist.y = 0;
	else if (ray.y == 0)
		cam->deltadist.y = 1;
	else
		cam->deltadist.y = abs(1 / ray.y);
	rayon(game, cam, ray);
	return (0);
}

int		ray_cast(t_parse game)
{
	int		i;
	t_cam	cam;

	i = 0;
	while (i < game.res.w)
	{
		plane(&game, i, &cam);
	}
}
