/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:42 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:51:43 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a, int checker)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_list_add_back(a, tmp);
	if (checker)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int checker)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_list_add_back(b, tmp);
	if (checker)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int checker)
{
	ra(a, 0);
	rb(b, 0);
	if (checker)
		write(1, "rr\n", 3);
}
