#ifndef CAMERA_H
# define CAMERA_H

#include "struct.h"

typedef	struct	s_cam
{
	t_vec sidedist;
	t_vec deltadist;
	double perpwalldist;
	int stepX;
    int stepY;
	int	mapX;
	int	mapY;
	int hit;
	int side;

}				t_cam;

#endif
