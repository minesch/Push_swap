/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:51:29 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/30 00:53:16 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

void	swap_ch(t_stack *stack, int b)
{
	t_list	*tmp;

	if ((b == 0 || b == 2)
		&& (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0))
	{
		tmp = stack->a->next;
		stack->a->next = stack->a;
		stack->a = tmp;
	}
	if ((b == 1 || b == 2)
		&& (ft_lstsize(stack->b) != 1 || ft_lstsize(stack->b) != 0))
	{
		tmp = stack->b->next;
		stack->b->next = stack->b;
		stack->b = tmp;
	}
}

void	push_ch(t_stack *stack, int b)
{
	if (b != 0 && b != 1)
		return ;
	if (stack->b != NULL && b == 0)
		pa(stack);
	else if (stack->a != NULL && b == 1)
		pb(stack);
}

void	rotate_ch(t_stack *stack, int b)
{
	if (b == 0)
		shift_rotate(&(stack)->a);
	else if (b == 1)
		shift_rotate(&(stack)->b);
	else if (b == 2)
	{
		shift_rotate(&(stack)->a);
		shift_rotate(&(stack)->b);
	}
}

void	rev_rotate_ch(t_stack *stack, int b)
{
	if (b == 0)
		shift_rev_rotate(&(stack)->a);
	else if (b == 1)
		shift_rev_rotate(&(stack)->b);
	else if (b == 2)
	{
		shift_rev_rotate(&(stack)->a);
		shift_rev_rotate(&(stack)->b);
	}
}
