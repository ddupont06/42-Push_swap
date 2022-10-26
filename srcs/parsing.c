/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:13 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:51:14 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_arg(char *arg)
{
	size_t	i;

	i = 0;
	if (!arg[i])
		return (0);
	if (arg[i] == '-' && arg[i + 1] == '0')
		return (0);
	if (arg[i] == '-' && arg[i + 1] != '\0')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9' || arg[i] == '-' || arg[i] == '+')
			return (0);
		i++;
	}
	if (ft_atoi(arg) < INT_MIN || ft_atoi(arg) > INT_MAX)
		return (0);
	return (1);
}

static int	is_duplicated(int *tab, int i, int value)
{
	while (i >= 0)
		if (tab[i--] == value)
			return (1);
	return (0);
}

static void	sort_tab(int *tab, int ac)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < ac - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	}
}

static void	create_list(t_list **a, char **arg, int *tab, int ac)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i])
	{
		j = -1;
		while (++j < ac)
		{
			if (ft_atoi(arg[i]) == tab[j])
				ft_list_add_back(a, ft_list_new(tab[j], j));
		}
	}
}

void	parse_arg(t_list **a, char **arg, int ac)
{
	int	i;
	int	*tab;

	i = -1;
	tab = malloc(sizeof(*tab) * ac);
	while (++i < ac)
	{
		if (!is_valid_arg(arg[i]))
		{
			free(tab);
			error(NULL, NULL, 1);
		}
		tab[i] = ft_atoi(arg[i]);
		if (is_duplicated(tab, i - 1, tab[i]))
		{
			free(tab);
			error(NULL, NULL, 1);
		}
	}
	sort_tab(tab, ac);
	create_list(a, arg, tab, ac);
	free(tab);
}
