/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:43:31 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/05 00:09:07 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

void	sorting(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size == 2)
		sort_2(stack);
	if (size == 3)
		sort_3(stack);
	if (size > 3 && size < 6)
		sort_5(stack);
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
	write(1, "\n", 1);
	print_stack(stack->a);
}
