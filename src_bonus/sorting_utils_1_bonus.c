/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:19:12 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/29 22:47:57 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

int	sorting_check(t_list *a)
{
	t_list	*aa;

	aa = a;
	while (aa->next)
	{
		if (aa->n < aa->next->n)
			aa = aa->next;
		else
			return (-1);
	}
	return (0);
}

void	index_neg(t_list *a)
{
	while (a)
	{
		a->index = -1;
		a = a->next;
	}
}

t_list	*find_smallest(t_list *a)
{
	int		smallest;
	t_list	*tmp;

	while (a->index != -1)
		a = a->next;
	tmp = a;
	smallest = a->n;
	while (a != NULL)
	{
		if (a->n < smallest && a->index == -1)
		{
			smallest = a->n;
			tmp = a;
		}
		a = a->next;
	}
	return (tmp);
}

void	print_stack(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		printf("%d--[%d]\n", tmp->n, tmp->index);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	indexing(t_list *a)
{
	int	loop_count;

	loop_count = 0;
	index_neg(a);
	while (loop_count != ft_lstsize(a))
	{
		(find_smallest(a))->index = loop_count;
		loop_count++;
	}
}
