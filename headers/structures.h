/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:39:43 by awali-al          #+#    #+#             */
/*   Updated: 2021/02/02 18:01:14 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_res
{
	int				w;
	int				h;
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
	char			*data;
}					t_img;

typedef struct		s_text
{
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	void			*img;
	char			*data;
}					t_text;

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
	t_bin			texture;
	double			camera;
	double			perpwalldist;
	double			wallx;
	double			texstep;
	double			texpos;
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
	t_text			texture[4];
	t_cam			cam;
	t_parse			parse;
}					t_cub;

#endif
