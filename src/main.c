/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:39:54 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/26 19:49:25 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mainlib.h"

int	main(int ac, char **av)
{
	char	**group;
	t_stack	*stack;

	if (ac > 1)
	{
		group = join_args(ac, av);
		if (*group == NULL)
			return (0);
		if (arg_check(group) != 0)
		{
			free_dp(&group);
			write(2, "Error\n", ft_strlen("error\n"));
			exit(1);
		}
		stack = make_stack(&group);
		if (sorting_check(stack->a) != 0)
			push_swap(stack);
		// print_stack(stack->a);
		free_stack(stack);
	}
	return (0);
}
