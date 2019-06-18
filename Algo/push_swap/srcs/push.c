/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:51 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/11 19:55:49 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	push(t_pile *add, t_pile *remove)
{
	size_t	i;
	int		temp;

	if (remove->size == 0)
		return ;
	if (add->size)
		temp = add->p[0];
	add->size++;
	add->p[0] = remove->p[0];
	i = add->size - 1;
	while (i > 1)
	{
		add->p[i] = add->p[i - 1];
		i--;
	}
	if (add->size > 1)
		add->p[i] = temp;
	i = 0;
	if (remove->size > 1)
		while (i < remove->size - 1)
		{
			remove->p[i] = remove->p[i + 1];
			i++;
		}
	remove->size--;
}
