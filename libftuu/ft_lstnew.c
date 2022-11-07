/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 01:37:24 by azakarya          #+#    #+#             */
/*   Updated: 2022/10/29 21:42:47 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstnew(int num)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->n = num;
	new->next = NULL;
	return (new);
}
