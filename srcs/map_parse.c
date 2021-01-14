/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:20:33 by kabourad          #+#    #+#             */
/*   Updated: 2021/01/14 17:22:22 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub.h"

static t_mapll	*new_node(char *line, t_mapll *prv)
{
	t_mapll	*ret;
	
	ret = (t_mapll*)malloc(sizeof(t_mapll));
	ret->next = NULL;
	if (prv)
		ret->i = prv->i + 1;
	else
		ret->i = 0;
	ret->line = ft_strdup(line);
	return (ret);
}

static void	check_store(char *line, t_parse *stru)
{
    t_mapll   *tmp;
    int     i;

    tmp = stru->map;
    while (tmp && tmp->next)
        tmp = tmp->next;
    i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			space_check(tmp, line, i);
		else if (is_valid(line[i]))
			twod_check(tmp, line, i, stru);
		else if (line[i] != '1')
			put_and_quit("Error\nInvalid map");
		i++;
	}
	if (tmp)
		tmp->next = new_node(line, tmp);
	else
		tmp = new_node(line, tmp);
    if (!stru->map)
        stru->map = tmp;
}

void		map_fill(int fd, t_parse *stru)
{
	char	*line;
	int		n;

	line = NULL;
	while ((n = get_next_line(fd, &line)) >= 0)
	{
		if (line)
		{
			check_store(line, stru);
			ft_strdel(&line);
		}
		else if (!line && stru->map)
			put_and_quit("The map shouldn't contain empty lines");
		if (!n)
			break ;
	}
	check_last_line(stru->map);
	stru->ids |= MP_ID;
}
