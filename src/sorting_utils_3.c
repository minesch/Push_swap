/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:41:33 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/22 22:12:39 by azakarya         ###   ########.fr       */
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

void	ft_rotate(t_list **ptr)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(*ptr);
	temp = (*ptr);
	(*ptr) = (*ptr)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ft_rev_rotate(t_list **ptr)
{
	t_list	*prelast;
	t_list	*last;

	prelast = ft_lstprelast(*ptr);
	last = ft_lstlast(*ptr);
	prelast->next = NULL;
	last->next = *ptr;
	*ptr = last;
}
