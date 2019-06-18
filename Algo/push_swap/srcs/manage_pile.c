/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:52:18 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/11 12:20:24 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

t_pile	*new_pile(size_t size)
{
	t_pile *new;

	if (!(new = (t_pile *)ft_memalloc(sizeof(t_pile))))
		return (NULL);
	if (!(new->p = (int *)ft_memalloc(size * sizeof(int))))
	{
		free(new);
		return (NULL);
	}
	new->size = size;
	return (new);
}

void	free_pile(t_pile *pile)
{
	if (pile->p)
		free(pile->p);
	free(pile);
}

void	print_both(t_pile *p1, t_pile *p2)
{
	size_t	i;

	ft_printf("\nPile A:\t\tPile B:\n");
	i = 0;
	while (i < p1->size || i < p2->size)
	{
		ft_printf("%s\t\t%s\n", p1->size > i ? ft_itoa(p1->p[i]) : "Empty",
				p2->size > i ? ft_itoa(p2->p[i]) : "Empty");
		i++;
	}
	ft_printf("Size: %lu\t\tSize: %lu\n", p1->size, p2->size);
}
