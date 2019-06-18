/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:34:43 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 18:09:40 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphic.h"

int		ft_close(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	exit(0);
	return (0);
}

int		draw(t_mlx *mlx)
{
	static t_bool end = TRUE;

	if (mlx->current)
	{
		mlx->check->nb_op++;
		if (mlx->check->v)
			ft_printf("\nApplying %s\n", mlx->current->name);
		mlx->current->opp(mlx->check->piles[0], mlx->check->piles[1]);
		mlx->current->opp(mlx->check->sort[0], mlx->check->sort[1]);
		if (mlx->check->v)
			print_both(mlx->check->piles[0], mlx->check->piles[1]);
		draw_pile(mlx);
		mlx->current = mlx->current->next;
	}
	else if (end)
	{
		end = FALSE;
		if (is_sorted(mlx->check->piles))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}

void	setup_interactions(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 0, ft_close, mlx);
	mlx_loop_hook(mlx->mlx, draw, mlx);
}
