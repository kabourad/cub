/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fills.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:49:51 by kabourad          #+#    #+#             */
/*   Updated: 2021/02/24 16:58:35 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

t_res	res_fill(char **array, t_cub *cub)
{
	t_res	ret;

	ret.w = ft_atoi(array[1]);
	ret.h = ft_atoi(array[2]);
	if (ret.w > 2560)
	{
		ret.w = 2560;
		ret.h = 1440;
	}
	if (ret.h > 1440)
	{
		ret.w = 2560;
		ret.h = 1440;
	}
	if (ret.w < 0 || ret.h < 0)
		quit("Negative resolution.", NULL, cub);
	return (ret);
}

t_rgb	color_fill(char *str, t_cub *cub)
{
	char	**arr;
	t_rgb	ret;

	arr = ft_split(str, ',');
	if (ft_arrlen(arr) != 3)
	{
		arr ? ft_arrdel(&arr) : 0;
		quit("Color needs to be in rgb format", NULL, cub);
	}
	ret.r = ft_atoi(arr[0]);
	ret.g = ft_atoi(arr[1]);
	ret.b = ft_atoi(arr[2]);
	if (ret.r > 255 || ret.r < 0 || ret.g > 255 || ret.g < 0 || ret.b > 255 ||
			ret.b < 0)
	{
		arr ? ft_arrdel(&arr) : 0;
		quit("Incorrect color value", NULL, cub);
	}
	arr ? ft_arrdel(&arr) : 0;
	return (ret);
}

char	*path_fill(char *str, t_cub *cub)
{
	int		fd;

	ft_extention(str, ".xpm") ? quit("Invalid extention: ", str, cub) : 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		quit("ERROR\ncouldn't open file: ", str, cub);
	close(fd);
	return (ft_strdup(str));
}
