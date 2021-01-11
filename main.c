/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:04:43 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/11 18:47:05 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

static int		ft_usage(void)
{
	ft_putstr_fd("Error\nusage: ./cub3d *.cub [--save]\n", 2);
	return (1);
}

void		ft_extention(char *path, char *ext)
{
	int			n;
	int			m;

	n = ft_strlen(path);
	m = ft_strlen(ext);
	if (ft_strcmp(path + n - m, ext))
		put_and_quit("Error\nwrong extention");
}

int			main(int argc, char ** argv)
{
	t_parse	    game;

	if (argc < 2 || argc > 3)
		return (ft_usage());
	ft_extention(argv[1], ".cub");
	game = game_init(argv[1]);
}
