/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:51:06 by ddupont           #+#    #+#             */
/*   Updated: 2022/05/18 14:51:08 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	nl_isin(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(*str) * 1);
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	return (0);
}

int	is_valid_buff(char *buff)
{
	if (!ft_memcmp(buff, "sa\n", 3) || !ft_memcmp(buff, "sb\n", 3)
		|| !ft_memcmp(buff, "ss\n", 3) || !ft_memcmp(buff, "pa\n", 3)
		|| !ft_memcmp(buff, "pb\n", 3) || !ft_memcmp(buff, "ra\n", 3)
		|| !ft_memcmp(buff, "rb\n", 3) || !ft_memcmp(buff, "rr\n", 3)
		|| !ft_memcmp(buff, "rra\n", 4) || !ft_memcmp(buff, "rrb\n", 4)
		|| !ft_memcmp(buff, "rrr\n", 4))
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
