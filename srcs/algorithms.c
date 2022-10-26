/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:50:27 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:50:29 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_values(t_list **a)
{
	while (!num_are_sorted(*a))
	{
		if ((*a)->index_of_num > (*a)->next->index_of_num
			&& (*a)->index_of_num < ft_list_last(*a)->index_of_num)
			sa(a, 1);
		else if ((*a)->index_of_num > (*a)->next->index_of_num
			&& (*a)->index_of_num > ft_list_last(*a)->index_of_num)
			ra(a, 1);
		else if (ft_list_last(*a)->index_of_num < (*a)->next->index_of_num)
			rra(a, 1);
	}
}

void	sort_5_values(t_list **a, t_list **b, int ac)
{
	int	index_of_num_to_find;

	index_of_num_to_find = 0;
	while (index_of_num_to_find <= 1)
	{
		while ((*a)->index_of_num != index_of_num_to_find)
		{
			if (lower_half_or_pos(*a, index_of_num_to_find, 0, ac))
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(b, a, 1);
		index_of_num_to_find++;
	}
	sort_3_values(a);
	pa(a, b, 1);
	pa(a, b, 1);
	if (!num_are_sorted(*a))
		sa(a, 1);
}

static	void	sort_large_b_sk(t_list **a, t_list **b, int max_index, int ac)
{
	int	lower_half_of_stack;
	int	place_of_num_in_stack;

	while (*b)
	{
		lower_half_of_stack = (max_index + 1) / 2;
		place_of_num_in_stack = lower_half_or_pos(*b, max_index, 1, ac);
		if ((*b)->index_of_num == max_index)
		{
			pa(a, b, 1);
			max_index--;
		}
		else if (place_of_num_in_stack <= lower_half_of_stack)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void	sort_large_stack(t_list **a, t_list **b, int interval, int ac)
{
	int	index_num_to_find;

	index_num_to_find = 0;
	while (*a)
	{
		if ((*a)->index_of_num <= index_num_to_find)
		{
			pb(b, a, 1);
			rb(b, 1);
			index_num_to_find++;
		}
		else if ((*a)->index_of_num <= (index_num_to_find + interval))
		{
			pb(b, a, 1);
			index_num_to_find++;
		}
		else if ((*a)->index_of_num >= index_num_to_find)
			ra(a, 1);
	}
	sort_large_b_sk(a, b, ac - 1, ac);
}

void	sort(t_list **a, int ac)
{
	t_list	*b;

	b = NULL;
	if (ac == 2)
		sa(a, 1);
	else if (ac == 3)
		sort_3_values(a);
	else if (ac == 4 || ac == 5)
		sort_5_values(a, &b, ac);
	else if (ac >= 6 && ac <= 100)
		sort_large_stack(a, &b, 13, ac);
	else if (ac >= 101)
		sort_large_stack(a, &b, 28, ac);
	error(a, &b, 0);
}
