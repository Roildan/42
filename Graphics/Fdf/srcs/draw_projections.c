/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:47:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/07 20:27:33 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

static void	draw_projections_init(t_fdf *fdf, int x, int y)
{
	size_t	i;
	t_point	line;

	line = new_point(0, y, 0);
	line.x = MENU_WIDTH;
	line.y += PROJECTIONS;
	draw_background(fdf, line, GREY);
	i = 3;
	line = new_point(x, y + LINE * 2, 0);
	line.x = MENU_WIDTH - x;
	while (i--)
	{
		draw_straight_line(fdf, line, WHITE);
		line.y_ini += CASE_HEIGHT;
		line.y += CASE_HEIGHT;
	}
	i = 2;
	line = new_point(x, y + LINE * 2, 0);
	line.y += CASE_HEIGHT * 2;
	while (i--)
	{
		draw_straight_line(fdf, line, WHITE);
		line.x_ini = MENU_WIDTH - LINE;
		line.x = MENU_WIDTH - LINE;
	}
}

static void	draw_projections_background(t_fdf *fdf, int x, int y)
{
	t_point line;

	line = new_point(x, y, 0);
	line.x = MENU_WIDTH - LINE;
	line.y += CASE_HEIGHT - 1;
	if (fdf->cam->projection == ISO)
		draw_background(fdf, line, GREEN);
	else
	{
		line.y_ini += CASE_HEIGHT;
		line.y += CASE_HEIGHT;
		draw_background(fdf, line, GREEN);
	}
	draw_cat(fdf, "- Projection:", 13);
}

static void	draw_projections_str(t_fdf *fdf, int y)
{
	mlx_string_put(fdf->mlx, fdf->win,
			MENU_WIDTH / 2 - get_middle("ISOMETRIC (I)"),
			y + CASE_HEIGHT / 2, WHITE, "ISOMETRIC (I)");
	mlx_string_put(fdf->mlx, fdf->win,
			MENU_WIDTH / 2 - get_middle("PARALLEL (P)"),
			y + CASE_HEIGHT + CASE_HEIGHT / 2, WHITE, "PARALLEL (P)");
}

void		draw_projections(t_fdf *fdf)
{
	draw_projections_init(fdf, LINE, FIXED_MENU + OFFSET + ROTATIONS);
	draw_projections_background(fdf, LINE + 1,
			FIXED_MENU + OFFSET + ROTATIONS + LINE * 2 + 1);
	draw_projections_str(fdf,
			FIXED_MENU + OFFSET + ROTATIONS + LINE * 2 - SPACE);
}
