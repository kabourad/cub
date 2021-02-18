#include "../../headers/cub.h"

static void	check_assign(t_cub *cub, int n, char *path)
{
	if (!(cub->text[n].img = mlx_xpm_file_to_image(cub->mlx, path,
			&(cub->text[n].width), &cub->text[n].height)))
		quit("Impossible to load a texture;\n", NULL, cub);
	cub->text[n].data = mlx_get_data_addr(cub->text[n].img,
			&(cub->text[n].bpp), &(cub->text[n].size_line),
			&(cub->text[n].endian));
}

void		texture_init(t_cub *cub)
{
	check_assign(cub, 0, cub->parse.paths.north);
	check_assign(cub, 1, cub->parse.paths.south);
	check_assign(cub, 2, cub->parse.paths.east);
	check_assign(cub, 3, cub->parse.paths.west);
	check_assign(cub, 4, cub->parse.paths.sprite);
}
