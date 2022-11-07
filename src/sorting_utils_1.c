/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 04:19:12 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/06 18:05:57 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

int	sorting_check(t_list *a)
{
	t_list	*tmp;
	t_list	*start;
	int		i;
	int		num;

	start = a;
	while (start)
	{
		tmp = start->next;
		num = start->n;
		while (tmp)
		{
			if (num > tmp->n)
				return (1);
			tmp = tmp->next;
		}
		start = start->next;
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
	while (tmp != NULL)
	{
		printf("\n");
		printf("node-----%p\n", tmp);
		printf("%d\t->\t[%d]\n", tmp->n, tmp->index);
		printf("next-----%p\n", (tmp->next));
		printf("-------------------\n");
		printf("\n");
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	indexing(t_list *a)
{
	int	loop_count;
	int	small;

	loop_count = 0;
	index_neg(a);
	while (loop_count != ft_lstsize(a))
	{
		(find_smallest(a))->index = loop_count;
		loop_count++;
	}
	print_stack(a);
}
