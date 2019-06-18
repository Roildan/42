/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:44:14 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:01:52 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "maplist.h"
#include "fdf.h"
#include "err_msg.h"

static t_point		get_max(t_maplist *list)
{
	t_point	max;

	max = new_point(0, 0, 0);
	while (list)
	{
		if (list->x > max.x)
			max.x = list->x;
		if (!list->next)
			max.y = list->y;
		list = list->next;
	}
	return (max);
}

static void			fill_grid(t_map *map, t_point max, t_maplist *list)
{
	int	x;
	int	y;
	int	z;

	y = -1;
	while (++y < max.y)
	{
		x = 0;
		while (x < list->x)
		{
			z = ft_atoi(list->line[x]);
			if (z < map->z_min)
				map->z_min = z;
			if (z > map->z_max)
				map->z_max = z;
			map->grid[y][x] = new_point(x, y, z);
			x++;
		}
		while (x <= max.x)
		{
			map->grid[y][x] = new_point(x, y, 0);
			x++;
		}
		list = list->next;
	}
}

static t_map		*create_map(t_maplist *list)
{
	t_map	*map;
	t_point	max;
	int		y;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit_msg(ERR_MSG_MALLOC, NULL);
	max = get_max(list);
	if (!(map->grid = (t_point **)ft_memalloc(max.y * sizeof(t_point *))))
		exit_msg(ERR_MSG_MALLOC, NULL);
	y = 0;
	while (y < max.y)
	{
		if (!(map->grid[y] = (t_point *)ft_memalloc(max.x * sizeof(t_point))))
			exit_msg(ERR_MSG_MALLOC, NULL);
		y++;
	}
	map->x_max = max.x;
	map->y_max = max.y;
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	fill_grid(map, max, list);
	return (map);
}

t_map				*parse(const char *file)
{
	t_maplist	*list;
	t_map		*map;

	if (!(list = create_list(file)))
		exit_msg(ERR_MSG_MAP, NULL);
	map = create_map(list);
	free_list(list);
	return (map);
}
