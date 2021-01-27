#ifndef EXECUTION_H
# define EXECUTION_H

# include "structures.h"

# define PL_SZ		2
# define G_BS		50
# define MOV_SPD	0.2
# define ROT_SPD	0.12

/*
** movements.c
*/

void	move(t_cub *cub, t_vec pos, t_vec vec, double mov_spd);
void	rotate(t_cub *cub, double rot_spd);

/*
** key_manager.c
*/

int		key_close(t_cub *cub);
int		key_release(int keycode, t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		key_manager(t_cub *cub);

/*
** execution.c
*/


int		draw_grid(t_cub *milix);
void	execution(t_cub *cub);

#endif
