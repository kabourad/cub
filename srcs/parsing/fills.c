/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fills.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:49:51 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/19 15:59:39 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub.h"

t_res	resolution_fill(char **array)
{
	t_res	ret;

	ret.width = ft_atoi(array[1]);
	ret.height = ft_atoi(array[2]);
	return (ret);
}

t_col	color_fill(char *str)
{
	char	**arr;
	t_col	ret;

	arr = ft_split(str, ',');
	if (ft_arrlen(arr) != 3)
		quit("Color needs to be in rgb format", NULL);
	ret.r = ft_atoi(arr[0] + 1);
	ret.r > 255 || ret.r < 0 ? quit("Incorrect red color value", NULL) : 0;
	ret.g = ft_atoi(arr[1]);
	ret.g > 255 || ret.g < 0 ? quit("Incorrect blue color value", NULL) : 0;
	ret.b = ft_atoi(arr[2]);
	ret.b > 255 || ret.b < 0 ? quit("Incorrect green color value", NULL) : 0;
	arr ? ft_arrdel(&arr) : 0;
	return (ret);
}

char	*path_fill(char *str)
{
	int		fd;

	ft_extention(str, ".xpm");
	if ((fd = open(str, O_RDONLY)) == -1)
		quit("ERROR\ncouldn't open file: ", str);
	close(fd);
	return (ft_strdup(str));
}
