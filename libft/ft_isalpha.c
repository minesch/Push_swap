/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:35:31 by azakarya          #+#    #+#             */
/*   Updated: 2022/03/23 23:04:14 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isalpha(int x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
		return (1);
	return (0);
}