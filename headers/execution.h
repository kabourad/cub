#ifndef EXECUTION_H
# define EXECUTION_H

# include "structures.h"

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

void	execution(t_cub *cub);

#endif
