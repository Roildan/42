/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:58:11 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/07 18:29:55 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_point(t_fdf *fdf, int x, int y)
{
	fdf->map->grid[y][x].x = fdf->map->grid[y][x].x_ini;
	fdf->map->grid[y][x].y = fdf->map->grid[y][x].y_ini;
	fdf->map->grid[y][x].z = fdf->map->grid[y][x].z_ini;
}

int		reset(t_fdf *fdf)
{
	ft_foreach(fdf, fdf->map, reset_point);
	init_cam(fdf->map, fdf->cam);
	draw_title_menu(fdf);
	compute_points(fdf);
	draw_image(fdf);
	return (1);
}
