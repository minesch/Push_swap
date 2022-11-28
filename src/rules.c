/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:51:29 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/26 20:08:32 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

void	swap(t_stack *stack, int b)
{
	t_list	*tmp;

	if ((b == 0 || b == 2)
		&& (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0))
	{
		tmp = stack->a->next;
		stack->a->next = stack->a;
		stack->a = tmp;
		if (b == 0)
			write(1, "sa\n", 3);
	}
	if ((b == 1 || b == 2)
		&& (ft_lstsize(stack->b) != 1 || ft_lstsize(stack->b) != 0))
	{
		tmp = stack->b->next;
		stack->b->next = stack->b;
		stack->b = tmp;
		if (b == 1)
			write(1, "sb\n", 3);
	}
	if (b == 2)
		write(1, "ss\n", 3);
}

void	push(t_stack *stack, int b)
{
	if (b != 0 && b != 1)
		return ;
	if (stack->b != NULL && b == 0)
	{
		pa(stack);
		write(1, "pa\n", 3);
	}
	else if (stack->a != NULL && b == 1)
	{
		pb(stack);
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stack *stack, int b)
{
	if (b == 0)
	{
		shift_rotate(&(stack)->a);
		write(1, "ra\n", 3);
	}
	else if (b == 1)
	{
		shift_rotate(&(stack)->b);
		write(1, "rb\n", 3);
	}
	else if (b == 2)
	{
		write(1, "rr\n", 3);
		shift_rotate(&(stack)->a);
		shift_rotate(&(stack)->b);
	}
}

void	rev_rotate(t_stack *stack, int b)
{
	if (b == 0)
	{
		shift_rev_rotate(&(stack)->a);
		write(1, "rra\n", 4);
	}
	else if (b == 1)
	{
		shift_rev_rotate(&(stack)->b);
		write(1, "rrb\n", 4);
	}
	else if (b == 2)
	{
		shift_rev_rotate(&(stack)->a);
		shift_rev_rotate(&(stack)->b);
		write(1, "rrr\n", 4);
	}
}
