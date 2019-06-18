/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:08:11 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:36:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

static void	draw_title(t_fdf *fdf)
{
	t_point	line;

	line = new_point(0, 0, 0);
	line.x = WIN_WIDTH;
	line.y = TITLE_HEIGHT;
	draw_background(fdf, line, GREY);
	mlx_string_put(fdf->mlx, fdf->win, WIN_WIDTH / 2 - get_middle(TITLE_NAME),
			SPACE, RED, TITLE_NAME);
	line = new_point(0, TITLE_HEIGHT, 0);
	line.x = WIN_WIDTH;
	draw_straight_line(fdf, line, RED);
}

static void	draw_reset(t_fdf *fdf, int x, int y)
{
	size_t	i;
	t_point	line;

	i = 2;
	line = new_point(x, y, 0);
	line.x = MENU_WIDTH - LINE * 2;
	while (i--)
	{
		draw_straight_line(fdf, line, RED);
		line.y_ini += CASE_HEIGHT / 2;
		line.y = line.y_ini;
	}
	i = 2;
	line = new_point(x, y, 0);
	line.y += CASE_HEIGHT / 2;
	while (i--)
	{
		draw_straight_line(fdf, line, RED);
		line.x_ini = MENU_WIDTH - LINE * 2;
		line.x = line.x_ini;
	}
	mlx_string_put(fdf->mlx, fdf->win, MENU_WIDTH / 2 - get_middle("RESET (R)"),
			y + SPACE, RED, "RESET (R)");
}

static void	draw_fixed_menu(t_fdf *fdf)
{
	t_point	line;

	line = new_point(0, TITLE_HEIGHT + 1, 0);
	line.x = MENU_WIDTH;
	line.y = FIXED_MENU;
	draw_background(fdf, line, GREY);
	line = new_point(MENU_WIDTH, TITLE_HEIGHT, 0);
	line.y = WIN_HEIGHT;
	draw_straight_line(fdf, line, RED);
	draw_cat(fdf, "Menu:", 0);
	draw_cat(fdf, "- Zoom:   + / -    or    Scroll", 3);
	draw_cat(fdf, "- Altitude:   Page_Up / Page_Down", 4.5);
	draw_cat(fdf, "- Move:   Directional Pad", 6);
}

void		draw_offset(t_fdf *fdf)
{
	char	*offset;
	char	*res;
	t_point	line;

	line = new_point(0, FIXED_MENU, 0);
	line.x = MENU_WIDTH;
	line.y += OFFSET;
	draw_background(fdf, line, GREY);
	res = ft_itoa(fdf->cam->offset_x);
	offset = ft_strjoin("Offset_x = ", res);
	mlx_string_put(fdf->mlx, fdf->win, SPACE * 5, FIXED_MENU + SPACE,
			WHITE, offset);
	free(offset);
	free(res);
	res = ft_itoa(fdf->cam->offset_y);
	offset = ft_strjoin("Offset_y = ", res);
	mlx_string_put(fdf->mlx, fdf->win, SPACE * 5, FIXED_MENU + LINE,
			WHITE, offset);
	free(offset);
	free(res);
}

void		draw_title_menu(t_fdf *fdf)
{
	t_point line;

	draw_title(fdf);
	draw_fixed_menu(fdf);
	draw_offset(fdf);
	draw_rotations(fdf);
	draw_projections(fdf);
	line = new_point(0, FIXED_MENU + OFFSET + ROTATIONS + PROJECTIONS, 0);
	line.x = MENU_WIDTH;
	line.y = WIN_HEIGHT;
	draw_background(fdf, line, GREY);
	draw_reset(fdf, LINE * 2,
			FIXED_MENU + OFFSET + ROTATIONS + PROJECTIONS + LINE - SPACE);
}
