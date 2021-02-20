#include "../../headers/cub.h"

void		ft_trace(t_cub *cub)
{
	int		i;

	cub->image.img = mlx_new_image(cub->mlx, cub->parse.res.w,
			cub->parse.res.h);
	cub->image.data = mlx_get_data_addr(cub->image.img,
		&cub->image.bpp, &cub->image.size_line, &cub->image.endian);
	cub->cam.z_buff = (double*)malloc(sizeof(double) * cub->parse.res.w);
	i = 0;
	while (i < cub->parse.res.w)
	{
		delta(cub, i);
		side_distance(cub);
		dda(cub);
		wall(cub);
		cub->cam.z_buff[i] = cub->cam.pwd;
		rendering(cub, i);
		i++;
	}
	cub->parse.spr_num ? sprites(cub) : 0;
	cub->save ? save(cub) : mlx_put_image_to_window(cub->mlx, cub->mlx_win,
			cub->image.img, 0, 0);
	cub->cam.z_buff ? free(cub->cam.z_buff) : 0;
}

static int	main_cast(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image.img);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	mv_manager(cub);
	ft_trace(cub);
	return (0);
}

int			ray_casting(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, cub->parse.res.w, cub->parse.res.h,
			"CUB3D");
	texture_init(cub);
	ft_trace(cub);
	mlx_hook(cub->mlx_win, 2, 0, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 0, key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, key_close, cub);
	mlx_loop_hook(cub->mlx, main_cast, cub);
	mlx_loop(cub->mlx);
	return (0);
}
