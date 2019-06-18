/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:10:02 by armoulin          #+#    #+#             */
/*   Updated: 2019/02/04 13:03:27 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_fdlist
{
	int				fd;
	char			*buff;
	struct s_fdlist	*next;
}					t_fdlist;

int					get_next_line(const int fd, char **line);

#endif
