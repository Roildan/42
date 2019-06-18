/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:04 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 17:51:07 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../ft_printf/includes/printf.h"

# define ERROR_MALLOC "Malloc error"
# define ERROR "Error"

/*
** Define a pile with a list of integers and her size.
*/
typedef struct		s_pile
{
	int				*p;
	size_t			size;
}					t_pile;

/*
** check_pile.c
*/
t_bool				check_pile(t_pile *pile, const char **list);

/*
** manage_pile.c
*/
t_pile				*new_pile(size_t size);
void				free_pile(t_pile *pile);
void				print_both(t_pile *p1, t_pile *p2);

/*
** get_piles.c
*/
int					*ft_sort_list(t_pile **piles);
t_pile				**get_piles(size_t size, const char **list);
const char			**check_str(const char *str, size_t *size);

/*
** tools.c
*/
t_bool				is_sorted(t_pile **piles);
void				ft_lstcpy(t_pile *pile, int *sortlist);
void				transform_pile(t_pile **piles);

/*
** push.c
*/
void				push(t_pile *add, t_pile *remove);

/*
** rotate.c
*/
void				rotate(t_pile *pile);

/*
** rrotate.c
*/
void				rrotate(t_pile *pile);

/*
** swap.c
*/
void				swap(t_pile *pile);

#endif
