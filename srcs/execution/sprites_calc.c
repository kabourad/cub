#include "../../headers/cub.h"

static t_vec	transform(t_cub *cub, int i)
{
	double		inv_det;
	t_vec		spr;
	t_vec		ret;
	t_vec		dir;
	t_vec		pln;

	dir = cub->parse.ply.dir;
	pln = cub->parse.ply.pln;
	spr.x = cub->parse.sprites[i].pos.x - cub->parse.ply.pos.x;
	spr.y = cub->parse.sprites[i].pos.y - cub->parse.ply.pos.y;
	inv_det = 1.0 / (pln.x * dir.y - pln.y * dir.x);
	ret.x = inv_det * (dir.y * spr.x - dir.x * spr.y);
	ret.y = inv_det * (pln.x * spr.y - pln.y * spr.x);
	return (ret);
}

static t_bin	tips(int dim, int ssx, int w, int h)
{
	t_bin	ret;

	ret.y = dim / 2 + h / 2;
	ret.x = dim / 2 + ssx;
	if (w)
	{
		ret.x = ret.x >= w ? w - 1 : ret.x;
		ret.y = ret.y >= h ? h - 1 : ret.y;
	}
	else
	{
		ret.x = ret.x < 0 ? 0 : ret.x;
		ret.y = ret.y < 0 ? 0 : ret.y;
	}
	return (ret);
}

static void		sprite_sort(t_cub *cub)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while ( i < cub->parse.spr_num)
	{
		j = i + 1;
		while (j < cub->parse.spr_num)
		{
			if (cub->parse.sprites[i].trans.y < cub->parse.sprites[j].trans.y)
			{
				tmp = cub->parse.sprites[i];
				cub->parse.sprites[i] = cub->parse.sprites[j];
				cub->parse.sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			sprites(t_cub *cub)
{
	int			i;

	i = 0;
	while (i < cub->parse.spr_num)
	{
		cub->parse.sprites[i].trans = transform(cub, i);
		i++;
	}
	sprite_sort(cub);
	i = 0;
	while (i < cub->parse.spr_num)
	{
		cub->parse.sprites[i].scr_x = (int)((cub->parse.res.w / 2) *
				(1 + cub->parse.sprites[i].trans.x /
				cub->parse.sprites[i].trans.y));
		cub->parse.sprites[i].dim = abs((int)(cub->parse.res.h /
				cub->parse.sprites[i].trans.y));
		cub->parse.sprites[i].d_s = tips(-cub->parse.sprites[i].dim,
				cub->parse.sprites[i].scr_x, 0, cub->parse.res.h);
		cub->parse.sprites[i].d_e = tips(cub->parse.sprites[i].dim,
				cub->parse.sprites[i].scr_x, cub->parse.res.w,
				cub->parse.res.h);
		sprite_render(cub, i);
		i++;
	}
}
