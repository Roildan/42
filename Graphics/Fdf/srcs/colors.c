/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:36:19 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 14:17:03 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = (double)(current - start);
	distance = (double)(end - start);
	return ((distance == 0 ? 1.0 : placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		get_color_init(int z, int min, int max)
{
	double	percentage;

	if (z <= 0)
	{
		percentage = percent(min, 0, z);
		if (percentage < 0.333)
			return (BLUE_DARK);
		if (percentage < 0.667)
			return (BLUE);
		return (BLUE_LIGHT);
	}
	percentage = percent(min, max, z);
	if (percentage < 0.143)
		return (GREEN_LIGHT);
	if (percentage < 0.286)
		return (GREEN);
	if (percentage < 0.429)
		return (GREEN_DARK);
	if (percentage < 0.571)
		return (BROWN_LIGHT);
	if (percentage < 0.714)
		return (BROWN);
	if (percentage < 0.857)
		return (BROWN_DARK);
	return (SNOW);
}

void			init_color(t_fdf *fdf, int x, int y)
{
	t_point *p;

	p = &fdf->map->grid[y][x];
	p->color = get_color_init(p->z, fdf->map->z_min, fdf->map->z_max);
}

int				get_color(t_point current, t_point start,
		t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
