/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:46 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:51:47 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a, int checker)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (checker)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int checker)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if (checker)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int checker)
{
	sa(a, 0);
	sb(b, 0);
	if (checker)
		write(1, "ss\n", 3);
}
