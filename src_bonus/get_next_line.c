/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:23:52 by azakarya          #+#    #+#             */
/*   Updated: 2022/11/30 01:17:46 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saver;
	char		buf[BUFFER_SIZE + 1];
	char		*print;
	int			count;
	char		*for_free;

	while (1)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			return (0);
		buf[count] = '\0';
		if (!saver)
			saver = ft_strdup_gnl(buf);
		else
			saver = ft_strjoin_gnl(saver, buf);
		if (ft_strchr_gnl(buf, '\n') || count == 0)
			break ;
	}
	count = f_strlen(saver) - f_strlen(ft_strchr_gnl(saver, '\n')) + 1;
	print = ft_substr_gnl(saver, 0, count);
	for_free = saver;
	saver = ft_substr_gnl(saver, count, f_strlen(saver));
	free(for_free);
	return (print);
}
