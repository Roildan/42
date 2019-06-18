/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:27:32 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/29 17:10:02 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphic.h"

t_line	new_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.x1 = x1;
	line.x2 = x2;
	line.y1 = y1;
	line.y2 = y2;
	return (line);
}

t_mlx	*init_mlx(t_check *check)
{
	t_mlx	*mlx;
	t_line	line;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		exit_msg(ERROR_MALLOC, NULL);
	if (!(mlx->mlx = mlx_init()))
		exit_msg(ERROR_MLX, NULL);
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT,
					"Push Swap")))
		exit_msg(ERROR_MLX, NULL);
	if (!(mlx->img = mlx_new_image(mlx->mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit_msg(ERROR_MLX, NULL);
	if (!(mlx->img_data = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
					&(mlx->size_line), &(mlx->endian))))
		exit_msg(ERROR_MLX, NULL);
	mlx->rec_h = PILE_HEIGHT / check->sort[0]->size;
	mlx->check = check;
	mlx->current = check->list;
	line = new_line(WIN_WIDTH / 2, TITLE_HEIGHT + 1, WIN_WIDTH / 2, WIN_HEIGHT);
	draw_line(mlx, line, WHITE);
	line = new_line(0, TITLE_HEIGHT, WIN_WIDTH, TITLE_HEIGHT);
	draw_line(mlx, line, WHITE);
	return (mlx);
}

void	draw_line(t_mlx *mlx, t_line line, int color)
{
	if (line.x1 == line.x2)
		while (line.y1 != line.y2)
			mlx_pixel_put(mlx->mlx, mlx->win, line.x1, line.y1++, color);
	else
		while (line.x1 != line.x2)
			mlx_pixel_put(mlx->mlx, mlx->win, line.x1++, line.y1, color);
}

void	pixel_to_image(t_mlx *mlx, t_line p, int color)
{
	int	i;

	if (p.x1 > 0 && p.x1 + 1 < IMG_WIDTH && p.y1 > 0 && p.y1 + 1 < IMG_HEIGHT)
	{
		i = (p.x1 * mlx->bits_per_pixel / 8) + (p.y1 * mlx->size_line);
		mlx->img_data[i++] = color;
		mlx->img_data[i++] = color >> 8;
		mlx->img_data[i] = color >> 16;
	}
}
