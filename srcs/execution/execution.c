#include "../../headers/cub.h"

static int	big_loop(t_cub *cub)
{
	key_manager(cub);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	draw_grid(cub);
	return (0);
}

void		execution(t_cub *cub)
{
	milix_init(cub);
	draw_grid(cub);
	mlx_hook(cub->mlx_win, 2, 0, key_press , cub);
    mlx_hook(cub->mlx_win, 3, 0, key_release , cub);
    mlx_hook(cub->mlx_win, 17, 0, key_close , cub);
	mlx_loop_hook(cub->mlx, big_loop, cub);
	mlx_loop(cub->mlx);
}
