/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:35:44 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 18:23:06 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	win_game(t_data *data)
{
	data->moves++;
	ft_printf("%s %d%s\n", "Félicitations! Tu as gagné en faisant", data->moves, " mouvements.");
	mlx_clear_window(data->mlx, data->win);
	img_destroy(data);
	player_destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_check(data);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		putstr_error("Le fichier map est manquant\n");
		exit(EXIT_FAILURE);
	}
	map_init(&data);
	size_map(&data, argv[1]);
	img_init(&data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_hook(data.win, 2, 0, &key_funct, &data);
	mlx_hook(data.win, 17, 0, &exit_prog, &data);
	mlx_loop(data.mlx);
}
