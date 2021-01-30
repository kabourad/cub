#include "../../headers/cub.h"

static int	rgb(t_rgb color)
{
	int		ret;

	ret = (color.r << 16) | (color.g << 8) | color.b;
	return (ret);
}

void	rendering(t_cub *cub, int n)
{
	int		i;

	i = 0;
	while (i < cub->parse.res.h)
	{
		if (i < cub->cam.drawstart)
		{
			cub->image.data[i * cub->parse.res.w + n] = rgb(cub->parse.ceiling);
			// bmp_filling(cub, &cub->f);
		}
		if (i >= cub->cam.drawstart && i <= cub->cam.drawend)
		{
			if (cub->cam.side == 0)
				cub->image.data[i * cub->parse.res.w + n] = 0x666666;
			if (cub->cam.side == 1)
				cub->image.data[i * cub->parse.res.w + n] = 0x666666 / 4;
			if (cub->cam.side == 2)
				cub->image.data[i * cub->parse.res.w + n] = 0x666666 / 2;
			if (cub->cam.side == 3)
				cub->image.data[i * cub->parse.res.w + n] = 0x666666 * 3 / 4;
		}
			// wallrendering(cub);
		if (i > cub->cam.drawend)
		{
			cub->image.data[i * cub->parse.res.w + n] = rgb(cub->parse.floor);
			// bmp_filling(cub, &cub->c);
		}
		i++;
	}
}
