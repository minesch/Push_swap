/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:41:38 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/26 19:15:52 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINLIB_H
# define MAINLIB_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

//utils.c
char	*join_str(char *s1, char *s2);
void	free_dp(char ***group);
t_stack	*make_stack(char ***group);

//validation.c
char	**join_args(int ac, char **av);
char	*limits_check(char *str);
int		arg_check(char **group);
int		atoi_check(char *str);

//rules.c
void	push(t_stack *stack, int b);
void	swap(t_stack *stack, int b);
void	rotate(t_stack *stack, int b);
void	rev_rotate(t_stack *stack, int b);

//rules_utils.c
void	free_stack(t_stack *stack);
void	shift_rev_rotate(t_list **list);
void	shift_rotate(t_list **list);
int		ft_pb(t_stack *stack);
int		ft_pa(t_stack *stack);
// void	ft_rotate(t_list *ptr);
// void	ft_rev_rotate(t_list *ptr);

//sorting.c
int		get_range(int size);
void	push_swap(t_stack *stack);
void	sorting(t_stack *stack);
void	sort_rest_b(t_stack *stack);
void	sort_rest_a(t_stack *stack);

//sorting_utils_1.c
int		sorting_check(t_list *a);
void	indexing(t_list *a);
void	index_neg(t_list *a);
void	print_stack(t_list *a);
t_list	*find_smallest(t_list *a);

//sorting_utils_2.c
int		get_min(t_list *list);
void	push_min(t_stack *stack);
void	sort_2(t_stack	*stack);
void	sort_3(t_stack	*stack);
void	sort_5(t_stack	*stack);

#endif
