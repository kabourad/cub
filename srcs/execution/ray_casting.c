#include "../../headers/cub.h"

static void	ft_trace(t_cub *cub)
{
	int	i;

	i = 0;
	cub->image.img = mlx_new_image(cub->mlx, cub->parse.res.w, cub->parse.res.h);
	cub->image.data = (int *)mlx_get_data_addr(cub->image.img,
		&cub->image.bpp, &cub->image.size_line, &cub->image.endian);
	while (i < cub->parse.res.w)
	{
		delta(cub, i);
		side_distance(cub);
		dda(cub);
		wall(cub);
		rendering(cub, i);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
}

static int	main_cast(t_cub *cub)
{
	// mlx_destroy_image(cub->mlx, cub->image.img);
	// mlx_clear_window(cub->mlx, cub->mlx_win);
	// if (cub->mlx_win)
	// 	mlx_destroy_window(cub->mlx, cub->mlx_win);
	// if (cub->image.img)
	// 	mlx_destroy_image(cub->mlx, cub->image.img);
	mv_manager(cub);
	ft_trace(cub);
	return(0);
}

static t_keys	keys_init(void)
{
	t_keys	ret;

	ret.esc = 0;
	ret.w_k = 0;
	ret.a_k = 0;
	ret.s_k = 0;
	ret.d_k = 0;
	ret.l_k = 0;
	ret.r_k = 0;
	return (ret);
}

int			ray_casting(t_cub *cub)
{
	t_cam	cam;

	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, cub->parse.res.w, cub->parse.res.h,
			"CUB3D");
	cub->keys = keys_init();
	ft_trace(cub);
	mlx_hook(cub->mlx_win, 2, 0, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 0, key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, key_close, cub);
	mlx_loop_hook(cub->mlx, main_cast, cub);
	mlx_loop(cub->mlx);
	return (0);
}