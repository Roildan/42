/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:51 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/25 16:07:58 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_pile *a, t_pile *b)
{
	push(a, b);
	ft_putendl("pa");
}

void	pb(t_pile *a, t_pile *b)
{
	push(b, a);
	ft_putendl("pb");
}
