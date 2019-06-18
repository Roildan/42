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

#include "../includes/main.h"

void	rrotate(t_pile *pile)
{
	size_t	i;
	int		temp;

	if (pile->size < 2)
		return ;
	temp = pile->p[pile->size - 1];
	i = pile->size;
	while (--i)
		pile->p[i] = pile->p[i - 1];
	pile->p[i] = temp;
}
