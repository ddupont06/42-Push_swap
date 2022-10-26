/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:50:43 by ddupont           #+#    #+#             */
/*   Updated: 2022/10/21 20:18:55 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	num_are_sorted(t_list *a)
{
	t_list	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->index_of_num > tmp->next->index_of_num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	lower_half_or_pos(t_list *s, int index_to_find, int sort_big, int ac)
{
	int	count;
	int	half;

	count = 0;
	half = ac / 2;
	while (s)
	{
		if (s->index_of_num == index_to_find)
			break ;
		count++;
		s = s->next;
	}
	if (sort_big)
		return (count);
	else if (count > half)
		return (0);
	else
		return (1);
}

long	ft_atoi(const char *s)
{
	int		sign;
	long	result;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	sign = 1;
	if (*s == '-' || *s == '+')
	{	
		if (*s == '-')
			sign *= -1;
		s++;
	}
	result = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		result *= 10;
		result += *s++ - '0';
	}
	return (sign * result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	error(t_list **a, t_list **b, int checker)
{
	if (a)
		ft_list_clear(a);
	if (b)
		ft_list_clear(b);
	if (checker)
		write(2, "Error\n", 6);
	exit(0);
}
