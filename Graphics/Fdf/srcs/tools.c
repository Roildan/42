/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:28:18 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 14:32:15 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void		exit_msg(const char *str, t_fdf *fdf)
{
	ft_putstr(str);
	if (fdf)
		free_fdf(fdf);
	exit(-1);
}

int			get_middle(char *str)
{
	return (ft_strlen(str) * CHAR_WIDTH / 2);
}

t_point		get_line_coords(size_t len, int x, int y)
{
	t_point res;

	res = new_point(x - (SPACE / 2), y + CHAR_HEIGHT, 0);
	res.x = x + (len * CHAR_WIDTH) + (SPACE / 2);
	return (res);
}

void		ft_foreach(t_fdf *fdf, t_map *map, void (*f)(t_fdf *, int, int))
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			f(fdf, x, y);
			x++;
		}
		y++;
	}
}

int			ft_close(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (fdf)
		free_fdf(fdf);
	exit(0);
	return (0);
}
