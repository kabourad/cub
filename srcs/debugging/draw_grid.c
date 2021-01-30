#include "../../headers/cub.h"

int		player_disp(t_cub *cub)
{
	t_vec	pos;
	t_vec	dir;
	t_vec	dot;
	t_res	res;
	int		i;
	int		j;

	pos = cub->parse.player.pos;
	dir = cub->parse.player.dir;
	dot.x = dir.x + pos.x;
	dot.y = dir.y + pos.y;
	res = cub->parse.res;
	printf("pos(%f, %f), dir(%f, %f), dot(%f, %f)\n", pos.x, pos.y, dir.x, dir.y, dot.x, dot.y);
	i = -PL_SZ;
	while (i <= PL_SZ)
	{
		j = -PL_SZ;
		while (j <= PL_SZ)
		{
			cub->image.data[(int)((pos.y * G_BS + i) * res.w + pos.x * G_BS +
					j)] = 0xFF0000;
			cub->image.data[(int)((dot.y * G_BS + i) * res.w + dot.x * G_BS +
					j)] = 0xFF00FF;
			j++;
		}
		i++;
	}
	return (0);
}

int		border(int i, int j)
{
	if (i % G_BS == 0 || j % G_BS == 0)
		return (0);
	else
		return (1);
}

void	reset(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < cub->parse.res.w * cub->parse.res.h)
		cub->image.data[i++] = 0x0;
}

int		draw_grid(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	reset(cub);
	while (i < cub->parse.res.h && cub->parse.map[(int)i / G_BS])
	{
		j = 0;
		while (j < cub->parse.res.w && cub->parse.map[(int)i / G_BS]
				[(int)(j / G_BS)])
		{
			if (border(i, j) && cub->parse.map[i / G_BS][j / G_BS] != ' ')
				cub->image.data[(i * cub->parse.res.w) + j] = 0x444444;
			if (border(i, j) && cub->parse.map[(int)i / G_BS][(int)(j / G_BS)]
					&& cub->parse.map[(int)i / G_BS][(int)(j / G_BS)] == '1')
				cub->image.data[(i * cub->parse.res.w) + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
	player_disp(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
	return (0);
}
