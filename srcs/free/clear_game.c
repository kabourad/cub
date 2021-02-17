/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:45:39 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/17 16:14:02 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"


void	free_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->parse.map[i])
	{
		free(cub->parse.map[i]);
		i++;
	}
	free(cub->parse.map);
}

void	clear_game(t_cub *cub)
{
	free(cub->parse.paths.north);
	free(cub->parse.paths.south);
	free(cub->parse.paths.east);
	free(cub->parse.paths.west);
	free(cub->parse.paths.sprite);
	free(cub->parse.sprites);
	free_map(cub);
}