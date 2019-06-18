/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:55:07 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/29 16:25:28 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "main.h"

/*
** tools.c
*/
void	exit_msg(const char *str, t_pile **piles);
void	sort_mano(t_pile **piles);
void	sort_mano_b(t_pile **piles);
void	sort_mano_big(t_pile **piles);
int		get_max(t_pile *pile, int size);
void	small_swap(t_pile **piles, t_bool boolean);

/*
** cchiant.c
*/
void	sorting_a(t_pile **piles, int size);

/*
** swap.c
*/
void	sa(t_pile *a);
void	sb(t_pile *b);
void	ss(t_pile *a, t_pile *b);

/*
** push.c
*/
void	pa(t_pile *a, t_pile *b);
void	pb(t_pile *a, t_pile *b);

/*
** rotate.c
*/
void	ra(t_pile *a);
void	rb(t_pile *b);
void	rr(t_pile *a, t_pile *b);

/*
** rrotate.c
*/
void	rra(t_pile *a);
void	rrb(t_pile *b);
void	rrr(t_pile *a, t_pile *b);

#endif
