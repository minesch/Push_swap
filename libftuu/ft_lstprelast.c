/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprelast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:46:04 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/02 23:47:06 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstprelast(t_list *lst)
{
	while (lst && lst->next->next)
		lst = lst->next;
	return (lst);
}
