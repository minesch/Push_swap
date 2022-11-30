/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:21:40 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/30 01:16:53 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

int	norm_fix2(char *tmp, t_stack *stack)
{
	if (ft_strncmp(tmp, "rrr", 3) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->a) > 1 && ft_lstsize(stack->b) > 1)
			rev_rotate_ch(stack, 2);
	}
	else if (ft_strncmp(tmp, "pa", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->b) > 1)
			push_ch(stack, 1);
	}
	else if (ft_strncmp(tmp, "pb", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->a) > 1)
			push_ch(stack, 1);
	}
	else if (!tmp || !*tmp || *tmp == '\n')
		return (0);
	else
		return (-1);
	return (0);
}

int	norm_fix(char *tmp, t_stack *stack)
{
	if (ft_strncmp(tmp, "rb", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (stack->b != NULL && ft_lstsize(stack->b) > 1)
			rotate_ch(stack, 1);
	}
	else if (ft_strncmp(tmp, "rr", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->a) > 1 && ft_lstsize(stack->b) > 1)
			rotate_ch(stack, 2);
	}
	else if (ft_strncmp(tmp, "rra", 3) == 0 && ft_strlen(tmp) == 4)
	{
		if (ft_lstsize(stack->a) > 1)
			rev_rotate_ch(stack, 1);
	}
	else if (ft_strncmp(tmp, "rrb", 3) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->b) > 1)
			rev_rotate_ch(stack, 1);
	}
	else
		return (norm_fix2(tmp, stack));
	return (0);
}

int	check_action(char *tmp, t_stack *stack)
{
	if (ft_strncmp(tmp, "sa", 2) == 0 && ft_strlen(tmp) == 2)
	{
		if (ft_lstsize(stack->a) > 1)
			swap_ch(stack, 1);
	}
	else if (ft_strncmp(tmp, "sb", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->b) > 1)
			swap_ch(stack, 1);
	}
	else if (ft_strncmp(tmp, "ss", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->a) > 1 && ft_lstsize(stack->b) > 1)
			swap_ch(stack, 2);
	}
	else if (ft_strncmp(tmp, "ra", 2) == 0 && ft_strlen(tmp) == 3)
	{
		if (ft_lstsize(stack->a) > 1)
			rotate_ch(stack, 1);
	}
	else
		return (norm_fix(tmp, stack));
	return (0);
}

int	checker(t_stack *stack)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(1);
		if (tmp)
		{
			if (check_action(tmp, stack) != 0)
				return (free(tmp), -1);
			free(tmp);
		}
		else
		{
			if (sorting_check(stack->a) == 0 && stack->b == NULL)
				write(1, "OK\n", 3);
			else
				write(2, "KO\n", 3);
			return (0);
		}
	}
	if (tmp)
		free(tmp);
	return (0);
}
