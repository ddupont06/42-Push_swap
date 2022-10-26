/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:36 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:51:37 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **a, int checker)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	if (checker)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int checker)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	if (checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int checker)
{
	rra(a, 0);
	rrb(b, 0);
	if (checker)
		write(1, "rrr\n", 4);
}
