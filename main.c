/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:04:43 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/17 17:38:21 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

static int	ft_usage(void)
{
	ft_putstr_fd("Error\nusage: ./cub3d *.cub [--save]\n", 2);
	return (1);
}

void		ft_extention(char *path, char *ext)
{
	int		n;
	int		m;

	n = ft_strlen(path);
	m = ft_strlen(ext);
	if (ft_strcmp(path + n - m, ext))
		quit("wrong extention: ", path);
}

int			main(int argc, char **argv)
{
	t_cub	cub;

	cub.save = 0;
	if (argc < 2 || argc > 3)
		return (ft_usage());
	else if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		cub.save = 1;
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
		return (ft_usage());
	ft_extention(argv[1], ".cub");
	cub.parse = parsing(argv[1]);
	ray_casting(&cub);
	return (0);
}
