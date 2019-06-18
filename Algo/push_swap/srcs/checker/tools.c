/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:59:59 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 18:08:59 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void		duplicate_piles(t_pile **piles, t_pile **sort)
{
	ft_lstcpy(piles[0], sort[0]->p);
	transform_pile(sort);
}

static t_bool	get_opt(const char *opt, t_check *check, size_t *size)
{
	check->g = FALSE;
	check->v = FALSE;
	if (*opt == '-')
	{
		opt++;
		if (*opt == 'g')
			check->g = TRUE;
		if (*opt == 'v')
			check->v = TRUE;
		if (opt)
		{
			opt++;
			if (*opt == 'g')
				check->g = TRUE;
			if (*opt == 'v')
				check->v = TRUE;
		}
	}
	if (check->g || check->v)
	{
		(*size)--;
		return (TRUE);
	}
	return (FALSE);
}

static void		init_check(t_check *check, size_t size, const char **tab)
{
	if (!(check->piles[0] = new_pile(size)))
		exit_msg(ERROR_MALLOC, check);
	if (!(check->piles[1] = new_pile(size)))
		exit_msg(ERROR_MALLOC, check);
	check->piles[1]->size = 0;
	if (!(check->sort[0] = new_pile(size)))
		exit_msg(ERROR_MALLOC, check);
	if (!(check->sort[1] = new_pile(size)))
		exit_msg(ERROR_MALLOC, check);
	check->sort[1]->size = 0;
	if (!check_pile(check->piles[0], tab))
		exit_msg(ERROR, check);
}

t_check			*get_check(size_t size, const char **tab)
{
	t_check	*check;
	t_bool	to_be_free;
	int		i;

	if (!(check = (t_check *)ft_memalloc(sizeof(t_check))))
		exit_msg(ERROR_MALLOC, NULL);
	tab += get_opt(*tab, check, &size);
	to_be_free = FALSE;
	if (size == 1)
	{
		to_be_free = TRUE;
		tab = check_str(*tab, &size);
	}
	init_check(check, size, tab);
	if (to_be_free)
	{
		i = 0;
		while (tab[i])
			free((void *)tab[i++]);
		free(tab);
	}
	duplicate_piles(check->piles, check->sort);
	check->nb_op = 0;
	return (check);
}

void			exit_msg(const char *str, t_check *check)
{
	if (check)
	{
		if (check->piles[0])
			free_pile(check->piles[0]);
		if (check->piles[1])
			free_pile(check->piles[1]);
		if (check->list)
			free_list(check->list);
		free(check);
	}
	ft_putendl(str);
	exit(-1);
}
