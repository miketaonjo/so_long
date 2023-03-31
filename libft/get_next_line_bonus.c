/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:25:48 by mcloarec          #+#    #+#             */
/*   Updated: 2022/05/13 10:08:46 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_bonus(int fd)
{
	static char	*line[1000];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line[fd] == NULL)
	{
		line[fd] = ft_calloc_gnl(sizeof(char), 1);
		if (!line[fd])
			return (NULL);
	}
	line[fd] = ft_read_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	result = ft_save_line(line[fd]);
	line[fd] = ft_move_to_line(line[fd]);
	return (result);
}
