/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:32:07 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 16:02:15 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "maplist.h"
#include "err_msg.h"

void				free_list(t_maplist *list)
{
	t_maplist	*next;
	int			i;

	while (list)
	{
		next = list->next;
		i = 0;
		while (list->line[i])
			free(list->line[i++]);
		free(list->line);
		free(list);
		list = next;
	}
}

static t_maplist	*new_elem(char **line, size_t y)
{
	t_maplist	*maplist;
	int			x;

	if (!(maplist = (t_maplist *)ft_memalloc(sizeof(t_maplist))) || !line)
		exit_msg(ERR_MSG_MALLOC, NULL);
	x = 0;
	while (line[x])
		x++;
	maplist->line = line;
	maplist->y = y;
	maplist->x = x;
	maplist->next = NULL;
	return (maplist);
}

static t_maplist	*add_elem(t_maplist *list, t_maplist *elem)
{
	t_maplist *current;

	current = list;
	if (!current)
		return (elem);
	while (current->next)
		current = current->next;
	current->next = elem;
	return (list);
}

static t_bool		check_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!line[i])
			break ;
		if (line[i] == '-')
		{
			if (i && ft_isdigit(line[i - 1]))
				return (FALSE);
			i++;
		}
		if (!ft_isdigit(line[i]))
			return (FALSE);
		while (ft_isdigit(line[i]))
			i++;
	}
	return (TRUE);
}

t_maplist			*create_list(const char *file)
{
	int			fd;
	int			y;
	char		*line;
	t_maplist	*list;

	fd = open(file, O_RDWR);
	if (fd < 0)
		exit_msg(ERR_MSG_OPEN, NULL);
	y = 1;
	list = NULL;
	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
		{
			free(line);
			close(fd);
			free_list(list);
			exit_msg(ERR_MSG_MAP, NULL);
		}
		list = add_elem(list, new_elem(ft_strsplit(line, ' '), y));
		free(line);
		y++;
	}
	close(fd);
	return (list);
}
