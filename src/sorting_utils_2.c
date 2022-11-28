/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:57:04 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/26 20:11:43 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainlib.h"

void	sort_2(t_stack	*stack)
{
	if (stack->a->n > stack->a->next->n)
		swap(stack, 0);
}

void	sort_3(t_stack	*stack)
{
	if (sorting_check(stack->a) == 0)
		return ;
	else if (stack->a->n > stack->a->next->n
		&& stack->a->next->n > stack->a->next->next->n)
	{
		rotate(stack, 0);
		swap(stack, 0);
	}
	else if (stack->a->n > stack->a->next->n
		&& stack->a->next->n < stack->a->next->next->n)
	{
		rev_rotate(stack, 0);
		sort_3(stack);
	}
	else if (stack->a->n < stack->a->next->n
		&& stack->a->next->n > stack->a->next->next->n)
	{
		rev_rotate(stack, 0);
		if (sorting_check(stack->a) != 0)
			swap(stack, 0);
	}
}

int	get_min(t_list *list)
{
	t_list	*tmp;
	int		min;

	min = list->n;
	tmp = list->next;
	while (tmp)
	{
		if (min > tmp->n)
			min = tmp->n;
		tmp = tmp->next;
	}
	return (min);
}

void	push_min(t_stack *stack)
{
	int		min;
	t_list	*tmp;
	int		counter;

	counter = 1;
	tmp = stack->a;
	min = get_min(stack->a);
	while (tmp->n != min)
	{
		tmp = tmp->next;
		counter++;
	}
	if (counter > 2)
	{
		while (stack->a->n != min)
			rev_rotate(stack, 0);
	}
	else
		while (stack->a->n != min)
			rotate(stack, 0);
	push(stack, 1);
}

void	sort_5(t_stack	*stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size == 4)
	{
		push_min(stack);
	}
	else if (size == 5)
	{
		push_min(stack);
		push_min(stack);
	}
	sort_3(stack);
	if (size == 4)
		push(stack, 0);
	else
	{
		push(stack, 0);
		push(stack, 0);
	}
}
