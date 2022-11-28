/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utills.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:41:33 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/26 19:49:37 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainlib.h"

void	free_stack(t_stack *stack)
{
	t_list	*start;
	t_list	*next;

	while (stack && stack->a)
	{
		start = stack->a;
		next = stack->a;
		while (next->next)
		{
			start = next;
			next = next->next;
		}
		if (start == next)
		{
			free(stack->a);
			stack->a = NULL;
		}
		else
		{
			start->next = NULL;
			free(next);
		}
	}
	free(stack);
}

void	shift_rotate(t_list **list)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

	if (!(*list)->next)
		return ;
	start = (*list)->next;
	cur = *list;
	iter = ft_lstlast(*list);
	iter->next = cur;
	cur->next = NULL;
	*list = start;
}

void	shift_rev_rotate(t_list **list)
{
	t_list	*iter;
	t_list	*start;
	t_list	*cur;

	cur = *list;
	iter = *list;
	while (iter->next->next)
		iter = iter->next;
	start = iter->next;
	iter->next = NULL;
	start->next = cur;
	*list = start;
}

int	pb(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	if (!stack->b)
		stack->b = tmp;
	else
		ft_lstadd_front(&stack->b, tmp);
	return (0);
}

int	pa(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	if (!stack->a)
		stack->a = tmp;
	else
		ft_lstadd_front(&stack->a, tmp);
	return (0);
}
