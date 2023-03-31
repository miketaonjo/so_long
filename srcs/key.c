/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:22:17 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 10:13:54 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int keycode, t_data *data)
{
	key_funct(keycode, data);
	return (0);
}

int	key_funct(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_prog(data);
	if (keycode == 119)
		move_up(data);
	if (keycode == 97)
		move_left(data);
	if (keycode == 115)
		move_down(data);
	if (keycode == 100)
		move_right(data);
	return(0);
}
