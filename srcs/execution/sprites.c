#include "../../headers/cub.h"

void	sprites(t_cub *cub)
{
	t_vec	ppos;
	t_bin	spos;
	int		i;

	i = 0;
	ppos = cub->parse.ply.pos;
	spos = cub->parse.sprites[i].pos;
	while (i < cub->parse.spr_num)
	{
		cub->parse.sprites[i].dis = ((ppos.x - spos.x) * (ppos.x - spos.x) +
				(ppos.y - spos.y) * (ppos.y - spos.y));
		i++;
	}
	sortSprites(spriteOrder, spriteDistance, numSprites);
}