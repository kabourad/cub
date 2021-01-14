/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fills.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:49:51 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/14 17:22:47 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

t_bi	resolution_fill(char **array)
{
	t_bi	ret;

	ret.x = (double)ft_atoi(array[1]);
	ret.y = (double)ft_atoi(array[2]);
	return (ret);
}

t_col	color_fill(char *str)
{
	char	**arr;
	t_col	ret;

	arr = ft_split(str, ',');
	if (ft_arrlen(arr) != 3)
		put_and_quit("Color needs to be in rgb format");
	ret.r = ft_atoi(arr[0]);
	ret.r > 255 || ret.r < 0 ? put_and_quit("Incorrect red color value") : 0;
	ret.g = ft_atoi(arr[1]);
	ret.g > 255 || ret.g < 0 ? put_and_quit("Incorrect blue color value") : 0; 
	ret.b = ft_atoi(arr[2]);
	ret.b > 255 || ret.b < 0 ? put_and_quit("Incorrect green color value") : 0;
	arr ? ft_arrdel(&arr) : 0;
	return (ret);
}

char	*path_fill(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("ERROR\ncouldn't open file: ", 2);
		ft_putendl_fd(str, 2);
		exit(1);
	}
	close(fd);
	return (ft_strdup(str));
}