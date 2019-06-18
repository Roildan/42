/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:09:00 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/10 17:38:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/main.h"

static t_bool	check_duplicate(t_pile *pile)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < pile->size - 1)
	{
		j = i + 1;
		while (j < pile->size)
		{
			if (pile->p[i] == pile->p[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool			check_pile(t_pile *pile, const char **list)
{
	long	nb;
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		nb = ft_atol(list[i]);
		if (nb == 0)
		{
			if (list[i][0] == '-')
			{
				if (list[i][1] != '0')
					return (FALSE);
			}
			else if (list[i][0] != '0')
				return (FALSE);
		}
		if (nb > INT_MAX || nb < INT_MIN)
			return (FALSE);
		pile->p[i] = (int)nb;
		i++;
	}
	return (check_duplicate(pile));
}
