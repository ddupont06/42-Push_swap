/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:22 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:51:23 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a_dest, t_list **b_src, int checker)
{
	t_list	*tmp;

	if (!*b_src)
		return ;
	tmp = *b_src;
	*b_src = tmp->next;
	tmp->next = *a_dest;
	*a_dest = tmp;
	if (checker)
		write(1, "pa\n", 3);
}

void	pb(t_list **b_dest, t_list **a_src, int checker)
{
	t_list	*tmp;

	if (!*a_src)
		return ;
	tmp = *a_src;
	*a_src = tmp->next;
	tmp->next = *b_dest;
	*b_dest = tmp;
	if (checker)
		write(1, "pb\n", 3);
}
