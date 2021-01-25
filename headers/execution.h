#ifndef EXECUTION_H
# define EXECUTION_H

# include "structures.h"

# define PL_SZ	4
# define G_BS	50
# define MV_SP	0.2
# define RT_SP	20

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
