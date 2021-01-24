#include "../../headers/cub.h"

int		milix_loop(t_milix milix, t_parse *game)
{
	return (0);
}

t_milix	milix_init(t_parse game)
{
	t_milix	ret;

	ret.mlx = mlx_init();
	ret.mlx_win = mlx_new_window(ret.mlx, game.res.w, game.res.h, "Hi!");
	return (ret);
}
