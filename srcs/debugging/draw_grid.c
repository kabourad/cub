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
					0xFFFFFF);
			j++;
		}
		i++;
	}
	return (0);
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
	while (i < game.res.height)
	{
		j = 0;
		while (j < game.res.width)
		{
			if (!(i % G_BS) || !(j % G_BS))
				mlx_pixel_put(mlx, mlx_win, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}
	player_disp(game.player.pos, mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}
