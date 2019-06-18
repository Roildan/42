/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:04:52 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 12:50:08 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include "err_msg.h"

static void	pixel_to_image(t_fdf *fdf, t_point p, int color)
{
	int	i;

	if (p.x > 0 && p.x + 1 < IMG_WIDTH && p.y > 0 && p.y + 1 < IMG_HEIGHT)
	{
		i = (p.x * fdf->bits_per_pixel / 8) + (p.y * fdf->size_line);
		fdf->img_data[i++] = color;
		fdf->img_data[i++] = color >> 8;
		fdf->img_data[i] = color >> 16;
	}
}

static void	init_dir(int *dir, t_point *p1, t_point *p2)
{
	dir[0] = p1->x < p2->x ? 1 : -1;
	dir[1] = p1->y < p2->y ? 1 : -1;
}

static void	init_delta(t_point *delta, t_point *p1, t_point *p2)
{
	delta->x = ft_iabs(p2->x - p1->x);
	delta->y = ft_iabs(p2->y - p1->y);
}

static void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	current;
	t_point	delta;
	int		dir[2];
	int		error[2];

	init_delta(&delta, &p1, &p2);
	init_dir(dir, &p1, &p2);
	error[0] = delta.x - delta.y;
	current = p1;
	while (1)
	{
		pixel_to_image(fdf, current, get_color(current, p1, p2, delta));
		if (current.x == p2.x && current.y == p2.y)
			break ;
		if ((error[1] = error[0]) > -delta.y)
		{
			error[0] -= delta.y;
			current.x += dir[0];
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			current.y += dir[1];
		}
	}
}

void		draw_image(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (!(fdf->img = mlx_new_image(fdf->mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit_msg(ERR_MSG_MINILIBX, fdf);
	if (!(fdf->img_data = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
					&(fdf->size_line), &(fdf->endian))))
		exit_msg(ERR_MSG_MINILIBX, fdf);
	y = -1;
	while (++y < fdf->map->y_max)
	{
		x = 0;
		while (x < fdf->map->x_max)
		{
			if (x + 1 < fdf->map->x_max)
				draw_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y][x + 1]);
			if (y + 1 < fdf->map->y_max)
				draw_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y + 1][x]);
			x++;
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, MENU_WIDTH + 1,
			TITLE_HEIGHT + 1);
}
