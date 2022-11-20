/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:41:33 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/20 03:59:56 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainlib.h"

void	ft_rotate(t_list **ptr)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(*ptr);
	temp = (*ptr);
	(*ptr) = (*ptr)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ft_rev_rotate(t_list **ptr)
{
	t_list	*prelast;
	t_list	*last;

	prelast = ft_lstprelast(*ptr);
	last = ft_lstlast(*ptr);
	prelast->next = NULL;
	last->next = *ptr;
	*ptr = last;
}
