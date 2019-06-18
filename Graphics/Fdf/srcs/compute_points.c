/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:08:22 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/07 16:52:07 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	iso_projection(t_point *p)
{
	int	temp_x;
	int	temp_y;

	temp_x = p->x;
	temp_y = p->y;
	p->x = (int)((double)(temp_x - temp_y) * cos(0.523599));
	p->y = -(p->z);
	p->y += (int)((double)(temp_x + temp_y) * sin(0.523599));
}

static void	apply_rot(double a, double b, double c, t_point *p)
{
	double	x;
	double	y;
	double	z;
	double	ccos[3];
	double	csin[3];

	x = (double)p->x;
	y = (double)p->y;
	z = (double)p->z;
	ccos[0] = cos(a);
	ccos[1] = cos(b);
	ccos[2] = cos(c);
	csin[0] = sin(a);
	csin[1] = sin(b);
	csin[2] = sin(c);
	p->x = (int)(ccos[2] * ccos[1] * x + csin[2] * ccos[1] * y +
			(-csin[1]) * z);
	p->y = (int)(((-csin[2]) * ccos[0] + ccos[2] * csin[1] * csin[0]) * x +
				(ccos[2] * ccos[0] + csin[2] * csin[1] * csin[0]) * y +
				ccos[1] * csin[0] * z);
	p->z = (int)((csin[2] * csin[1] + ccos[2] * csin[1] * ccos[0]) * x +
				((-ccos[2]) * csin[0] + csin[2] * csin[1] * ccos[0]) * y +
				ccos[1] * ccos[0] * z);
}

static void	compute_point(t_fdf *fdf, int x, int y)
{
	reset_point(fdf, x, y);
	fdf->map->grid[y][x].x *= fdf->cam->zoom;
	fdf->map->grid[y][x].y *= fdf->cam->zoom;
	fdf->map->grid[y][x].z *= fdf->cam->zoom * fdf->cam-> z_multi / 3;
	fdf->map->grid[y][x].x -= fdf->map->x_max * fdf->cam->zoom / 2;
	fdf->map->grid[y][x].y -= fdf->map->y_max * fdf->cam->zoom / 2;
	if (fdf->cam->rot_x || fdf->cam->rot_y || fdf->cam->rot_z)
		apply_rot(fdf->cam->rot_x, fdf->cam->rot_y, fdf->cam->rot_z,
				&(fdf->map->grid[y][x]));
	if (fdf->cam->projection == ISO)
		iso_projection(&(fdf->map->grid[y][x]));
	fdf->map->grid[y][x].x += IMG_WIDTH / 2 + fdf->cam->offset_x;
	fdf->map->grid[y][x].y += IMG_HEIGHT / 2 + fdf->cam->offset_y;
}

void		compute_points(t_fdf *fdf)
{
	ft_foreach(fdf, fdf->map, compute_point);
}
