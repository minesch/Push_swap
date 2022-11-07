/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:57:04 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/06 22:28:35 by azakarya         ###   ########.fr       */
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
	if (stack->a->n > stack->a->next->n && stack->a->next->next->n < stack->a->n
		&& stack->a->next->next->n < stack->a->next->n)
		rotate(stack, 0);
	if (stack->a->n > stack->a->next->n && stack->a->next->next->n > stack->a->n
		&& stack->a->next->next->n > stack->a->next->n)
		swap(stack, 0);
	if (stack->a->n < stack->a->next->n && stack->a->n < stack->a->next->next->n
		&& stack->a->next->n > stack->a->next->next->n)
	{
		rotate(stack, 0);
		sort_3(stack);
	}
	if (stack->a->n > stack->a->next->n && stack->a->n > stack->a->next->next->n
		&& stack->a->next->n > stack->a->next->next->n)
	{
		swap(stack, 0);
		sort_3(stack);
	}
	if (stack->a->n > stack->a->next->n && stack->a->n > stack->a->next->next->n
		&& stack->a->next->n < stack->a->next->next->n)
	{
		rotate(stack, 0);
		sort_3(stack);
	}
}

void	four(t_stack *stack, int b)
{
	int		counter;
	t_list	*tmp;

	tmp = stack->a;
	if (b == 0)
		counter = 1;
		while (tmp->index != b)
		{
			tmp = tmp->next;
			counter++;
		}
		if (counter == 4)
			rev_rotate(stack, 0);
		else
		{
			while (--counter)
				rotate(stack, 0);
		}
	push(stack, 1);
	sort_3(stack);
	push(stack, 0);
}

void	five(t_stack *stack)
{
	int	counter;
	int	counter_2;

	if (ft_lstsize(stack->a) == 5)
	{
		counter = 2;
		while (stack->a->index != 0)
		{
			stack->a = stack->a->next;
			counter++;
		}
		if (--counter > 4)
			five_rra(stack, counter);
		else
			five_ra(stack, counter);
		push(stack, 1);
		printf("gag\n");
		four(stack, 1);
	}
	else
		four(stack, 0);
}

void	sort_5(t_stack	*stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size > 3)
		five(stack);
}
