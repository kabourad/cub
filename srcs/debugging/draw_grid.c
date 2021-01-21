#include "../../headers/cub.h"

int		draw_grid(t_parse game)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, game.res.width, game.res.height, "Hello world!");
	i = 0;
	while (i < game.res.height)
	{
		j = 0;
		while (j < game.res.width)
		{
			if (!(i % GRID_BLOCKSIZE) || !(j % GRID_BLOCKSIZE))
				mlx_pixel_put(mlx, mlx_win, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}
	return (0);
}
