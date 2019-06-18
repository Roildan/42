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

#include "../includes/checker.h"

void		rrotate_a(t_pile *a, t_pile *b)
{
	(void)b;
	rrotate(a);
}

void		rrotate_b(t_pile *a, t_pile *b)
{
	(void)a;
	rrotate(b);
}

void		rrotate_ab(t_pile *a, t_pile *b)
{
	rrotate(a);
	rrotate(b);
}
