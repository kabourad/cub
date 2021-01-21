/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:42:30 by awali-al          #+#    #+#             */
/*   Updated: 2021/01/21 16:20:53 by awali-al         ###   ########.fr       */
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

//fills.c

t_res		res_fill(char **array);
t_col		color_fill(char *str);
char		*path_fill(char *str);

//id_extra.c

int			is_id(char *c, int ids);

//id_parse.c

void		id_fill(int fd, t_parse *stru);

//map_check_extra.c

int			is_valid(char c);

//map_check.c

void		space_check(t_mapll *tmp, char *line, int i);
void		twod_check(t_mapll *tmp, char *line, int i, t_parse *stru);
void		check_last_line(t_mapll *ptr);

//map_parse.c

void		map_fill(int fd, t_parse *stru);

//parse_init.c

t_parse		stru_init(void);

//parsing.c

t_parse		parsing(char *path);

#endif
