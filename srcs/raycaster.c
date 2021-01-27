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
	cam->mapX = int(game.player.pos.x);
    cam->mapY = int(game.player.pos.y);
	if(ray.x < 0)
      {
        stepX = -1;
        sideDist.x = ((int)(game.player.pos.x) - cam->mapX) * deltadist.x;
      }
      else
      {
        stepX = 1;
        sideDistX = (cam->mapX + 1.0 - game.player.pos.x) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (game.player.pos.y - cam->mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (cam->mapY + 1.0 - game.player.pos.y) * deltaDistY;
      }
	  
}

int		plane(t_parse *game, int i, t_cam *cam)
{
	t_vec	ray;
	double	camx;

	camx = 2 * i / game->res.w - 1;
	ray.x = game->player.dir.x + game->player.pln.x * camx;
	ray.y = game->player.dir.y + game->player.pln.y * camx;
	cam->deltadist.x = (ray.x == 0) ? 0 : ((ray.x == 0) ? 1 : abs(1 / ray.x));
	cam->deltadist.y = (ray.y == 0) ? 0 : ((ray.y == 0) ? 1 : abs(1 / ray.y));
	ray(game, cam, ray);
	return(0);
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
