/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:22:53 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 18:08:33 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "main.h"

/*
** Typedef to make easier the use of pointer on functions.
*/
typedef void		(*t_opp)(t_pile *, t_pile *);

/*
** Chained-list, contains a list of the operations to be applyed,
** this operations are stored as pointer on the corresponding function,
** also stores the name of the operations.
*/
typedef struct		s_clist
{
	t_opp			opp;
	char			name[4];
	struct s_clist	*next;
}					t_clist;

/*
** Main structure, contains the two piles and the list of operations.
*/
typedef struct		s_check
{
	t_pile			*piles[2];
	t_pile			*sort[2];
	t_clist			*list;
	int				nb_op;
	t_bool			v;
	t_bool			g;
}					t_check;

/*
** manage_list.c
*/
t_clist				*new_elem(t_opp opp, char *name);
t_clist				*add_elem(t_clist *list, t_clist *elem);
void				free_list(t_clist *list);

/*
** check_opp.c
*/
t_bool				check_opp(const char *str, t_clist **list);

/*
** tools.c
*/
t_check				*get_check(size_t size, const char **tab);
void				exit_msg(const char *str, t_check *check);

/*
** swap.c
*/
void				swap_a(t_pile *a, t_pile *b);
void				swap_b(t_pile *a, t_pile *b);
void				swap_ab(t_pile *a, t_pile *b);

/*
** push.c
*/
void				push_a(t_pile *a, t_pile *b);
void				push_b(t_pile *a, t_pile *b);

/*
** rotate.c
*/
void				rotate_a(t_pile *a, t_pile *b);
void				rotate_b(t_pile *a, t_pile *b);
void				rotate_ab(t_pile *a, t_pile *b);

/*
** rrotate.c
*/
void				rrotate_a(t_pile *a, t_pile *b);
void				rrotate_b(t_pile *a, t_pile *b);
void				rrotate_ab(t_pile *a, t_pile *b);

#endif
