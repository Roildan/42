/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:40:30 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 17:51:10 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *list, size_t i)
{
	int	temp;

	temp = list[i];
	list[i] = list[i + 1];
	list[i + 1] = temp;
}

int			*ft_sort_list(t_pile **piles)
{
	size_t	i;
	int		*sortlist;

	if (!(sortlist = (int *)ft_memalloc(sizeof(int) * piles[0]->size)))
		exit_msg(ERROR_MALLOC, piles);
	ft_lstcpy(piles[0], sortlist);
	i = 0;
	while (i < piles[0]->size - 1)
	{
		if (sortlist[i] > sortlist[i + 1])
		{
			ft_swap(sortlist, i);
			i = 0;
		}
		else
			i++;
	}
	return (sortlist);
}

const char	**check_str(const char *str, size_t *size)
{
	const char	**list;
	int			i;

	list = (const char **)ft_strsplit(str, ' ');
	i = 0;
	while (list[i])
		i++;
	*size = i;
	return (list);
}

static void	init_piles(t_pile **piles, size_t size, const char **list)
{
	if (!(piles[0] = new_pile(size)))
		exit_msg(ERROR_MALLOC, piles);
	if (!(piles[1] = new_pile(size)))
		exit_msg(ERROR_MALLOC, piles);
	piles[1]->size = 0;
	if (!(check_pile(piles[0], list)))
		exit_msg(ERROR, piles);
}

t_pile		**get_piles(size_t size, const char **list)
{
	t_pile		**piles;
	t_bool		to_be_free;
	int			i;

	to_be_free = FALSE;
	if (!(piles = (t_pile **)ft_memalloc(sizeof(t_pile *) * 2)))
		exit_msg(ERROR_MALLOC, piles);
	if (size == 1)
	{
		to_be_free = TRUE;
		list = check_str(*list, &size);
	}
	init_piles(piles, size, list);
	if (to_be_free)
	{
		i = 0;
		while (list[i])
			free((void *)list[i++]);
		free(list);
	}
	transform_pile(piles);
	return (piles);
}
