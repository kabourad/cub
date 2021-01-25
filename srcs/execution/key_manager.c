#include "../../headers/cub.h"

int	key_press(int keycode, t_cub *cub)
{
	printf("%d\n", keycode);
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

int	key_manager(t_cub *cub)
{
	t_vec	pos;

	pos = cub->parse.player.pos;
	if (cub->keys.a_k)
		cub->parse.player.pos.x -= 0.2;
	if (cub->keys.d_k && is_valid(cub->parse.map[(int)pos.y][(int)(pos.x)])) // changes here
		cub->parse.player.pos.x += 0.2;
	if (cub->keys.w_k)
		cub->parse.player.pos.y -= 0.2;
	if (cub->keys.s_k && is_valid(cub->parse.map[(int)pos.y][(int)pos.x])) // changes here
		cub->parse.player.pos.y += 0.2;
	if (cub->keys.esc)
		key_close(cub);
	return (0);
}
