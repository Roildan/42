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

#include "../includes/checker.h"

void		rotate_a(t_pile *a, t_pile *b)
{
	(void)b;
	rotate(a);
}

void		rotate_b(t_pile *a, t_pile *b)
{
	(void)a;
	rotate(b);
}

void		rotate_ab(t_pile *a, t_pile *b)
{
	rotate(a);
	rotate(b);
}
