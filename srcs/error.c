/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <mcloarec@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:34:06 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/14 18:01:54 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putstr_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
}

void	error_map(void)
{
	putstr_error("La map n'est pas un rectangle\n");
	exit(EXIT_FAILURE);
}

void	error_symbols(void)
{
	putstr_error("Il doit y avoir au moins 1 sortie, 1 item et 1 départ\n");
	exit(EXIT_FAILURE);
}

void	error_walls(void)
{
	putstr_error("La map doit être entourée de murs\n");
	exit(EXIT_FAILURE);
}

void	error_chars(void)
{
	putstr_error("La map ne peut contenir que 1, 0, P, E et C\n");
	exit(EXIT_FAILURE);
}
