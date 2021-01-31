/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:39:43 by awali-al          #+#    #+#             */
/*   Updated: 2021/01/31 17:20:35 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_res
{
	int				w;
	int				h;
	int				sizex;
	int				sizey;
}					t_res;

typedef struct		s_path
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
}					t_path;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct		s_player
{
	t_vec			pos;
	t_vec			dir;
	t_vec			pln;
}					t_player;

typedef struct		s_parse
{
	int				ids;
	t_res			res;
	t_path			paths;
	t_rgb			floor;
	t_rgb			ceiling;
	t_player		player;
	char			**map;
}					t_parse;

typedef struct		s_mapll
{
	char			*line;
	int				i;
	struct s_mapll	*next;
}					t_mapll;

typedef struct		s_img
{
	int				bpp;
	int				size_line;
	int				endian;
	void			*img;
	int				*data;
}					t_img;

typedef struct		s_keys
{
	int				w_k;
	int				a_k;
	int				s_k;
	int				d_k;
	int				l_k;
	int				r_k;
	int				esc;
}					t_keys;

typedef struct		s_bin
{
	int				x;
	int				y;
}					t_bin;

typedef	struct		s_cam
{
	t_vec			sidedist;
	t_vec			deltadist;
	t_vec			ray;
	t_bin			step;
	t_bin			map;
	double			camera;
	double			perpwalldist;
	// double			wallx;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_cam;

typedef struct		s_cub
{
	void			*mlx;
	void			*mlx_win;
	t_keys			keys;
	t_img			image;
	t_cam			cam;
	t_parse			parse;
}					t_cub;

#endif
