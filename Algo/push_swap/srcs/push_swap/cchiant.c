/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cchiant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:20:08 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/29 16:41:15 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_bool	check(t_pile *pile, int pivot, int size, t_bool sup)
{
	int i;

	if (size < 2)
		return (FALSE);
	i = 0;
	while (i < size)
	{
		if (sup)
		{
			if (pile->p[i] > pivot)
				return (TRUE);
		}
		else if (pile->p[i] < pivot)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int		push_b(t_pile **piles, int pivot, int size)
{
	int		res;
	int		temp;
	int		i;

	res = 0;
	i = 0;
	temp = size;
	while (size)
	{
		small_swap(piles, TRUE);
		if (piles[0]->p[0] < pivot && ++res)
			pb(piles[0], piles[1]);
		else if (check(piles[0], pivot, size, FALSE))
		{
			ra(piles[0]);
			i++;
		}
		else
			break ;
		size--;
	}
	while (i-- && (int)piles[0]->size != temp - res)
		rra(piles[0]);
	return (res);
}

static int		push_a(t_pile **piles, int pivot, int size)
{
	int	res;
	int	temp;
	int	i;

	res = 0;
	i = 0;
	temp = size;
	while (size)
	{
		small_swap(piles, FALSE);
		if (piles[1]->p[0] > pivot && ++res)
			pa(piles[0], piles[1]);
		else if (check(piles[1], pivot, size, TRUE))
		{
			rb(piles[1]);
			i++;
		}
		else
			break ;
		size--;
	}
	while (i-- && (int)piles[1]->size != temp - res)
		rrb(piles[1]);
	return (res);
}

static void		sorting_b(t_pile **piles, int size)
{
	int	new_size;
	int	pivot;

	if (size < 3)
	{
		if (size == 2)
		{
			pa(piles[0], piles[1]);
			pa(piles[0], piles[1]);
			sorting_a(piles, size);
		}
		else if (size == 1)
			pa(piles[0], piles[1]);
		return ;
	}
	pivot = get_max(piles[1], size) - size / 2;
	new_size = push_a(piles, pivot, size);
	if (!new_size)
		return ;
	sorting_a(piles, new_size);
	sorting_b(piles, size - new_size);
}

void			sorting_a(t_pile **piles, int size)
{
	int	pivot;
	int	new_size;

	if (size < 5)
	{
		if (size == 4)
			sort_mano_big(piles);
		else if (size == 3)
			sort_mano(piles);
		else if (size == 2)
			if (piles[0]->p[0] > piles[0]->p[1])
				sa(piles[0]);
		return ;
	}
	pivot = get_max(piles[0], size) - size / 2;
	if (size % 2)
		pivot++;
	new_size = push_b(piles, pivot, size);
	sorting_a(piles, size - new_size);
	if (new_size)
		sorting_b(piles, new_size);
}
