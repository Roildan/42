/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:52:07 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 17:36:35 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "colors.h"

static void	draw_rotations_init(t_fdf *fdf)
{
	size_t	i;
	t_point	line;

	line = new_point(0, FIXED_MENU + OFFSET, 0);
	line.x = MENU_WIDTH;
	line.y += ROTATIONS;
	draw_background(fdf, line, GREY);
	i = 2;
	line = new_point(SPACE, FIXED_MENU + OFFSET + SPACE + LINE, 0);
	line.x = MENU_WIDTH - SPACE;
	while (i--)
	{
		draw_straight_line(fdf, line, WHITE);
		line.y_ini += CASE_HEIGHT;
		line.y += CASE_HEIGHT;
	}
	i = 4;
	line = new_point(SPACE, FIXED_MENU + OFFSET + SPACE + LINE, 0);
	line.y += CASE_HEIGHT;
	while (i--)
	{
		draw_straight_line(fdf, line, WHITE);
		line.x_ini += CASE_WIDTH;
		line.x += CASE_WIDTH;
	}
}

static void	draw_rotations_background(t_fdf *fdf, int x, int y)
{
	int		i;
	t_bool	is_on[3];
	t_point	line;

	is_on[0] = fdf->cam->is_rot_x;
	is_on[1] = fdf->cam->is_rot_y;
	is_on[2] = fdf->cam->is_rot_z;
	i = 0;
	while (i < 3)
	{
		if (is_on[i])
		{
			line = new_point(x + CASE_WIDTH * i, y, 0);
			line.x += CASE_WIDTH - 1;
			line.y += CASE_HEIGHT - 1;
			draw_background(fdf, line, GREEN);
		}
		i++;
	}
}

static char	*get_angle(t_cam *cam, double angle)
{
	char	*res;
	char	*degre;

	if (cam->is_deg)
	{
		angle *= 180 / M_PI;
		degre = ft_dtoa(angle, 1);
	}
	else
		degre = ft_dtoa(angle, 2);
	if (cam->is_deg)
		res = ft_strjoin(degre, " (deg)");
	else
		res = ft_strjoin(degre, " (rad)");
	free(degre);
	return (res);
}

static void	draw_rotations_str(t_fdf *fdf, int x, int y)
{
	int		i;
	int		j;
	char	*name;
	char	*angle;

	i = -1;
	name = ft_strdup("Rot_x: (X)");
	while (++i < 3)
	{
		j = -1;
		if (i == 0)
			angle = get_angle(fdf->cam, fdf->cam->rot_x);
		else if (i == 1)
			angle = get_angle(fdf->cam, fdf->cam->rot_y);
		else
			angle = get_angle(fdf->cam, fdf->cam->rot_z);
		while (++j < 2)
			mlx_string_put(fdf->mlx, fdf->win, x + CASE_WIDTH * i,
				y + LINE * j, WHITE, j == 0 ? name : angle);
		name[4]++;
		name[8]++;
		free(angle);
	}
	free(name);
}

void		draw_rotations(t_fdf *fdf)
{
	draw_rotations_init(fdf);
	draw_rotations_mode_init(fdf,
			MENU_WIDTH - (CASE_WIDTH * 1.5) - SPACE, LINE * 9 - SPACE / 2);
	draw_rotations_mode(fdf,
			MENU_WIDTH - (CASE_WIDTH * 1.5) - SPACE + 1,
			LINE * 9 - SPACE / 2 + 1);
	draw_rotations_background(fdf, SPACE + 1,
			FIXED_MENU + OFFSET + SPACE + LINE + 1);
	draw_rotations_str(fdf, SPACE * 2, FIXED_MENU + OFFSET + SPACE * 2 + LINE);
}
