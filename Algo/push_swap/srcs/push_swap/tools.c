/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:16:51 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/29 16:50:57 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exit_msg(const char *str, t_pile **piles)
{
	if (piles)
	{
		if (piles[0])
			free_pile(piles[0]);
		if (piles[1])
			free_pile(piles[1]);
	}
	ft_putendl(str);
	exit(-1);
}

void	sort_mano(t_pile **piles)
{
	if (piles[0]->p[0] < piles[0]->p[1] && piles[0]->p[1] < piles[0]->p[2])
		return ;
	if (piles[0]->p[0] > piles[0]->p[1])
	{
		sa(piles[0]);
		return (sort_mano(piles));
	}
	if (piles[0]->p[piles[0]->size - 1] == 0)
	{
		rra(piles[0]);
		return (sort_mano(piles));
	}
	if (piles[0]->p[1] > piles[0]->p[2])
	{
		ra(piles[0]);
		sa(piles[0]);
		rra(piles[0]);
		return (sort_mano(piles));
	}
}

void	sort_mano_big(t_pile **piles)
{
	int	i;

	pb(piles[0], piles[1]);
	sort_mano(piles);
	i = 0;
	while (piles[1]->p[0] != piles[0]->p[0] - 1)
	{
		ra(piles[0]);
		i++;
	}
	pa(piles[0], piles[1]);
	while (i--)
		rra(piles[0]);
}

void	small_swap(t_pile **piles, t_bool boolean)
{
	if (boolean)
	{
		if (piles[0]->p[0] == piles[0]->p[1] + 1)
		{
			if (piles[1]->size > 1 && piles[1]->p[0] == piles[1]->p[1] - 1)
				ss(piles[0], piles[1]);
			else
				sa(piles[0]);
		}
	}
	else
	{
		if (piles[1]->p[0] == piles[1]->p[1] - 1)
		{
			if (piles[0]->size > 1 && piles[0]->p[0] == piles[0]->p[1] + 1)
				ss(piles[0], piles[1]);
			else
				sb(piles[1]);
		}
	}
}

int		get_max(t_pile *pile, int size)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (pile->p[i] > max)
			max = pile->p[i];
		i++;
	}
	return (max);
}
