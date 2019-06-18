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

#include "../includes/checker.h"

void		swap_a(t_pile *a, t_pile *b)
{
	(void)b;
	swap(a);
}

void		swap_b(t_pile *a, t_pile *b)
{
	(void)a;
	swap(b);
}

void		swap_ab(t_pile *a, t_pile *b)
{
	swap(a);
	swap(b);
}
