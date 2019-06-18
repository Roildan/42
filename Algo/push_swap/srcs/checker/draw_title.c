/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_title.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:28:49 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 18:17:03 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphic.h"

static void	reset_title(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < TITLE_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			mlx_pixel_put(mlx->mlx, mlx->win, x++, y, GREY);
		y++;
	}
}

static char	*get_title(t_check *check, t_bool pile)
{
	char	*str;
	char	*temp;
	char	*size;
	char	name;

	name = 'A' + pile;
	str = ft_strdup("Pile ");
	str = ft_str_addi_back(name, str, 1);
	temp = ft_strjoin(str, " (");
	free(str);
	size = ft_itoa((int)check->sort[pile]->size);
	str = ft_strjoin(temp, size);
	free(temp);
	free(size);
	str = ft_str_addi_back(')', str, 1);
	return (str);
}

static char	*get_nb_op(t_check *check)
{
	char	*str;
	char	*temp;
	char	*nb;

	temp = ft_strdup("Number of Operations : ");
	nb = ft_itoa(check->nb_op);
	str = ft_strjoin(temp, nb);
	free(temp);
	free(nb);
	return (str);
}

void		draw_title(t_mlx *mlx)
{
	char	*str;
	int		pile;

	reset_title(mlx);
	str = get_nb_op(mlx->check);
	mlx_string_put(mlx->mlx, mlx->win,
			WIN_WIDTH / 2 - (ft_strlen(str) * CHAR_WIDTH / 2),
			SPACE, WHITE, str);
	free(str);
	pile = 0;
	while (pile < 2)
	{
		str = get_title(mlx->check, pile);
		mlx_string_put(mlx->mlx, mlx->win,
				PILE_WIDTH / 2 - (ft_strlen(str) * CHAR_WIDTH / 2)
				+ pile * WIN_WIDTH / 2, SPACE, WHITE, str);
		free(str);
		pile++;
	}
}
