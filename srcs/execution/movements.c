#include "../../headers/cub.h"

void	rotate(t_cub *cub, double rot_spd)
{
	t_vec	dir;
	t_vec	pln;

	dir = cub->parse.player.dir;
	pln = cub->parse.player.pln;
	cub->parse.player.dir.x = dir.x * cos(rot_spd) - dir.y * sin(rot_spd);
	cub->parse.player.dir.y = dir.x * sin(rot_spd) + dir.y * cos(rot_spd);
	cub->parse.player.pln.x = pln.x * cos(rot_spd) - pln.y * sin(rot_spd);
	cub->parse.player.pln.y = pln.x * sin(rot_spd) + pln.y * cos(rot_spd);
}

void	move(t_cub *cub, t_vec pos, t_vec vec, double mov_spd)
{
	if (is_valid(cub->parse.map[(int)pos.y][(int)(pos.x + vec.x * mov_spd)]))
		cub->parse.player.pos.x += vec.x * mov_spd;
	if (is_valid(cub->parse.map[(int)(pos.y + vec.y * mov_spd)][(int)pos.x]))
		cub->parse.player.pos.y += vec.y * mov_spd;
}
