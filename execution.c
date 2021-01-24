#include "headers/cub.h"

void	execution(t_parse game)
{
	t_milix		milix;

	milix = milix_init(game);
	draw_grid(game, milix);
	mlx_loop(milix.mlx);
}