/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:43:31 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/22 00:10:37 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

int	get_closer(int size)
{
	if (size <= 100)
		return ((15 * size) / 100);
	else
		return ((30 * size) / 100);
}

void	sort_rest_a(t_stack *stack)
{
	int	size;
	int	ind_range;
	int	count;

	size = ft_lstsize(stack->a);
	while (stack->a)
	{
		ind_range = get_closer(size);
		if (stack->a->index <= count)
		{
			push(stack, 1);
			rotate(stack, 1);
			count++;
		}
		else if (stack->a->index <= count + ind_range)
		{
			push(stack, 1);
			count++;
		}
		else
			rotate(stack, 0);
	}
}

void	sort_rest_b(t_stack *stack)
{
	int	size;
	int	ind_range;
	int	count;

	count = 0;
	size = ft_lstsize(stack->b);
	while (stack->b)
	{

	}
}

void	sorting(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size == 2)
		sort_2(stack);
	else if (size == 3)
		sort_3(stack);
	else if (size > 3 && size < 6)
		sort_5(stack);
	else
		sort_rest(stack);
}

void	push_swap(t_stack *stack)
{
	if (sorting_check(stack->a) == 0)
	{
		free(stack->a);
		return ;
	}
	indexing(stack->a);
	sorting(stack);
}
