/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:28:56 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:10:15 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int		zoom(int key, t_fdf *fdf)
{
	if (key == MORE)
		fdf->cam->zoom += fdf->cam->zoom * 0.1;
	else if (fdf->cam->zoom > 0.5)
		fdf->cam->zoom -= fdf->cam->zoom * 0.1;
	compute_points(fdf);
	draw_image(fdf);
	return (1);
}

int		altitude(int key, t_fdf *fdf)
{
	if (key == PAGE_DOWN)
		fdf->cam->z_multi -= 0.1;
	else if (fdf->cam->z_multi < 4)
		fdf->cam->z_multi += 0.1;
	if (fdf->cam->z_multi < 0.1)
		fdf->cam->z_multi = 0.1;
	compute_points(fdf);
	draw_image(fdf);
	return (0);
}

int		switch_projection(int key, t_fdf *fdf)
{
	t_bool	change;

	change = TRUE;
	if (key == PROJ_I && fdf->cam->projection == ISO)
		change = FALSE;
	else if (key == PROJ_P && fdf->cam->projection == PARALLEL)
		change = FALSE;
	if (change)
	{
		reset(fdf);
		fdf->cam->projection = key == PROJ_P ? PARALLEL : ISO;
		compute_points(fdf);
		draw_projections(fdf);
		draw_image(fdf);
	}
	return (1);
}
