/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:55:57 by armoulin          #+#    #+#             */
/*   Updated: 2019/01/31 15:20:40 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	ft_read_one(const int fd, char *buffer)
{
	int res;
	int i;

	buffer[20] = '\0';
	res = read(fd, buffer, 20);
	if (res != 20)
		return (FALSE);
	if ((buffer[4] != '\n') || (buffer[9] != '\n')
			|| (buffer[14] != '\n') || (buffer[19] != '\n'))
		return (FALSE);
	i = -1;
	res = 0;
	while (buffer[++i])
	{
		if (i % 5 == 4)
			continue ;
		else if (buffer[i] == '#')
			res++;
		else if (buffer[i] != '.')
			return (FALSE);
	}
	if (res != 4)
		return (FALSE);
	return (TRUE);
}

static int		ft_read_all(const int fd, int coords[26][4])
{
	char	buffer[21];
	int		i;
	int		nb_tetri;
	int		j;

	nb_tetri = 0;
	while (nb_tetri < 26)
	{
		if (!ft_read_one(fd, buffer))
			return (0);
		i = -1;
		j = 0;
		while (buffer[++i])
			if (buffer[i] == '#')
				coords[nb_tetri][j++] = i;
		nb_tetri++;
		if (read(fd, buffer, 1))
		{
			if (*buffer != '\n')
				return (0);
		}
		else
			return (nb_tetri);
	}
	return (0);
}

static t_bool	ft_check_piece(int coords[26][4], int nb_tetri)
{
	int		i;
	int		j;
	int		save;
	int		is_next;
	t_bool	is_double;

	i = -1;
	is_double = FALSE;
	while (++i < 4)
	{
		is_next = 0;
		j = -1;
		while (++j < 4)
		{
			save = coords[nb_tetri][i] - coords[nb_tetri][j];
			if (save == 5 || save == -5 || save == 1 || save == -1)
				is_next++;
			if (is_next == 2)
				is_double = TRUE;
		}
		if (!is_next)
			return (FALSE);
	}
	return (is_double);
}

static void		ft_move_coords(int coords[26][4], int tetri_total)
{
	int nb_tetri;
	int offset_x;
	int offset_y;
	int i;

	nb_tetri = 0;
	while (nb_tetri < tetri_total)
	{
		i = 0;
		offset_x = 3;
		while (i < 4)
		{
			if (coords[nb_tetri][i] % 5 < offset_x)
				offset_x = coords[nb_tetri][i] % 5;
			i++;
		}
		offset_y = (coords[nb_tetri][0] / 5) * 5;
		i = 0;
		while (i < 4)
			coords[nb_tetri][i++] -= offset_x + offset_y;
		nb_tetri++;
	}
}

int				ft_parsing(const int fd, int coords[26][4])
{
	int tetri_total;
	int nb_tetri;

	if ((tetri_total = ft_read_all(fd, coords)) == 0)
		return (0);
	nb_tetri = 0;
	while (nb_tetri < tetri_total)
	{
		if (!ft_check_piece(coords, nb_tetri))
			return (0);
		nb_tetri++;
	}
	ft_move_coords(coords, tetri_total);
	return (tetri_total);
}
