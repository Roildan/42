/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:58 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/10 18:59:21 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ra(t_pile *a)
{
	rotate(a);
	ft_putendl("ra");
}

void		rb(t_pile *b)
{
	rotate(b);
	ft_putendl("rb");
}

void		rr(t_pile *a, t_pile *b)
{
	rotate(a);
	rotate(b);
	ft_putendl("rr");
}
