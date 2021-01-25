#include "../../headers/cub.h"

void	milix_init(t_cub *cub)
{
	t_cub	ret;
	int		i;

	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, cub->parse.res.w, cub->parse.res.h,
			"Cub3D");
	cub->image = (t_img*)malloc(sizeof(t_img));
	cub->image->img = mlx_new_image(cub->mlx, cub->parse.res.w,
			cub->parse.res.h);
	cub->image->data = (int *)mlx_get_data_addr(cub->image->img,
			&cub->image->bpp, &cub->image->size_line, &ret.image->endian);
	cub->keys.w_k = 0;
	cub->keys.a_k = 0;
	cub->keys.s_k = 0;
	cub->keys.d_k = 0;
	cub->keys.l_k = 0;
	cub->keys.r_k = 0;
	cub->keys.esc = 0;
}
