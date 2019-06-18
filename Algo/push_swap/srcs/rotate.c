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

#include "../includes/main.h"

void	rotate(t_pile *pile)
{
	size_t	i;
	int		temp;

	if (pile->size < 2)
		return ;
	temp = pile->p[0];
	i = 0;
	while (i < pile->size - 1)
	{
		pile->p[i] = pile->p[i + 1];
		i++;
	}
	pile->p[i] = temp;
}
