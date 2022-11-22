/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:51:29 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/22 22:15:03 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

void	swap(t_stack *stack, int b)
{
	t_list	*tmp;

	if ((b == 0 || b == 2)
		&& (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0))
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		tmp->next = stack->a->next;
		stack->a->next = tmp;
		if (b == 0)
			write(1, "sa\n", 3);
	}
	if ((b == 1 || b == 2)
		&& (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0))
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		tmp->next = stack->b->next;
		stack->b->next = tmp;
		if (b == 1)
			write(1, "sb\n", 3);
	}
	if (b == 2)
		write(1, "ss\n", 3);
}

void	push(t_stack *stack, int b)
{
	t_list	*tmp;

	if (b == 0 && ft_lstsize(stack->a) != 0)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		tmp->next = NULL;
		if (!stack->a)
			stack->a = tmp;
		else
			ft_lstadd_front(&(stack->a), tmp);
		write(1, "pa\n", 3);
	}
	if (b == 1 && ft_lstsize(stack->a) != 0)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		if (!stack->b)
			stack->b = tmp;
		else
			ft_lstadd_front(&(stack->b), tmp);
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stack *stack, int b)
{
	if (b == 0 || b == 2)
	{
		if (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0)
		{
			ft_rotate(&(stack->a));
			if (b == 0)
				write(1, "ra\n", 3);
		}
	}
	if (b == 1 || b == 2)
	{
		if (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0)
		{
			ft_rotate(&(stack->b));
			if (b == 1)
				write(1, "rb\n", 3);
		}
	}
	if (b == 2)
		write(1, "rr\n", 3);
}

void	rev_rotate(t_stack *stack, int b)
{
	int		i;

	i = 0;
	if (b == 0 || b == 2)
	{
		if (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0)
		{
			ft_rev_rotate(&(stack->a));
			if (b == 0)
				write(1, "rra\n", 4);
		}
	}
	if (b == 1 || b == 2)
	{
		if (ft_lstsize(stack->a) != 1 || ft_lstsize(stack->a) != 0)
		{
			ft_rev_rotate(&(stack->b));
			if (b == 0)
				write(1, "rrb\n", 4);
		}
	}
	if (b == 2)
		write(1, "rrr\n", 4);
}
