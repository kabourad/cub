/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:04:43 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/18 14:36:45 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub.h"

static t_keys	keys_init(void)
{
	t_keys	ret;

	ret.esc = 0;
	ret.w_k = 0;
	ret.a_k = 0;
	ret.s_k = 0;
	ret.d_k = 0;
	ret.l_k = 0;
	ret.r_k = 0;
	return (ret);
}

static t_cub	cub_init(void)
{
	t_cub	ret;
	
	ret.save = 0;
	ret.mlx = NULL;
	ret.mlx_win = NULL;
	ret.keys = keys_init();
	return (ret);
}

static int	ft_usage(void)
{
	ft_putstr_fd("Error\nusage: ./cub3d *.cub [--save]\n", 2);
	return (1);
}

int			ft_extention(char *path, char *ext)
{
	int		n;
	int		m;

	n = ft_strlen(path);
	m = ft_strlen(ext);
	if (ft_strcmp(path + n - m, ext))
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_cub	cub;

	cub = cub_init();
	if (argc < 2 || argc > 3)
		return (ft_usage());
	else if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		cub.save = 1;
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
		return (ft_usage());
	if (ft_extention(argv[1], ".cub"))
		quit("Invalid extention: ", argv[1], &cub);
	parsing(argv[1], &cub);
	ray_casting(&cub);
	return (0);
}
