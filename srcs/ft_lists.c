/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:50:48 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:50:50 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_list_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_list_add_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (!list || !new)
		return ;
	tmp = ft_list_last(*list);
	if (!tmp)
		*list = new;
	else
		tmp->next = new;
}

t_list	*ft_list_new(int number, int index_of_num)
{
	t_list	*new;

	new = malloc (sizeof(*new));
	if (!new)
		return (NULL);
	new->number = number;
	new->index_of_num = index_of_num;
	new->next = NULL;
	return (new);
}

static void	ft_list_del_one(t_list *list)
{
	if (!list)
		return ;
	free(list);
}

void	ft_list_clear(t_list **list)
{
	t_list	*next;

	if (!list || !*list)
		return ;
	next = (*list)->next;
	ft_list_del_one(*list);
	ft_list_clear(&next);
	*list = NULL;
}
