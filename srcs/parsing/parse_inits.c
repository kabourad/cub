#include "../../headers/cub.h"

static t_player	init_player(void)
{
	t_player	ret;

	ret.pos.x = 0;
	ret.pos.y = 0;
	ret.dir.x = 0;
	ret.dir.y = 0;
	ret.pln.x = 0;
	ret.pln.y = 0;
	return (ret);
}

static t_rgb	init_color(void)
{
	t_rgb		ret;

	ret.r = 0;
	ret.g = 0;
	ret.b = 0;
	return (ret);
}

static t_path	init_path(void)
{
	t_path		ret;

	ret.north = NULL;
	ret.south = NULL;
	ret.west = NULL;
	ret.east = NULL;
	ret.sprite = NULL;
	return (ret);
}

static t_res	init_res(void)
{
	t_res		ret;

	ret.w = 0;
	ret.h = 0;
	ret.sizex = 0;
	ret.sizey = 0;
	return (ret);
}

t_parse			stru_init(void)
{
	t_parse		stru;

	stru.ids = 0;
	stru.res = init_res();
	stru.paths = init_path();
	stru.floor = init_color();
	stru.ceiling = init_color();
	stru.player = init_player();
	stru.map = NULL;
	return (stru);
}
