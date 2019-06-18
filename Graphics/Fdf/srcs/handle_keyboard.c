/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:57:01 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/07 16:12:08 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int		key_press(int key, void *param)
{
	if (key == ESC)
		return (ft_close(param));
	else if (key == RESET)
		return (reset((t_fdf *)param));
	else if (key == ARROW_LEFT || key == ARROW_RIGHT ||
			key == ARROW_DOWN || key == ARROW_UP)
		return (move(key, (t_fdf *)param));
	else if (key == ROT_X || key == ROT_Y || key == ROT_Z)
		return (set_rotations(key, (t_fdf *)param));
	else if (key == MORE || key == LESS)
		return (zoom(key, (t_fdf *)param));
	else if (key == PAGE_UP || key == PAGE_DOWN)
		return (altitude(key, (t_fdf *)param));
	else if (key == PROJ_I || key == PROJ_P)
		return (switch_projection(key, (t_fdf *)param));
	return (0);
}
