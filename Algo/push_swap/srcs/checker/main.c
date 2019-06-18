/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:20:04 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/26 17:22:47 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphic.h"

static void		apply_opp(t_check *check)
{
	t_clist	*current;

	current = check->list;
	while (current)
	{
		if (check->v)
			ft_printf("\nApplying %s\n", current->name);
		current->opp(check->piles[0], check->piles[1]);
		current->opp(check->sort[0], check->sort[1]);
		if (check->v)
			print_both(check->piles[0], check->piles[1]);
		current = current->next;
	}
}

static void		graphic(t_check *check)
{
	t_mlx	*mlx;

	mlx = init_mlx(check);
	setup_interactions(mlx);
	mlx_loop(mlx->mlx);
}

static void		get_list(t_check *check)
{
	t_clist	*list;
	char	*line;

	list = NULL;
	while (get_next_line(0, &line))
	{
		if (!check_opp(line, &list))
		{
			free(line);
			free_list(list);
			exit_msg(ERROR, check);
		}
		free(line);
	}
	check->list = list;
}

int				main(int ac, const char **av)
{
	t_check	*check;

	if (ac < 2)
		return (0);
	check = get_check((size_t)(ac - 1), av + 1);
	get_list(check);
	if (!check->piles[0]->size)
		exit_msg(ERROR, check);
	if (check->v)
	{
		ft_printf("\nInitial State:\n");
		print_both(check->piles[0], check->piles[1]);
	}
	if (check->g)
		graphic(check);
	else
	{
		apply_opp(check);
		if (is_sorted(check->piles))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
