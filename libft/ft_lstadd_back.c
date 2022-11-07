/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:26:37 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:31 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst && new))
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
