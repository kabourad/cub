#include "../../headers/cub.h"

int		player_disp(t_milix *milix)
{
	t_vec	pos;
	t_vec	dir;
	t_res	res;
	int		i;
	int		j;

	pos = milix->game.player.pos;
	dir = milix->game.player.dir;
	res = milix->game.res;
	i = -PLAYER_SIZE;
	while (i <= PLAYER_SIZE)
	{
		j = -PLAYER_SIZE;
		while (j <= PLAYER_SIZE)
		{
			milix->image->data[(int)((pos.y * G_BS + i) * res.w + pos.x * G_BS +
					j)] = 0xFF0000;
			milix->image->data[(int)(((dir.y + pos.y) * G_BS + i) * res.w +
					(dir.x + pos.x) * G_BS + j)] = 0xFF00FF;
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

int		draw_grid(t_milix *milix)
{
	int		i;
	int		j;

	i = 0;
	while (i < milix->game.res.h + 25 && milix->game.map[(int)i / G_BS])
	{
		j = 0;
		while (j < milix->game.res.w + 25 && milix->game.map[(int)i / G_BS][(int)(j / G_BS)])
		{
			if (border(i, j) && milix->game.map[i / G_BS][j / G_BS] != ' ')
				milix->image->data[(i * milix->game.res.w) + j] = 0x444444;
				// mlx_pixel_put(milix->mlx, milix->mlx_win, j, i, 0x444444);
			if (border(i, j) && milix->game.map[(int)i / G_BS][(int)(j / G_BS)] && milix->game.map[(int)i / G_BS][(int)(j / G_BS)] == '1')
				milix->image->data[(i * milix->game.res.w) + j] = 0xFFFFFF;
				// mlx_pixel_put(milix->mlx, milix->mlx_win, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	player_disp(milix);
	mlx_put_image_to_window(milix->mlx, milix->mlx_win, milix->image->img, 0, 0);
	if (milix->keyboard[53])
		key_close(milix);
	return (0);
}
