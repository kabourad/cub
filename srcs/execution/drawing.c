#include "../../headers/cub.h"

static int	rgb(t_rgb color)
{
	int		ret;

	ret = (color.r << 16) | (color.g << 8) | color.b;
	return (ret);
}

void		pixel_fill(t_cub *cub, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	cub->image.data[y * cub->image.size_line + x * cub->image.bpp / 8] = r;
	cub->image.data[y * cub->image.size_line + x * cub->image.bpp / 8 + 1] = g;
	cub->image.data[y * cub->image.size_line + x * cub->image.bpp / 8 + 2] = b;
}

void	wall_rendering(t_cub *cub, int x, int y, int n)
{
	int		d;

	d = y * cub->texture[n].size_line - cub->parse.res.h *
			cub->texture[n].size_line / 2 + cub->cam.lineheight *
			cub->texture[n].size_line / 2;
	cub->cam.texture.y = ((d * cub->texture[n].height) / cub->cam.lineheight)
		/ cub->texture[n].size_line;
	cub->image.data[y * cub->image.size_line + x * cub->image.bpp / 8] =
		cub->texture[n].data[cub->cam.texture.y * cub->texture[n].size_line
		+ cub->cam.texture.x * (cub->texture[n].bpp / 8)];
	cub->image.data[y * cub->image.size_line + x * cub->image.bpp / 8 + 1] =
		cub->texture[n].data[cub->cam.texture.y * cub->texture[n].size_line
		+ cub->cam.texture.x * (cub->texture[n].bpp / 8) + 1];
	cub->image.data[y * cub->image.size_line + x * cub->image.bpp / 8 + 2] =
		cub->texture[n].data[cub->cam.texture.y * cub->texture[n].size_line
		+ cub->cam.texture.x * (cub->texture[n].bpp / 8) + 2];
}

void	rendering(t_cub *cub, int n)
{
	int		i;

	i = 0;
	cub->cam.texpos = (cub->cam.drawstart - cub->parse.res.h / 2 +
			cub->cam.lineheight / 2) * cub->cam.texstep;
	while (i < cub->parse.res.h)
	{
		if (i < cub->cam.drawstart)
			pixel_fill(cub, n, i, rgb(cub->parse.ceiling));
		if (i >= cub->cam.drawstart && i <= cub->cam.drawend)
		{
			if (cub->cam.side == 0)
				wall_rendering(cub, n, i, 2);
			else if (cub->cam.side == 1)
				wall_rendering(cub, n, i, 3);
			else if (cub->cam.side == 2)
				wall_rendering(cub, n, i, 0);
			else if (cub->cam.side == 3)
				wall_rendering(cub, n, i, 1);
		}
		if (i > cub->cam.drawend)
			pixel_fill(cub, n, i, rgb(cub->parse.floor));
		i++;
	}
}
