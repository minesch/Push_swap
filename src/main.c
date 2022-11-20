/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:39:54 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/20 04:07:12 by azakarya         ###   ########.fr       */
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
		push_swap(stack);
		free(stack);
	}
	return (0);
}
