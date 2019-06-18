/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:37:31 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 17:38:09 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"
#include "mouse.h"

static int	check_rotations(int x, int y, t_fdf *fdf)
{
	int		i;
	t_point	square;

	square = new_point(SPACE, FIXED_MENU + OFFSET + SPACE + LINE, 0);
	square.y += CASE_HEIGHT;
	i = 1;
	while (i < 4)
	{
		if (i != 1)
			square.x_ini += CASE_WIDTH;
		square.x += CASE_WIDTH;
		if (x >= square.x_ini && x < square.x &&
				y >= square.y_ini && y <= square.y)
		{
			if (i == 1)
				return (set_rotations(ROT_X, fdf));
			else if (i == 2)
				return (set_rotations(ROT_Y, fdf));
			else
				return (set_rotations(ROT_Z, fdf));
		}
		i++;
	}
	return (0);
}

static int	check_projections(int x, int y, t_fdf *fdf)
{
	int		i;
	t_point	square;

	square = new_point(LINE, FIXED_MENU + OFFSET + ROTATIONS + LINE * 2, 0);
	square.x = MENU_WIDTH - LINE;
	i = 1;
	while (i < 3)
	{
		if (i != 1)
			square.y_ini += CASE_HEIGHT;
		square.y += CASE_HEIGHT;
		if (x >= square.x_ini && x < square.x &&
				y >= square.y_ini && y <= square.y)
		{
			if (i == 1)
				return (switch_projection(PROJ_I, fdf));
			else
				return (switch_projection(PROJ_P, fdf));
		}
		i++;
	}
	return (0);
}

static int	check_reset(int x, int y, t_fdf *fdf)
{
	t_point	square;

	square = new_point(LINE * 2,
			FIXED_MENU + OFFSET + ROTATIONS + PROJECTIONS + LINE - SPACE, 0);
	square.x = MENU_WIDTH - LINE * 2;
	square.y += CASE_HEIGHT / 2;
	if (x >= square.x_ini && x <= square.x &&
			y >= square.y_ini && y <= square.y)
		return (reset(fdf));
	return (0);
}

static int	handle_position(int x, int y, t_fdf *fdf)
{
	if (x < 0 || x > MENU_WIDTH || y < TITLE_HEIGHT || y > WIN_HEIGHT)
		return (0);
	if (check_rotations(x, y, fdf))
		return (1);
	if (check_rotations_mode(x, y, fdf))
		return (1);
	if (check_projections(x, y, fdf))
		return (1);
	if (check_reset(x, y, fdf))
		return (1);
	return (0);
}

int			mouse_clic(int button, int x, int y, void *param)
{
	if (button == SCROLL_UP)
		zoom(MORE, (t_fdf *)param);
	else if (button == SCROLL_DOWN)
		zoom(LESS, (t_fdf *)param);
	else if (button == CLIC_LEFT || button == CLIC_RIGHT ||
			button == CLIC_MIDDLE)
		handle_position(x, y, (t_fdf *)param);
	return (0);
}
