/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:05:33 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/14 17:23:08 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/*
** Defines
*/

# define R_ID		1
# define S_ID		2
# define C_ID		4
# define F_ID		8
# define NO_ID		16
# define SO_ID		32
# define WE_ID		64
# define EA_ID		128
# define MP_ID		256
# define PL_ID		512

/*
** includes
*/

# include "../libft/libft.h"
# include <fcntl.h>
// # include "mlx.h"

/*
** structures
*/

typedef struct  s_bi
{
    double      x;
    double      y;
}               t_bi;

typedef struct  s_ori
{
    char		*no;
    char		*so;
    char		*ea;
    char		*we;
}               t_ori;

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
}				t_col;

typedef struct 	s_player
{
	t_bi		pos;
	t_bi		dir;
}				t_player;

typedef struct		s_mapll
{
	char			*line;
	int				i;
	struct s_mapll	*next;
}					t_mapll;


typedef struct  s_parse
{
    t_bi		resolution;
    t_ori		orientation;
	char		*sprite;
	t_col		floor;
	t_col		ceiling;
	t_player	player;
	int			ids;
	t_mapll		*map;
}               t_parse;

typedef struct	s_ingame
{
	t_player	player;
	char		**map;
}				t_ingame;

/*
** prototypes
*/

// extras.c

void	ft_strdel(char **as);
int     ft_arrlen(char **arr);
void    ft_arrdel(char ***arr);
int		ft_strcmp(const char *s1, const char *s2);
void	put_and_quit(char *msg);

//fills.c

t_bi	resolution_fill(char **array);
t_col	color_fill(char *str);
char	*path_fill(char *str);

//game_init.c

t_parse	game_init(char *path);

//id_extra.c

int		is_id(char *c, int ids);

//id_parse.c

void	id_fill(int fd, t_parse *stru);

//map_check

void	space_check(t_mapll *tmp, char *line, int i);
int		is_valid(char c);
void	twod_check(t_mapll *tmp, char *line, int i, t_parse *stru);
void	check_last_line(t_mapll *ptr);

void	map_fill(int fd, t_parse *stru);

//split whitespaces
char	**ft_split_whitespaces(char const *s);

//main.c

void	ft_extention(char *path, char *ext);

#endif
