#include "../../headers/cub.h"

void	sprite_put(t_cub *cub, t_sprite sprite, t_bin iter, t_res res)
{
	int	d;
	int	color;
	int	index;

	d = iter.y * cub->texture[4].size_line - res.h
	* cub->texture[4].size_line / 2 + sprite.dim
	* cub->texture[4].size_line / 2;
	sprite.txt.y = (int)(d * TEX_HEI / sprite.dim
	/ cub->texture[4].size_line);
	index = sprite.txt.y * cub->texture[4].size_line
	+ sprite.txt.x * cub->texture[4].bpp / 8;
	color = cub->texture[4].data[index]
	+ cub->texture[4].data[index + 1]
	+ cub->texture[4].data[index + 2];
	if (color != 0x000000)
		wall_rendering(cub, iter.x, iter.y, 4);
}

void	sprite_render(t_cub *cub, int i)
{
	t_bin	iter;

	iter.x = cub->parse.sprites[i].d_s.x;
	while (iter.x < cub->parse.sprites[i].d_e.x)
	{
		if (cub->parse.sprites[i].trans.y > 0 && iter.x > 0 && iter.x <
				cub->parse.res.w && cub->parse.sprites[i].trans.y <
				cub->cam.z_buff[iter.x])
		{
			iter.y = cub->parse.sprites[i].d_s.y;
			cub->parse.sprites[i].txt.x = (int)(cub->texture[4].size_line
			* (iter.x - (-cub->parse.sprites[i].dim / 2 +
			cub->parse.sprites[i].scr_x)) * TEX_WID / cub->parse.sprites[i].dim)
			/ cub->texture[4].size_line;
			while (iter.y < cub->parse.sprites[i].d_e.y)
			{
				sprite_put(cub, cub->parse.sprites[i], iter, cub->parse.res);
				iter.y++;
			}
		}
		iter.x++;
	}
}
