/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:41:33 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/06 22:26:41 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainlib.h"

void	five_ra(t_stack *stack, int counter)
{
	int	counter_2;

	counter_2 = ft_lstsize(stack->a) - counter;
	printf("%d\n", counter_2);
	// sleep(10);
	while (--counter_2)
	{
		ft_rotate(&(stack->a));
	}
}

void	five_rra(t_stack *stack, int counter)
{
	int	counter_2;

	counter_2 = ft_lstsize(stack->a) - counter + 2;
	while (--counter_2)
		ft_rev_rotate(&(stack->a));
}

void	ft_rotate(t_list **ptr)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(*ptr);
	temp = (*ptr)->next;
	(*ptr)->next = NULL;
	last->next = (*ptr);
	(*ptr)->next = NULL;
	*ptr = temp;
}

void	ft_rev_rotate(t_list **ptr)
{
	t_list	*last;

	last = ft_lstlast(*ptr);
	last->next = *ptr;
	*ptr = last;
}
