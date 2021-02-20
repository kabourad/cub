/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:53:12 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/20 14:53:19 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

void		quit(char *msg, char *path, t_cub *cub)
{
	ft_putendl_fd("ERROR", 2);
	ft_putstr_fd(msg, 2);
	path ? ft_putendl_fd(path, 2) : ft_putendl_fd("", 2);
	clear_game(cub);
	exit(1);
}
