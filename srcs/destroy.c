/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:40:17 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 13:56:57 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_prog(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	img_destroy(data);
	player_destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_check(data);
	free(data->mlx);
	exit(0);
}

void	player_destroy(t_data *data)
{
	if (data->img.c.player != 0)
		mlx_destroy_image(data->mlx, data->img.c.player);
	if (data->img.c.up != 0)
		mlx_destroy_image(data->mlx, data->img.c.up);
	if (data->img.c.left != 0)
		mlx_destroy_image(data->mlx, data->img.c.left);
	if (data->img.c.right != 0)
		mlx_destroy_image(data->mlx, data->img.c.right);
}

void	img_destroy(t_data *data)
{
	if (data->img.background != 0)
		mlx_destroy_image(data->mlx, data->img.background);
	if (data->img.wall != 0)
		mlx_destroy_image(data->mlx, data->img.wall);
/*	if (data->img.rock != 0)
		mlx_destroy_image(data->mlx, data->img.rock);
	if (data->img.player != 0)
		mlx_destroy_image(data->mlx, data->img.player);*/
	if (data->img.collect != 0)
		mlx_destroy_image(data->mlx, data->img.collect);
	if (data->img.exit != 0)
		mlx_destroy_image(data->mlx, data->img.exit);
}

void	game_destroy(t_data *data)
{
	if (data->mlx != 0)
		mlx_destroy_display(data->mlx);
	if (data->win != 0)
		mlx_destroy_window(data->mlx, data->win);
}
