#include "../../headers/cub.h"

int		player_disp(t_vec pos, void *mlx, void *mlx_win)
{
	int		i;
	int		j;

	i = -PLAYER_SIZE;
	while (i <= PLAYER_SIZE)
	{
		j = -PLAYER_SIZE;
		while (j <= PLAYER_SIZE)
		{
			mlx_pixel_put(mlx, mlx_win, pos.x * G_BS + j, pos.y * G_BS + i,
					0x00FF0000);
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

int		draw_grid(t_parse game)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, game.res.width, game.res.height, "Hi!");
	i = 0;
	while (i < game.res.height + 25 && game.map[(int)i / G_BS])
	{
		j = 0;
		while (j < game.res.width + 25 && game.map[(int)i / G_BS][(int)(j / G_BS)])
		{
			// printf("%c\n", game.map[(int)i / G_BS][(int)(j / G_BS)]);
			if (border(i, j) && game.map[i / G_BS][j / G_BS] != ' ')
				mlx_pixel_put(mlx, mlx_win, j, i, 0x444444);
			if (border(i, j) && game.map[(int)i / G_BS][(int)(j / G_BS)] && game.map[(int)i / G_BS][(int)(j / G_BS)] == '1')
				mlx_pixel_put(mlx, mlx_win, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	player_disp(game.player.pos, mlx, mlx_win);
	// mlx_loop_hook(mlx, rendering)
	mlx_loop(mlx);
	return (0);
}
