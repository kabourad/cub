/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:04:43 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/02 16:51:35 by awali-al         ###   ########.fr       */
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

	if (argc < 2 || argc > 3)
		return (ft_usage());
	ft_extention(argv[1], ".cub");
	cub.parse = parsing(argv[1]);
	ray_casting(&cub);
	return (0);
}
