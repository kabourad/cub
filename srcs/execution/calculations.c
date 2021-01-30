#include "../../headers/cub.h"

void	delta(t_cub *cub, int i)
{

	cub->cam.hit = 0;
	cub->cam.camera = 2 * i / (double)cub->parse.res.w - 1;
	cub->cam.ray.x = cub->parse.player.dir.x + cub->parse.player.pln.x
			* cub->cam.camera;
	cub->cam.ray.y = cub->parse.player.dir.y + cub->parse.player.pln.y
			* cub->cam.camera;
	cub->cam.map.x = (int)cub->parse.player.pos.x;
	cub->cam.map.y = (int)cub->parse.player.pos.y;
	cub->cam.deltadist.x = sqrt(1 + pow(cub->cam.ray.y, 2)
			/ pow(cub->cam.ray.x, 2));
	cub->cam.deltadist.y = sqrt(1 + pow(cub->cam.ray.x, 2)
			/ pow(cub->cam.ray.y, 2));
	if (cub->cam.ray.y == 0)
		cub->cam.deltadist.x = 0;
	else
		cub->cam.deltadist.x = (cub->cam.ray.x == 0) ? 1 : cub->cam.deltadist.x;
	if (cub->cam.ray.x == 0)
		cub->cam.deltadist.y = 0;
	else
		cub->cam.deltadist.y = (cub->cam.ray.y == 0) ? 1 : cub->cam.deltadist.y;
}

void	side_distance(t_cub *cub)
{
	if (cub->cam.ray.x < 0)
	{
		cub->cam.step.x = -1;
		cub->cam.sidedist.x = (cub->parse.player.pos.x - cub->cam.map.x)
				* cub->cam.deltadist.x;
	}
	else
	{
		cub->cam.step.x = 1;
		cub->cam.sidedist.x = (cub->cam.map.x + 1.0 - cub->parse.player.pos.x)
				* cub->cam.deltadist.x;
	}
	if (cub->cam.ray.y < 0)
	{
		cub->cam.step.y = -1;
		cub->cam.sidedist.y = (cub->parse.player.pos.y - cub->cam.map.y)
				* cub->cam.deltadist.y;
	}
	else
	{
		cub->cam.step.y = 1;
		cub->cam.sidedist.y = (cub->cam.map.y + 1.0 - cub->parse.player.pos.y)
				* cub->cam.deltadist.y;
	}
}

void	dda(t_cub *cub)
{
	while (cub->cam.hit == 0)
	{
		if (cub->cam.sidedist.x < cub->cam.sidedist.y)
		{
			cub->cam.sidedist.x += cub->cam.deltadist.x;
			cub->cam.map.x += cub->cam.step.x;
			cub->cam.side = 0;
		}
		else
		{
			cub->cam.sidedist.y += cub->cam.deltadist.y;
			cub->cam.map.y += cub->cam.step.y;
			cub->cam.side = 3;
		}
		if (cub->cam.side == 0 && cub->cam.ray.x > 0)
			cub->cam.side = 2;
		else if (cub->cam.side == 3 && cub->cam.ray.y < 0)
			cub->cam.side = 1;
		if (cub->parse.map[cub->cam.map.y][cub->cam.map.x] == '1')
		// printf("[%d][%d]\n", cub->cam.map.y, cub->cam.map.x);
		// if (!is_valid(cub->parse.map[cub->cam.map.y][cub->cam.map.x]))
			cub->cam.hit = 1;
		// printf("No segfault behind\n");
	}
}

void	wall(t_cub *cub)
{
	if (cub->cam.side == 0 || cub->cam.side == 2)
		cub->cam.perpwalldist = (cub->cam.map.x - cub->parse.player.pos.x
				+ (1 - cub->cam.step.x) / 2) / cub->cam.ray.x;
	else
		cub->cam.perpwalldist = (cub->cam.map.y - cub->parse.player.pos.y
				+ (1 - cub->cam.step.y) / 2) / cub->cam.ray.y;
	cub->cam.lineheight = (int)(cub->parse.res.h / cub->cam.perpwalldist);
	cub->cam.drawstart = (-cub->cam.lineheight / 2) + (cub->parse.res.h / 2);
	if (cub->cam.drawstart < 0)
		cub->cam.drawstart = 0;
	cub->cam.drawend = cub->cam.lineheight / 2 + (cub->parse.res.h / 2);
	if (cub->cam.drawend >= cub->parse.res.h)
		cub->cam.drawend = cub->parse.res.h - 1;
	// if (cub->side == 0 || cub->side == 2)
	// 	cub->wallx = cub->posy + cub->perpwalldist * cub->raydiry;
	// else
	// 	cub->wallx = cub->posx + cub->perpwalldist * cub->raydirx;
	// cub->wallx -= floor((cub->wallx));
	// cub->tex_x = (int)(cub->wallx * (double)(cub->texwidth));//later
	// if (cub->side == 0 && cub->raydirx > 0)
	// 	cub->tex_x = cub->texwidth - cub->tex_x - 1;
	// if (cub->side == 1 && cub->raydiry < 0)
	// 	cub->tex_x = cub->texwidth - cub->tex_x - 1;
	// cub->step = 1.0 * cub->texheight / cub->lineheight;//later
}
