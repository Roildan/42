/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:43 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/11 18:22:53 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa(t_pile *a)
{
	swap(a);
	ft_putendl("sa");
}

void		sb(t_pile *b)
{
	swap(b);
	ft_putendl("sb");
}

void		ss(t_pile *a, t_pile *b)
{
	swap(a);
	swap(b);
	ft_putendl("ss");
}
