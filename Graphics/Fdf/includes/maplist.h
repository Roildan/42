/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:34:05 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/05 18:16:51 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPLIST_H
# define MAPLIST_H

# include "fdf.h"

/*
** Defines a chained list that stores a splited line from get_next_line and
** ft_strsplit.
*/
typedef struct s_maplist	t_maplist;
struct			s_maplist
{
	char		**line;
	int			y;
	int			x;
	t_maplist	*next;
};

void			free_list(t_maplist *list);
t_maplist		*create_list(const char *file);

#endif
