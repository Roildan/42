/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:26:03 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/10 18:59:48 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rra(t_pile *a)
{
	rrotate(a);
	ft_putendl("rra");
}

void		rrb(t_pile *b)
{
	rrotate(b);
	ft_putendl("rrb");
}

void		rrr(t_pile *a, t_pile *b)
{
	rrotate(a);
	rrotate(b);
	ft_putendl("rrr");
}
