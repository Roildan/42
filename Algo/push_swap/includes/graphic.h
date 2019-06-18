/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:01:40 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 17:05:34 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "mlx.h"
# include "checker.h"

# define ERROR_MLX "MiniLibX failed (for whatever reason)"

# define GREY 0x202020
# define WHITE 0xFFFFFF
# define RED 0xe8175d

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define TITLE_HEIGHT 50
# define IMG_HEIGHT (WIN_HEIGHT - TITLE_HEIGHT - 1)
# define IMG_WIDTH (WIN_WIDTH / 2 - 1)
# define PADDING 20
# define PILE_HEIGHT (WIN_HEIGHT - TITLE_HEIGHT - PADDING)
# define PILE_WIDTH (WIN_WIDTH / 2 - PADDING * 2)
# define CHAR_WIDTH 10
# define CHAR_HEIGHT 23
# define SPACE 13

typedef struct	s_line
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			rec_h;
	t_check		*check;
	t_clist		*current;
}				t_mlx;

/*
** graphic.c
*/
void			draw_pile(t_mlx *mlx);

/*
** graphic_tools.c
*/
void			draw_line(t_mlx *mlx, t_line line, int color);
void			pixel_to_image(t_mlx *mlx, t_line p, int color);
t_line			new_line(int x1, int y1, int x2, int y2);
t_mlx			*init_mlx(t_check *check);

/*
** draw_title.c
*/
void			draw_title(t_mlx *mlx);

/*
** event_management.c
*/
void			setup_interactions(t_mlx *mlx);

#endif
