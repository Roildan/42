/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:34 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 17:41:06 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

void	draw_background(t_fdf *fdf, t_point coords, int color)
{
	int	x;

	while (coords.y_ini < coords.y)
	{
		x = coords.x_ini;
		while (x < coords.x)
			mlx_pixel_put(fdf->mlx, fdf->win,
					x++, coords.y_ini, color);
		coords.y_ini++;
	}
}

void	draw_straight_line(t_fdf *fdf, t_point line, int color)
{
	if (line.x_ini == line.x)
		while (line.y_ini <= line.y)
			mlx_pixel_put(fdf->mlx, fdf->win, line.x, line.y_ini++, color);
	else if (line.y_ini == line.y)
		while (line.x_ini <= line.x)
			mlx_pixel_put(fdf->mlx, fdf->win, line.x_ini++, line.y, color);
}

void	draw_cat(t_fdf *fdf, char *str, double i)
{
	size_t	len;
	char	*title;
	t_point	line;
	t_bool	is_menu;

	len = 0;
	is_menu = ft_strcmp(str, "Menu:") == 0 ? TRUE : FALSE;
	while (str[len] && str[len] != ':')
		len++;
	title = ft_strndup(str, len + 1);
	if (is_menu)
		line = get_line_coords(++len, MENU_WIDTH / 2 - get_middle("Menu:"),
			SPACE + TITLE_HEIGHT);
	else
		line = get_line_coords(++len, SPACE, LINE * i);
	mlx_string_put(fdf->mlx, fdf->win, line.x_ini + SPACE / 2,
				line.y - CHAR_HEIGHT, GREEN, title);
	mlx_string_put(fdf->mlx, fdf->win,
			line.x_ini + SPACE / 2 + len * CHAR_WIDTH,
			line.y - CHAR_HEIGHT, WHITE, str + len);
	draw_straight_line(fdf, line, GREEN);
	free(title);
}

void	draw_rotations_mode_init(t_fdf *fdf, int x, int y)
{
	size_t	i;
	t_point	line;

	draw_cat(fdf, "- Rotations:", 9);
	line = new_point(x, y, 0);
	line.x += CASE_WIDTH * 1.5 - 1;
	i = 2;
	while (i--)
	{
		draw_straight_line(fdf, line, WHITE);
		line.y_ini += CASE_HEIGHT / 3;
		line.y = line.y_ini;
	}
	line = new_point(x, y, 0);
	line.y += CASE_HEIGHT / 3;
	i = 3;
	while (i--)
	{
		draw_straight_line(fdf, line, WHITE);
		line.x_ini += CASE_WIDTH * 0.75;
		line.x = line.x_ini;
	}
}

void	draw_rotations_mode(t_fdf *fdf, int x, int y)
{
	t_point line;

	line = new_point((fdf->cam->is_deg ? x : x + CASE_WIDTH * 0.75), y, 0);
	line.x += CASE_WIDTH * 0.75 - 1;
	line.y += CASE_HEIGHT / 3 - 1;
	draw_background(fdf, line, GREEN);
	mlx_string_put(fdf->mlx, fdf->win, x + SPACE * 2,
				y + SPACE / 2 - 2, WHITE, "Deg");
	mlx_string_put(fdf->mlx, fdf->win, x + CASE_WIDTH * 0.75 + SPACE * 2,
				y + SPACE / 2 - 2, WHITE, "Rad");
}
