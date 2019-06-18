/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:36:44 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/07 12:23:52 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	if (!(new = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
