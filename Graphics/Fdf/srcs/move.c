/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:59:51 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/07 16:57:08 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

static void	apply_offset(t_map *map, t_bool is_x, int nb)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (is_x)
				map->grid[y][x].x += nb;
			else
				map->grid[y][x].y += nb;
			x++;
		}
		y++;
	}
}

int			move(int key, t_fdf *fdf)
{
	t_bool	is_x;
	int		nb;

	is_x = (key == ARROW_LEFT || key == ARROW_RIGHT) ? TRUE : FALSE;
	nb = (key == ARROW_LEFT || key == ARROW_UP) ? -10 : 10;
	if (is_x)
		fdf->cam->offset_x += nb;
	else
		fdf->cam->offset_y += nb;
	apply_offset(fdf->map, is_x, nb);
	draw_offset(fdf);
	draw_image(fdf);
	return (0);
}
