#include "../../headers/cub.h"

int	key_press(int keycode, t_cub *cub)
{
	// printf("%d\n", keycode);
	if (keycode == 53)
		cub->keys.esc = 1;
	else if (keycode == 13)
		cub->keys.w_k = 1;
	else if (keycode == 0)
		cub->keys.a_k = 1;
	else if (keycode == 1)
		cub->keys.s_k = 1;
	else if (keycode == 2)
		cub->keys.d_k = 1;
	else if (keycode == 123)
		cub->keys.l_k = 1;
	else if (keycode == 124)
		cub->keys.r_k = 1;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 53)
		cub->keys.esc = 0;
	else if (keycode == 13)
		cub->keys.w_k = 0;
	else if (keycode == 0)
		cub->keys.a_k = 0;
	else if (keycode == 1)
		cub->keys.s_k = 0;
	else if (keycode == 2)
		cub->keys.d_k = 0;
	else if (keycode == 123)
		cub->keys.l_k = 0;
	else if (keycode == 124)
		cub->keys.r_k = 0;
	return (0);
}

int	key_close(t_cub *cub)
{
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	if (cub->image->img)
		mlx_destroy_image(cub->mlx, cub->image->img);
	exit(0);
	return (0);
}

static void	rotate(t_cub *cub, double rot_spd)
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

int	key_manager(t_cub *cub)
{
	t_vec	pos;

	pos = cub->parse.player.pos;
	if (cub->keys.a_k && pos.x && is_valid(cub->parse.map[(int)pos.y][(int)(pos.x - 0.25)]))
		cub->parse.player.pos.x -= 0.2;
	if (cub->keys.d_k && is_valid(cub->parse.map[(int)pos.y][(int)(pos.x + 0.25)])) // changes here
		cub->parse.player.pos.x += 0.2;
	if (cub->keys.w_k && pos.y && is_valid(cub->parse.map[(int)(pos.y - 0.25)][(int)pos.x]))
		cub->parse.player.pos.y -= 0.2;
	if (cub->keys.s_k && is_valid(cub->parse.map[(int)(pos.y + 0.25)][(int)pos.x])) // changes here
		cub->parse.player.pos.y += 0.2;
	if (cub->keys.esc)
		key_close(cub);
	if (cub->keys.l_k)
		rotate(cub, (M_PI / 180) * -RT_SP);
	if (cub->keys.r_k)
		rotate(cub, (M_PI / 180) * RT_SP);
	return (0);
}
