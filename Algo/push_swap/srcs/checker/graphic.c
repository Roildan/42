/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:16:30 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 17:09:36 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphic.h"

static void	reset_img(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (!(mlx->img = mlx_new_image(mlx->mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit_msg(ERROR_MLX, NULL);
	if (!(mlx->img_data = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
					&(mlx->size_line), &(mlx->endian))))
		exit_msg(ERROR_MLX, NULL);
}

static void	draw_rec(t_mlx *mlx, t_line line)
{
	int	i;
	int	x_ini;

	i = 0;
	x_ini = line.x1;
	while (i < mlx->rec_h)
	{
		while (line.x1 <= line.x2)
		{
			pixel_to_image(mlx, line, RED);
			line.x1++;
		}
		line.x1 = x_ini;
		line.y1++;
		i++;
	}
}

void		draw_pile(t_mlx *mlx)
{
	int		size;
	float	width;
	int		pile;
	t_line	line;

	draw_title(mlx);
	pile = -1;
	while (++pile < 2)
	{
		reset_img(mlx);
		size = mlx->check->sort[pile]->size;
		while (--size >= 0)
		{
			width = (float)mlx->check->sort[pile]->p[size] /
				(float)(mlx->check->sort[0]->size + mlx->check->sort[1]->size)
				* PILE_WIDTH + 10;
			line = new_line(WIN_WIDTH / 4 - (int)(width / 2),
					TITLE_HEIGHT + size * mlx->rec_h - PADDING,
					WIN_WIDTH / 4 + (int)(width / 2),
					TITLE_HEIGHT + size * mlx->rec_h - PADDING);
			draw_rec(mlx, line);
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
				pile * (WIN_WIDTH / 2 + 1), TITLE_HEIGHT + 1);
	}
}
