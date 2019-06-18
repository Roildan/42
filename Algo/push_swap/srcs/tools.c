/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:16:51 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 17:52:07 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	is_sorted(t_pile **piles)
{
	size_t	i;
	t_pile	*pile;

	if (piles[1]->size)
		return (FALSE);
	pile = piles[0];
	i = 0;
	while (i < pile->size - 1)
	{
		if (pile->p[i] > pile->p[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	transform_pile(t_pile **piles)
{
	size_t	i;
	size_t	j;
	int		*sortlist;
	int		*newlist;

	i = 0;
	if (!(newlist = (int *)ft_memalloc(piles[0]->size * sizeof(int))))
		exit_msg(ERROR_MALLOC, piles);
	sortlist = ft_sort_list(piles);
	while (i < piles[0]->size)
	{
		j = 0;
		while (piles[0]->p[i] != sortlist[j])
			j++;
		newlist[i++] = j;
	}
	i = 0;
	while (i < piles[0]->size)
	{
		piles[0]->p[i] = newlist[i];
		i++;
	}
	free(sortlist);
	free(newlist);
}

void	ft_lstcpy(t_pile *pile, int *sortlist)
{
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		sortlist[i] = pile->p[i];
		i++;
	}
}
