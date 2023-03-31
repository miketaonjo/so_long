/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:19:29 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 11:48:01 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_init(t_data *data)
{
	data->map.matrix = NULL;
	data->map.size_x = 0;
	data->map.size_y = 0;
}

void	check_player(t_data *data)
{
	if (data->img.c.player == 0)
	{
		player_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	if (data->img.c.up == 0)
	{
		player_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	if (data->img.c.left == 0)
	{
		player_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	if (data->img.c.right == 0)
	{
		player_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
}

void	check_img(t_data *data)
{
	if (data->img.background == 0)
	{
		img_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	if (data->img.wall == 0)
	{
		img_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	/*if (data->img.rock == 0)
	{
		img_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	if (data->img.player == 0)
	{
		img_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}*/
	if (data->img.collect == 0)
	{
		img_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	if (data->img.exit == 0)
	{
		img_destroy(data);
		putstr_error("Impossible de créer les images\n");
	}
	check_player(data);
}

void	player_init(t_data *data)
{
	int w;
	int h;

	data->img.c.player = mlx_xpm_file_to_image(data->mlx, "./imgs/player/poro.xpm", &w, &h);
	data->img.c.up = mlx_xpm_file_to_image(data->mlx, "./imgs/player/up.xpm", &w, &h);
	data->img.c.left = mlx_xpm_file_to_image(data->mlx, "./imgs/player/left.xpm", &w, &h);
	data->img.c.right = mlx_xpm_file_to_image(data->mlx, "./imgs/player/right.xpm", &w, &h);
}

void	img_init(t_data *data)
{
	int w;
	int h;

	data->mlx = mlx_init();
	if (data->mlx == 0)
	{
		game_destroy(data);
		putstr_error("Impossible de charger la minilibx\n");
	}
	data->win = mlx_new_window(data->mlx, data->map.size_x * 64, data->map.size_y * 64, "Poro snax quest");
	if (data->win == 0)
	{
		game_destroy(data);
		putstr_error("Impossible de créer la fenêtre\n");
	}
	data->img.background = mlx_xpm_file_to_image(data->mlx, "./imgs/background/bg.xpm", &w, &h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./imgs/wall/tree.xpm", &w, &h);
	//data->img.rock = mlx_xpm_file_to_image(data-> mlx, "./imgs/rock/rocks.xpm", &w, &h);
	//data->img.player = mlx_xpm_file_to_image(data-> mlx, "./imgs/player/poro.xpm", &w, &h);
	data->img.collect = mlx_xpm_file_to_image(data->mlx, "./imgs/collect/snax.xpm", &w, &h);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./imgs/exit/braum.xpm", &w, &h);
	player_init(data);
	check_img(data);
	set_img(data);
}
