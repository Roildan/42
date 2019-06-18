/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:03:21 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/06 16:14:06 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *res;
	int i;

	if (min >= max)
		return (NULL);
	if (!(res = (int *)malloc((max - min) * sizeof(int))))
		return (NULL);
	i = 0;
	while (min < max)
		res[i++] = min++;
	return (res);
}
