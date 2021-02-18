/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:58:02 by awali-al          #+#    #+#             */
/*   Updated: 2021/01/17 19:25:31 by awali-al         ###   ########.fr       */
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
