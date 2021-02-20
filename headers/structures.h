/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:39:43 by awali-al          #+#    #+#             */
/*   Updated: 2021/02/20 11:57:51 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_res
{
	int				w;
	int				h;
}					t_res;

typedef struct		s_bin
{
	int				x;
	int				y;
}					t_bin;

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

typedef struct		s_sprite
{
	t_vec			trans;
	t_vec			pos;
	t_bin			d_s;
	t_bin			d_e;
	t_bin			txt;
	double			dis;
	int				dim;
	int				order;
	int				scr_x;
}					t_sprite;

/*
** Parse structure
*/

typedef struct		s_parse
{
	int				ids;
	int				spr_num;
	t_res			res;
	t_path			paths;
	t_rgb			floor;
	t_rgb			ceiling;
	t_player		ply;
	t_sprite		*sprites;
	char			**map;
}					t_parse;

typedef struct		s_mapll
{
	char			*line;
	int				i;
	int				n;
	struct s_mapll	*next;
}					t_mapll;

/*
** Image structure
*/

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

/*
** Camera structure
*/

typedef	struct		s_cam
{
	t_vec			sidedist;
	t_vec			deltadist;
	t_vec			ray;
	t_bin			step;
	t_bin			map;
	t_bin			texture;
	double			camera;
	double			pwd;
	double			wallx;
	double			texstep;
	double			texpos;
	double			*z_buff;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_cam;

/*
** Cub structure
*/

typedef struct		s_cub
{
	int				save;
	void			*mlx;
	void			*mlx_win;
	t_keys			keys;
	t_img			image;
	t_text			text[5];
	t_cam			cam;
	t_parse			parse;
}					t_cub;

/*
** Bmp structures
*/

# define HEADER_SIZE 54

typedef	struct		s_bitmap_file
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bitmap_file;

typedef	struct		s_bitmap_image
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bitmap_image;


#endif
