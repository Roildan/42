/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:57:00 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/04/25 16:07:42 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	replace(t_pile **piles)
{
	size_t	i_ra;
	size_t	i_rra;

	i_ra = 0;
	while (piles[0]->p[i_ra])
		i_ra++;
	i_rra = 0;
	while (piles[0]->p[piles[0]->size - 1 - i_rra])
		i_rra++;
	if (i_ra < i_rra)
		while (!is_sorted(piles))
			ra(piles[0]);
	else
		while (!is_sorted(piles))
			rra(piles[0]);
}

int		main(int ac, const char **av)
{
	t_pile	**piles;

	if (ac == 1)
		return (0);
	piles = get_piles(ac - 1, av + 1);
	if (is_sorted(piles))
		return (0);
	sorting_a(piles, (int)piles[0]->size);
	replace(piles);
	return (0);
}
