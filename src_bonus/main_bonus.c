/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:25:41 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/29 21:25:50 by azakarya         ###   ########.fr       */
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
		if (group == NULL)
			return (write(2, "Error\n", 6), 1);
		else if (*group == 0)
			return (0);
		if (arg_check(group) != 0)
		{
			if (group)
				free_dp(&group);
			write(2, "Error\n", ft_strlen("error\n"));
			exit(1);
		}
		stack = make_stack(&group);
		if (checker(stack) == -1)
			return (free_stack(stack),
				write(2, "Error\n", ft_strlen("error\n")), 1);
		free_stack(stack);
	}
	return (0);
}
