/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:25:35 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 17:37:47 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include "../libft/includes/libft.h"
# include "mlx.h"
# include "settings.h"

/*
** Defines the type of projection chosen (Initially ISO).
*/
typedef enum	e_project
{
	ISO,
	PARALLEL,
	CONICAL
}				t_project;

/*
** Defines a point whith his initial coordinates (x_ini, y_ini and z_ini),
** the actual computed coordinates to fit into the image (x, y and z)
** and finally his color (RGB formated).
*/
typedef struct	s_point
{
	int			x_ini;
	int			y_ini;
	int			z_ini;
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

/*
** Defines a map whith a grid of points (grid),
** the size of the map (x_max and y_max)
** and the highest and lowest altitudes (z_min and z_max).
*/
typedef struct	s_map
{
	t_point		**grid;
	int			x_max;
	int			y_max;
	int			z_min;
	int			z_max;
}				t_map;

/*
** Defines a camera (the point of view) used to compute the image whith :
** - The type of projection (Initially ISO).
** - The zoom, initially computed to correctly fill the image then can be
**   changed by the user.
** - 3 angles of rotations, initially 0 but can be changed by the user.
** - Offsets x and y, initially 0 but can be changed by the user.
*/
typedef struct	s_cam
{
	t_project	projection;
	double		zoom;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	t_bool		is_rot_x;
	t_bool		is_rot_y;
	t_bool		is_rot_z;
	size_t		offset_x;
	size_t		offset_y;
	double		z_multi;
	double		turn;
	t_bool		is_deg;
}				t_cam;

/*
** Main structure which will contains all required informations :
** - MiniLibX's pointers (mlx, win, img and img_data) used by the API.
** - The number of bits used for representing a pixel color (bits_per_pixel).
** - The number of bytes used to store one line of the image in memory,
**   used to move from one line to another (syze_line).
** - Little or big endian, actually little on mac-intel so 0 (endian).
** - A pointer on the map and another to the camera (map and cam).
*/
typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_map		*map;
	t_cam		*cam;
}				t_fdf;

/*
** tools.c
*/
void			exit_msg(const char *str, t_fdf *fdf);
int				get_middle(char *str);
t_point			get_line_coords(size_t len, int x, int y);
void			ft_foreach(t_fdf *fdf, t_map *map,
		void (*f)(t_fdf *, int, int));
int				ft_close(void *param);

/*
** init.c
*/
t_point			new_point(int x, int y, int z);
t_cam			*init_cam(t_map *map, t_cam *cam);
t_fdf			*init_fdf(t_map *map, t_cam *cam);
void			free_fdf(t_fdf *fdf);

/*
** parse.c
*/
t_map			*parse(const char *file);

/*
** draw_tools.c
*/
void			draw_background(t_fdf *fdf, t_point coords, int color);
void			draw_straight_line(t_fdf *fdf, t_point line, int color);
void			draw_cat(t_fdf *fdf, char *str, double i);
void			draw_rotations_mode_init(t_fdf *fdf, int x, int y);
void			draw_rotations_mode(t_fdf *fdf, int x, int y);

/*
** draw_rotations.c
*/
void			draw_rotations(t_fdf *fdf);

/*
** draw_projections.c
*/
void			draw_projections(t_fdf *fdf);

/*
** draw_title_menu.c
*/
void			draw_title_menu(t_fdf *fdf);
void			draw_offset(t_fdf *fdf);

/*
** draw_image.c
*/
void			draw_image(t_fdf *fdf);

/*
** compute_point.c
*/
void			compute_points(t_fdf *fdf);

/*
** colors.c
*/
int				get_color(t_point current, t_point start,
		t_point end, t_point delta);
void			init_color(t_fdf *fdf, int x, int y);

/*
** handle_keyboard.c
*/
int				key_press(int key, void *param);

/*
** handle_mouse.c
*/
int				mouse_clic(int button, int x, int y, void *param);

/*
** reset.c
*/
void			reset_point(t_fdf *fdf, int x, int y);
int				reset(t_fdf *fdf);

/*
** move.c
*/
int				move(int key, t_fdf *fdf);

/*
** rotations.c
*/
int				switch_angle(int i, t_fdf *fdf);
int				check_rotations_mode(int x, int y, t_fdf *fdf);
int				set_rotations(int key, t_fdf *fdf);
int				rotations(t_fdf *fdf);

/*
** zoom_altitude.c
*/
int				zoom(int key, t_fdf *fdf);
int				altitude(int key, t_fdf *fdf);
int				switch_projection(int key, t_fdf *fdf);

#endif
