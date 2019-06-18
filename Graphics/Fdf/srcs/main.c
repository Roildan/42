/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:39:23 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:02:47 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "err_msg.h"

static void	setup_interactions(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_clic, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close, fdf);
	mlx_loop_hook(fdf->mlx, rotations, fdf);
}

int			main(int ac, char **av)
{
	t_map	*map;
	t_fdf	*fdf;

	if (ac != 2)
	{
		ft_putstr(ERR_MSG_USAGE);
		return (-1);
	}
	map = parse(av[1]);
	ft_putendl("Parsing done.");
	fdf = init_fdf(map, init_cam(map, NULL));
	ft_foreach(fdf, fdf->map, init_color);
	ft_putendl("Fdf initilized.");
	draw_title_menu(fdf);
	ft_putendl("Title and menu drawed.");
	compute_points(fdf);
	ft_putendl("Coords computed.");
	draw_image(fdf);
	ft_putendl("Image drawed.");
	setup_interactions(fdf);
	ft_putendl("Interactions established.");
	mlx_loop(fdf->mlx);
	free_fdf(fdf);
	return (0);
}
