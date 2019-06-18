/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:40:21 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 17:40:42 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int		switch_angle(int i, t_fdf *fdf)
{
	if (i == 0)
		fdf->cam->is_deg = TRUE;
	else
		fdf->cam->is_deg = FALSE;
	return (1);
}

int		check_rotations_mode(int x, int y, t_fdf *fdf)
{
	int		i;
	t_point	square;

	square = new_point(MENU_WIDTH - CASE_WIDTH * 1.5 - SPACE,
			LINE * 9 - SPACE / 2, 0);
	square.y += CASE_HEIGHT / 3;
	i = 0;
	while (i < 2)
	{
		square.x_ini += (CASE_WIDTH * 0.75) * i;
		square.x += (CASE_WIDTH * 0.75) * (i + 1);
		if (x >= square.x_ini && x < square.x &&
				y >= square.y_ini && y <= square.y)
			return (switch_angle(i, fdf));
		i++;
	}
	return (0);
}

int		set_rotations(int key, t_fdf *fdf)
{
	if (key == ROT_X)
		fdf->cam->is_rot_x = !fdf->cam->is_rot_x;
	else if (key == ROT_Y)
		fdf->cam->is_rot_y = !fdf->cam->is_rot_y;
	else
		fdf->cam->is_rot_z = !fdf->cam->is_rot_z;
	return (1);
}

int		rotations(t_fdf *fdf)
{
	double turn;

	turn = fdf->cam->turn;
	if (fdf->cam->is_rot_x)
	{
		fdf->cam->rot_x += 0.01;
		if (fdf->cam->rot_x >= turn)
			fdf->cam->rot_x -= turn;
	}
	if (fdf->cam->is_rot_y)
	{
		fdf->cam->rot_y += 0.01;
		if (fdf->cam->rot_y >= turn)
			fdf->cam->rot_y -= turn;
	}
	if (fdf->cam->is_rot_z)
	{
		fdf->cam->rot_z += 0.01;
		if (fdf->cam->rot_z >= turn)
			fdf->cam->rot_z -= turn;
	}
	compute_points(fdf);
	draw_rotations(fdf);
	draw_image(fdf);
	return (0);
}
