/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:59:37 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/10 14:04:16 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_clist	*new_elem(t_opp opp, char *name)
{
	t_clist	*new;

	if (!(new = (t_clist *)ft_memalloc(sizeof(t_clist))))
		return (NULL);
	new->opp = opp;
	ft_strncpy(new->name, name, 4);
	new->next = NULL;
	return (new);
}

t_clist	*add_elem(t_clist *list, t_clist *elem)
{
	t_clist	*curr;

	if (!list)
		return (elem);
	curr = list;
	while (curr->next)
		curr = curr->next;
	curr->next = elem;
	return (list);
}

void	free_list(t_clist *list)
{
	t_clist	*temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}
