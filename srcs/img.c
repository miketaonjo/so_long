/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:23:49 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 11:47:28 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player_up(t_data *data, int j, int i)
{	
	if (data->map.matrix[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.background, j * 64, i * 64);
	else if (data->map.matrix[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, j * 64, i * 64);
	/*else if (data->map.matrix[i][j] == 'R')
		mlx_put_image_to_window(data->mlx, data->win, data->img.rock, j * 64, i * 64);*/
	else if (data->map.matrix[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collect, j * 64, i * 64);
	else if (data->map.matrix[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, j * 64, i * 64);
	else if (data->map.matrix[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.c.up, j * 64, i * 64);
}

void	set_player_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y)
	{
		j = 0;
		while (j < data->map.size_x)
		{
			put_player_up(data, j, i);
			j++;
		}
		i++;
	}
}

void	put_img(t_data *data, int j, int i)
{
	if (data->map.matrix[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.background, j * 64, i * 64);
	else if (data->map.matrix[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, j * 64, i * 64);
	/*else if (data->map.matrix[i][j] == 'R')
		mlx_put_image_to_window(data->mlx, data->win, data->img.rock, j * 64, i * 64);*/
	else if (data->map.matrix[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.c.player, j * 64, i * 64);
	else if (data->map.matrix[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collect, j * 64, i * 64);
	else if (data->map.matrix[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, j * 64, i * 64);
}

void	set_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y)
	{
		j = 0;
		while (j < data->map.size_x)
		{
			put_img(data, j, i);
			j++;
		}
		i++;
	}
}
