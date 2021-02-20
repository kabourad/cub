/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:42:30 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/20 16:52:49 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

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
**fills.c
*/

t_res		res_fill(char **array);
t_rgb		color_fill(char *str, t_cub *cub);
char		*path_fill(char *str, t_cub *cub);

/*
**id_extra.c
*/

int			is_id(char *c, int ids);

/*
**id_parse.c
*/

void		id_fill(int fd, t_cub *cub);

/*
**map_check_extra.c
*/

int			is_valid(char c);

/*
**map_check.c
*/

void		space_check(t_mapll *tmp, char *line, int i, t_cub *cub);
void		twod_check(t_mapll *tmp, char *line, int i, t_cub *cub);
int			check_end(t_mapll *tmp, int n);

/*
**map_parse.c
*/

void		map_fill(int fd, t_cub *cub);

/*
**parse_init.c
*/

t_parse		stru_init(void);

/*
** parsing.c
*/

void		parsing(char *path, t_cub *cub);

#endif
