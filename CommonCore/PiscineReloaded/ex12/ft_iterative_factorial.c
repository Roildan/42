/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:23:37 by armoulin          #+#    #+#             */
/*   Updated: 2018/11/06 14:38:46 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb < 2)
		return (1);
	res = nb;
	while (--nb > 1)
		res *= nb;
	return (res);
}
