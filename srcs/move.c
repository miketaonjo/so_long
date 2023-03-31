/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:19 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 11:45:34 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y)
	{
		j = 0;
		while (j < data->map.size_x)
		{
			if (data->map.matrix[i][j] == 'P')
				break ;
			j++;
		}
		if (j != data->map.size_x)
			break ;
		i++;
	}
	if (data->map.matrix[i - 1][j] == 'C')
		data->snax++;
	if (data->map.matrix[i - 1][j] == 'E' && data->snax == data->total)
		win_game(data);
	else if (data->map.matrix[i - 1][j] != '1' && data->map.matrix[i - 1][j] != 'E')
	{
		data->map.matrix[i][j] = '0';
		data->map.matrix[i - 1][j] = 'P';
		data->moves++;
		ft_printf("%d %s\n", data->moves, "mouvements.");
		set_player_up(data);
	}
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y)
	{
		j = 0;
		while (j < data->map.size_x)
		{
			if (data->map.matrix[i][j] == 'P')
				break ;
			j++;
		}
		if (j != data->map.size_x)
			break ;
		i++;
	}
	if (data->map.matrix[i][j - 1] == 'C')
		data->snax++;
	if (data->map.matrix[i][j - 1] == 'E' && data->snax == data->total)
		win_game(data);
	else if (data->map.matrix[i][j - 1] != '1' && data->map.matrix[i][j - 1] != 'E')
	{
		data->map.matrix[i][j] = '0';
		data->map.matrix[i][j - 1] = 'P';
		data->moves++;
		ft_printf("%d %s\n", data->moves, "mouvements.");
		set_player_left(data);
	}
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y)
	{
		j = 0;
		while (j < data->map.size_x)
		{
			if (data->map.matrix[i][j] == 'P')
				break ;
			j++;
		}
		if (j != data->map.size_x)
			break ;
		i++;
	}
	if (data->map.matrix[i + 1][j] == 'C')
		data->snax++;
	if (data->map.matrix[i + 1][j] == 'E' && data->snax == data->total)
		win_game(data);
	else if (data->map.matrix[i + 1][j] != '1' && data->map.matrix[i + 1][j] != 'E')
	{
		data->map.matrix[i][j] = '0';
		data->map.matrix[i + 1][j] = 'P';
		data->moves++;
		ft_printf("%d %s\n", data->moves, "mouvements.");
		set_img(data);
	}
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y)
	{
		j = 0;
		while (j < data->map.size_x)
		{
			if (data->map.matrix[i][j] == 'P')
				break ;
			j++;
		}
		if (j != data->map.size_x)
			break ;
		i++;
	}
	if (data->map.matrix[i][j + 1] == 'C')
		data->snax++;
	if (data->map.matrix[i][j + 1] == 'E' && data->snax == data->total)
		win_game(data);
	else if (data->map.matrix[i][j + 1] != '1' && data->map.matrix[i][j + 1] != 'E')
	{
		data->map.matrix[i][j] = '0';
		data->map.matrix[i][j + 1] = 'P';
		data->moves++;
		ft_printf("%d %s\n", data->moves, "mouvements.");
		set_player_right(data);
	}
}
