/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:30 by ddupont           #+#    #+#             */
/*   Updated: 2022/10/22 18:49:58 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*s;
	char	**tab;
	size_t	count;

	s = NULL;
	if (ac == 1)
		error(NULL, NULL, 0);
	if (ac == 2)
	{	
		tab = ft_split(av[1], ' ');
		count = count_words(av[1], ' ');
		parse_arg(&s, tab, count);
		free_split(tab);
	}
	else
		parse_arg(&s, av + 1, ac - 1);
	if (num_are_sorted(s))
		error(&s, NULL, 0);
	if (ac == 2)
		sort(&s, count);
	else
		sort(&s, ac - 1);
}
