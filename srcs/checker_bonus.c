/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:50:34 by ddupont           #+#    #+#             */
/*   Updated: 2022/10/22 18:54:13 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	parse_operation_2(char *buff, t_list **a, t_list **b)
{
	if (!ft_strncmp(buff, "rra\n", 5))
		rra(a, 0);
	else if (!ft_strncmp(buff, "rrb\n", 5))
		rrb(b, 0);
	else if (!ft_strncmp(buff, "rrr\n", 5))
		rrr(a, b, 0);
	else
	{
		free(buff);
		error(a, b, 1);
	}
}

static void	parse_operation_1(char *buff, t_list **a, t_list **b)
{
	if (!ft_strncmp(buff, "sa\n", 4))
		sa(a, 0);
	else if (!ft_strncmp(buff, "sb\n", 4))
		sb(b, 0);
	else if (!ft_strncmp(buff, "ss\n", 4))
		ss(a, b, 0);
	else if (!ft_strncmp(buff, "pa\n", 4))
		pa(a, b, 0);
	else if (!ft_strncmp(buff, "pb\n", 4))
		pb(b, a, 0);
	else if (!ft_strncmp(buff, "ra\n", 4))
		ra(a, 0);
	else if (!ft_strncmp(buff, "rb\n", 4))
		rb(b, 0);
	else if (!ft_strncmp(buff, "rr\n", 4))
		rr(a, b, 0);
	else
		return (parse_operation_2(buff, a, b));
}

static void	user_input(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		parse_operation_1(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

static int	str_has_digit(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			return (1);
		s++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**tab;

	a = NULL;
	b = NULL;
	if (ac == 1)
		error(NULL, NULL, 0);
	if (ac == 2 && str_has_digit(av[1]))
	{
		tab = ft_split(av[1], ' ');
		parse_arg(&a, tab, count_words(av[1], ' '));
		free_split(tab);
	}
	else
		parse_arg(&a, av + 1, ac - 1);
	user_input(&a, &b);
	if (!num_are_sorted(a) || (num_are_sorted(a) && b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	error(&a, &b, 0);
}
