/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:00:55 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 10:51:48 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.size_y)
	{
		free(data->map.matrix[i]);
		i++;
	}
	free(data->map.matrix);
}

void	check_symbols(t_data *data)
{
	t_check	s;

	s.nb_p = 0;
	s.nb_c = 0;
	s.nb_e = 0;
	s.i = -1;
	while (++s.i < data->map.size_y)
	{
		s.j = -1;
		while (++s.j < data->map.size_x)
		{
			if (data->map.matrix[s.i][s.j] == 'P')
				s.nb_p++;
			else if (data->map.matrix[s.i][s.j] == 'C')
				s.nb_c++;
			else if (data->map.matrix[s.i][s.j] == 'E')
				s.nb_e++;
		}
	}
	if (s.nb_p == 0 || s.nb_c == 0 || s.nb_e == 0)
	{
		free_check(data);
		error_symbols();
	}
}

void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.size_y)
	{
		j = -1;
		while (++j < data->map.size_x)
		{
			if (data->map.matrix[0][j] != '1'
				|| data->map.matrix[data->map.size_y - 1][j] != '1')
			{
				free_check(data);
				error_walls();
			}
			else if (data->map.matrix[i][0] != '1'
				|| data->map.matrix[i][data->map.size_x - 1] != '1')
			{
				free_check(data);
				error_walls();
			}
		}
	}
	check_symbols(data);
}

void	check_char(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.size_y)
	{
		j = -1;
		while (++j <= data->map.size_x)
		{
			if (data->map.matrix[i][j] != '1'
				&& data->map.matrix[i][j] != '0'
				&& data->map.matrix[i][j] != 'P'
				&& data->map.matrix[i][j] != 'E'
				&& data->map.matrix[i][j] != 'C'
				&& data->map.matrix[i][j] != 'R'
				&& data->map.matrix[i][j] != '\n'
				&& data->map.matrix[i][j] != '\0')
			{
				free_check(data);
				error_chars();
			}
		}
	}
	check_walls(data);
}

void	check_map(t_data *data)
{
	int	i;
	int	len_line;
	int	j;

	i = -1;
	j = -1;
	data->total = 0;
	data->snax = 0;
	data->moves = 0;
	while (++i < data->map.size_y)
	{
		len_line = ft_strlen(data->map.matrix[i]);
		if (len_line != (data->map.size_x + 1))
		{
			free_check(data);
			/*i = 0;
			j = data->game.size_y;
			while (i < j)
			{
				free(data->game.matrix[i]);
				i++;
			}	
			free(data->game.matrix);*/
			error_map();
		}
		j = 0;
		while (++j < data->map.size_x)
		{
			if (data->map.matrix[i][j] == 'C')
				data->total++;
		}
	}
	check_walls(data);
}
