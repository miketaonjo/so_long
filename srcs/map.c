/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:28:23 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/20 19:20:38 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	nb_cells(int fd)
{
	char	buffer[1];
	int		cell;

	buffer[0] = 49;
	cell = 0;
	while (buffer[0] != '\n')
	{
		if (read(fd, buffer, 1) == 0)
		{
			putstr_error("La fichier map est vide\n");
			exit(EXIT_FAILURE);
		}
		if (buffer[0] != '\n')
			cell++;
	}
	return (cell);
}

static int	nb_lines(int fd)
{
	char	buffer[1];
	int		lines;
	int		i;

	lines = 0;
	i = 1;
	buffer[0] = 48;
	while (i != 0)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			lines++;
	}
	if (buffer[0] != '\n' /*|| buffer[0] != '\0'*/)
		lines++;
	return (lines);
}

int	check_ber(char *map)
{
	if (!(ft_strnstr(map, ".ber", ft_strlen(map))))
		return (0);
	else
		return (1);
}

void	create_map(t_data *data, char *str)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(str, O_RDONLY);
	if (check_ber(str) == 0)
	{
		putstr_error("La map n'est pas au format .ber\n");
		exit(EXIT_FAILURE);
	}
	data->map.matrix = ft_calloc(sizeof(char *), data->map.size_y);
	i = 0;
	line = NULL;
	while (line || i == 0)
	{
		line = get_next_line(fd);
		if (i < data->map.size_y)
			data->map.matrix[i] = line;
		i++;
	}
	/*i = -1;
	while (++i < map->game.size_y)
		ft_printf("%s", map->game.matrix[i]);*/
	close(fd);
	check_map(data);
}

void	size_map(t_data *data, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		putstr_error("Le fichier n'est pas lisible\n");
		exit(EXIT_FAILURE);
	}
	data->map.size_x = nb_cells(fd);
	data->map.size_y = nb_lines(fd);
//	ft_printf("%d", map->game.size_y);
//	ft_printf("%d", map->game.size_x);
	close(fd);
	create_map(data, str);
}
