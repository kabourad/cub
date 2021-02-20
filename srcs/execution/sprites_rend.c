/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_rend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:51:49 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/20 16:51:50 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

static void	text_put(t_cub *cub, t_sprite sprite, t_bin iter)
{
	int		index;
	int		index_sprite;

	index = iter.y * cub->image.size_line
	+ iter.x * cub->image.bpp / 8;
	index_sprite = sprite.txt.y * cub->text[4].size_line + sprite.txt.x
	* cub->text[4].bpp / 8;
	cub->image.data[index] = cub->text[4].data[index_sprite];
	cub->image.data[index + 1] =
	cub->text[4].data[index_sprite + 1];
	cub->image.data[index + 2] =
	cub->text[4].data[index_sprite + 2];
}

static void	sprite_disp(t_cub *cub, t_sprite sprite, t_bin iter, t_res res)
{
	int		d;
	int		color;
	int		index;

	d = iter.y * cub->text[4].size_line - res.h * cub->text[4].size_line /
			2 + sprite.dim * cub->text[4].size_line / 2;
	sprite.txt.y = (int)(d * TEX_HEI / sprite.dim / cub->text[4].size_line);
	index = sprite.txt.y * cub->text[4].size_line + sprite.txt.x *
			cub->text[4].bpp / 8;
	color = cub->text[4].data[index] + cub->text[4].data[index + 1] +
		cub->text[4].data[index + 2];
	if (color != 0)
		text_put(cub, sprite, iter);
}

void		sprite_render(t_cub *cub, int i)
{
	t_bin	iter;

	iter.x = cub->parse.sprites[i].d_s.x;
	while (iter.x < cub->parse.sprites[i].d_e.x)
	{
		if (cub->parse.sprites[i].trans.y > 0 && iter.x > 0 && iter.x <
				cub->parse.res.w && cub->parse.sprites[i].trans.y <
				cub->cam.z_buff[iter.x])
		{
			iter.y = cub->parse.sprites[i].d_s.y;
			cub->parse.sprites[i].txt.x = (int)(cub->text[4].size_line
			* (iter.x - (-cub->parse.sprites[i].dim / 2 +
			cub->parse.sprites[i].scr_x)) * TEX_WID / cub->parse.sprites[i].dim)
			/ cub->text[4].size_line;
			while (iter.y < cub->parse.sprites[i].d_e.y)
			{
				sprite_disp(cub, cub->parse.sprites[i], iter, cub->parse.res);
				iter.y++;
			}
		}
		iter.x++;
	}
}
