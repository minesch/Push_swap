/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:43:31 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/22 22:03:43 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

// int	get_closer(int size)
// {
// 	if (size <= 100)
// 		return ((15 * size) / 100);
// 	else
// 		return ((30 * size) / 100);
// }

// void	sort_rest_b(t_stack *stack)
// {
// 	int	size;
// 	int	ind_range;
// 	int	count;

// 	if (sorting_check(stack->a) == 0)
// 		return ;
// 	size = ft_lstsize(stack->a);
// 	while (stack->a)
// 	{
// 		ind_range = get_closer(size);
// 		if (stack->a->index <= count)
// 		{
// 			push(stack, 1);
// 			rotate(stack, 1);
// 			count++;
// 		}
// 		else if (stack->a->index <= count + ind_range)
// 		{
// 			push(stack, 1);
// 			count++;
// 		}
// 		else
// 			rotate(stack, 0);
// 	}
// 	sort_rest_a(stack);
// }

// void	sort_rest_a(t_stack *stack)
// {
// 	t_list		*first;
// 	long int	place;
// 	long int	sz;

// 	sz = ft_lstsize(stack->b);
// 	place = 0;
// 	while (stack->b)
// 	{
// 		first = stack->b;
// 		while (sz - 1 != stack->b->index)
// 		{
// 			place++;
// 			stack->b = stack->b->next;
// 		}
// 		stack->b = first;
// 		if (place <= sz / 2)
// 			while (stack->b->index != sz - 1)
// 				rotate(stack, 1);
// 		else if (place > sz / 2)
// 			while (stack->b->index != sz - 1)
// 				rev_rotate(stack, 1);
// 		push(stack, 1);
// 		place = 0;
// 		sz--;
// 	}
// }

void	sorting(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	printf("gag\n ");
	if (size == 2)
		sort_2(stack);
	else if (size == 3)
		sort_3(stack);
	else if (size > 3 && size < 6)
		sort_5(stack);

	// else
	// 	sort_rest_b(stack);
}

void	push_swap(t_stack *stack)
{
	indexing(stack->a);
	sorting(stack);
}
