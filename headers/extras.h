/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:47:57 by awali-al          #+#    #+#             */
/*   Updated: 2021/02/18 00:48:14 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# include "structures.h"

void		ft_strdel(char **as);
int			ft_arrlen(char **arr);
void		ft_arrdel(char ***arr);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_listlen(t_mapll *map);
char		**ft_split_whitespaces(char const *s);
void		quit(char *msg, char *path, t_cub *cub);

#endif
