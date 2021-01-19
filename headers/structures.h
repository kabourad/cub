/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:39:43 by awali-al          #+#    #+#             */
/*   Updated: 2021/01/19 16:42:38 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_res
{
	int				width;
	int				height;
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

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

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
	t_res			resolution;
	t_path			paths;
	t_col			floor;
	t_col			ceiling;
	t_player		player;
	char			**map;
}					t_parse;

typedef struct		s_mapll
{
	char			*line;
	int				i;
	struct s_mapll	*next;
}					t_mapll;

#endif
