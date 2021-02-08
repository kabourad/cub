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

// int		draw_grid(t_cub *milix);
int		ray_casting(t_cub *cub);

/*
** sprites.c
*/

void	sprites(t_cub *cub);

/*
** textures.c
*/

void	texture_init(t_cub *cub);

#endif
