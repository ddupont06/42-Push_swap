/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupont <ddupont@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:52:07 by ddupont           #+#    #+#             */
/*   Updated: 2022/10/22 18:46:26 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	int				index_of_num;
	struct s_list	*next;
}		t_list;

// swap.c
void	sa(t_list **a, int checker);
void	sb(t_list **b, int checker);
void	ss(t_list **a, t_list **b, int checker);

// push.c
void	pa(t_list **a_dest, t_list **b_src, int checker);
void	pb(t_list **b_dest, t_list **a_src, int checker);

// rotate.c
void	ra(t_list **a, int checker);
void	rb(t_list **b, int checker);
void	rr(t_list **a, t_list **b, int checker);

// reverse_rotate.c
void	rra(t_list **a, int checker);
void	rrb(t_list **b, int checker);
void	rrr(t_list **a, t_list **b, int checker);

// ft_lists.c
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, t_list *new);
t_list	*ft_list_new(int number, int index_of_num);
void	ft_list_clear(t_list **list);

// common_utils.c
int		num_are_sorted(t_list *a);
long	ft_atoi(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error(t_list **a, t_list **b, int checker);

// ft_split.c
size_t	count_words(char const *s, char c);
char	**ft_split(char const *s, char c);
void	free_split(char **tab);

// parsing.c
void	parse_arg(t_list **a, char **arg, int ac);

// get_next_line_utils_bonus.c
int		nl_isin(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		is_valid_buff(char *buff);
size_t	ft_strlen(const char *s);

// get_next_line_bonus.c
char	*get_next_line(int fd);

#endif
