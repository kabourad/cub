/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:47:44 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/19 16:35:39 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

t_parse			parsing(char *path)
{
	int			fd;
	t_parse		ret;

	ret = stru_init();
	if ((fd = open(path, O_RDONLY)) == -1)
		quit("Opening file failed.", NULL);
	id_fill(fd, &ret);
	map_fill(fd, &ret);
	return (ret);
}
