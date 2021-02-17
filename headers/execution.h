#ifndef EXECUTION_H
# define EXECUTION_H

# include "structures.h"

# define PL_SZ		2
# define G_BS		50
# define MOV_SPD	0.2
# define ROT_SPD	0.1
# define TEX_WID	64
# define TEX_HEI	64

/*
** calculations.c
*/

void	delta(t_cub *cub, int i);
void	side_distance(t_cub *cub);
void	dda(t_cub *cub);
void	wall(t_cub *cub);

/*
** drawing.c
*/

void	wall_rendering(t_cub *cub, int x, int y, int n);
void	rendering(t_cub *cub, int n);

/*
** key_manager.c
*/

int		key_close(t_cub *cub);
int		key_release(int keycode, t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		mv_manager(t_cub *cub);

/*
** movements.c
*/

void	move(t_cub *cub, t_vec pos, t_vec vec, double mov_spd);
void	rotate(t_cub *cub, double rot_spd);

/*
** ray_casting.c
*/

void	ft_trace(t_cub *cub);
int		ray_casting(t_cub *cub);

/*
** save.c
*/

void	save(t_cub *cub);

/*
** sprites_calc.c
*/

void	sprites(t_cub *cub);

/*
** sprites_rend.c
*/

void	sprite_render(t_cub *cub, int i);

/*
** textures.c
*/

void	texture_init(t_cub *cub);

#endif
