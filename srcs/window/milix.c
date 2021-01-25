#include "../../headers/cub.h"



t_milix	milix_init(t_parse game)
{
	t_milix	ret;
	int		i;

	while (i < 300)
		ret.keyboard[i++] = 0;
	ret.mlx = mlx_init();
	ret.mlx_win = mlx_new_window(ret.mlx, game.res.w, game.res.h, "Cub3D");
	ret.image = (t_img*)malloc(sizeof(t_img));
	ret.image->img = mlx_new_image(ret.mlx, game.res.w, game.res.h);
	ret.image->data = (int *)mlx_get_data_addr(ret.image->img, &ret.image->bpp, &ret.image->size_line, &ret.image->endian);
	ret.game = game;
	return (ret);
}
