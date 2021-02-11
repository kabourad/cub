#include "../../headers/cub.h"

static void	check_assign(t_cub *cub, int n, char *path)
{
	if (!(cub->texture[n].img = mlx_xpm_file_to_image(cub->mlx, path,
			&(cub->texture[n].width), &cub->texture[n].height)))
		quit("Impossible to load a texture;\n", NULL);
	cub->texture[n].data = mlx_get_data_addr(cub->texture[n].img,
			&(cub->texture[n].bpp), &(cub->texture[n].size_line),
			&(cub->texture[n].endian));
}

void	texture_init(t_cub *cub)
{
	check_assign(cub, 0, cub->parse.paths.north);
	check_assign(cub, 1, cub->parse.paths.south);
	check_assign(cub, 2, cub->parse.paths.east);
	check_assign(cub, 3, cub->parse.paths.west);
	check_assign(cub, 4, cub->parse.paths.sprite);
}