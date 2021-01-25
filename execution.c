#include "headers/cub.h"

int     key_press(int keycode, t_milix *data)
{
    
	data->keyboard[keycode] = 1;
	return (0);
}

int     key_release(int keycode, t_milix *data)
{
    
	data->keyboard[keycode] = 0;
	return (0);
}

int		key_close(t_milix *cub)
{
	mlx_clear_window(cub->mlx, cub->mlx_win);
	ft_putstr_fd("END OF GAME!\n", 2);
	exit(0);
	return (0);
}

void	execution(t_parse game)
{
	t_milix		milix;
	t_img		*img;

	milix = milix_init(game);
	mlx_hook(milix.mlx_win, 2, 0, key_press , &milix);
    mlx_hook(milix.mlx_win, 3, 0, key_release , &milix);
    mlx_hook(milix.mlx_win, 17, 0, key_close , &milix);
	mlx_loop_hook(milix.mlx, draw_grid, &milix);
	mlx_loop(milix.mlx);
}