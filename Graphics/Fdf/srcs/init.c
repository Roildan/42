/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:39:31 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:29:29 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "err_msg.h"
#include "colors.h"

t_point	new_point(int x, int y, int z)
{
	t_point new;

	new.x_ini = x;
	new.y_ini = y;
	new.z_ini = z;
	new.x = x;
	new.y = y;
	new.z = z;
	new.color = WHITE;
	return (new);
}

t_cam	*init_cam(t_map *map, t_cam *cam)
{
	if (!cam)
		if (!(cam = (t_cam *)ft_memalloc(sizeof(t_cam))))
			exit_msg(ERR_MSG_MALLOC, NULL);
	cam->projection = ISO;
	cam->zoom = ft_imin(WIN_WIDTH / map->x_max / 2,
			WIN_HEIGHT / map->y_max / 2);
	if (cam->zoom < 0.5)
		cam->zoom = 0.5;
	cam->rot_x = 0;
	cam->rot_y = 0;
	cam->rot_z = 0;
	cam->is_rot_x = FALSE;
	cam->is_rot_y = FALSE;
	cam->is_rot_z = FALSE;
	cam->offset_x = 0;
	cam->offset_y = 0;
	cam->z_multi = 1;
	cam->turn = 2 * M_PI;
	cam->is_deg = TRUE;
	return (cam);
}

t_fdf	*init_fdf(t_map *map, t_cam *cam)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		exit_msg(ERR_MSG_MALLOC, NULL);
	if (!(fdf->mlx = mlx_init()))
		exit_msg(ERR_MSG_MINILIBX, fdf);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF")))
		exit_msg(ERR_MSG_MINILIBX, fdf);
	if (!(fdf->img = mlx_new_image(fdf->mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit_msg(ERR_MSG_MINILIBX, fdf);
	if (!(fdf->img_data = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
					&(fdf->size_line), &(fdf->endian))))
		exit_msg(ERR_MSG_MALLOC, fdf);
	fdf->map = map;
	fdf->cam = cam;
	return (fdf);
}

void	free_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->map && fdf->map->grid)
	{
		while (i < fdf->map->y_max)
			free(fdf->map->grid[i++]);
		free(fdf->map->grid);
	}
	if (fdf->map)
		free(fdf->map);
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf);
}
