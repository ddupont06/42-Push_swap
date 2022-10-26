/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:52:03 by ddupont           #+#    #+#             */
/*   Updated: 2022/10/22 18:46:02 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				number;
	int				index_of_num;
	struct s_list	*next;
}		t_list;

// swap.c
void	sa(t_list **a, int checker);

// push.c
void	pa(t_list **a_dest, t_list **b_src, int checker);
void	pb(t_list **b_dest, t_list **a_src, int checker);

// rotate.c
void	ra(t_list **a, int checker);
void	rb(t_list **b, int checker);

// reverse_rotate.c
void	rra(t_list **a, int checker);
void	rrb(t_list **b, int checker);
void	rrr(t_list **a, t_list **b, int checker);

// ft_lists.c
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, t_list *new);
t_list	*ft_list_new(int number, int index_of_num);
void	ft_list_clear(t_list **list);

// algorithms.c
void	sort_3_values(t_list **a);
void	sort_5_values(t_list **a, t_list **b, int ac);
void	sort_large_stack(t_list **a, t_list **b, int interval, int ac);
void	sort(t_list **a, int ac);

// common_utils.c
int		num_are_sorted(t_list *a);
int		lower_half_or_pos(t_list *s, int index_to_find, int sort_big, int ac);
long	ft_atoi(const char *s);
void	error(t_list **a, t_list **b, int checker);

// ft_split.c
size_t	count_words(char const *s, char c);
char	**ft_split(char const *s, char c);
void	free_split(char **tab);

// parsing.c
void	parse_arg(t_list **a, char **arg, int ac);

#endif
