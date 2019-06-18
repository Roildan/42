/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:25:57 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/10 12:59:54 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static t_bool	get_swap(const char *str, t_clist **list)
{
	if (*str == 'a')
		*list = add_elem(*list, new_elem(swap_a, "sa"));
	else if (*str == 'b')
		*list = add_elem(*list, new_elem(swap_b, "sb"));
	else if (*str == 's')
		*list = add_elem(*list, new_elem(swap_ab, "ss"));
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	get_push(const char *str, t_clist **list)
{
	if (*str == 'a')
		*list = add_elem(*list, new_elem(push_a, "pa"));
	else if (*str == 'b')
		*list = add_elem(*list, new_elem(push_b, "pb"));
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	get_rotate(const char *str, t_clist **list)
{
	if (*str == 'a')
		*list = add_elem(*list, new_elem(rotate_a, "ra"));
	else if (*str == 'b')
		*list = add_elem(*list, new_elem(rotate_b, "rb"));
	else if (*str == 'r')
		*list = add_elem(*list, new_elem(rotate_ab, "rr"));
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	get_rrotate(const char *str, t_clist **list)
{
	if (*str == 'a')
		*list = add_elem(*list, new_elem(rrotate_a, "rra"));
	else if (*str == 'b')
		*list = add_elem(*list, new_elem(rrotate_b, "rrb"));
	else if (*str == 'r')
		*list = add_elem(*list, new_elem(rrotate_ab, "rrr"));
	else
		return (FALSE);
	return (TRUE);
}

t_bool			check_opp(const char *str, t_clist **list)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 2)
	{
		if (*str == 's')
			return (get_swap(str + 1, list));
		else if (*str == 'p')
			return (get_push(str + 1, list));
		else if (*str == 'r')
			return (get_rotate(str + 1, list));
	}
	else if (len == 3)
		if (*str == 'r' && *(str + 1) == 'r')
			return (get_rrotate(str + 2, list));
	return (FALSE);
}
