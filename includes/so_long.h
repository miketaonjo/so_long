/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:12:40 by mcloarec          #+#    #+#             */
/*   Updated: 2022/06/23 11:16:36 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<mlx.h>
# include<mlx_int.h>
# include"../libft/libft.h"

typedef struct s_player
{
	void	*player;
	void	*up;
	void	*left;
	void	*right;
}			t_player;

typedef struct s_game
{
	//void		*player;
	void		*background;
	void		*wall;
	void		*rock;
	void		*collect;
	void		*exit;
	t_player	c;
}				t_game;

typedef struct s_map
{
	char	**matrix;
	int		size_x;
	int		size_y;
}				t_map;

typedef struct s_check
{
	int	i;
	int	nb_p;
	int	nb_c;
	int	nb_e;
	int	j;	
}				t_check;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_game	img;
	int		total;
	int		snax;
	int		moves;
}				t_data;

void	putstr_error(char *str);
void	error_map(void);
void	error_symbols(void);
void	error_walls(void);
void	error_chars(void);
void	map_init(t_data *data);
void	img_init(t_data *data);
void	size_map(t_data *data, char *str);
void	check_map(t_data *data);
void	set_img(t_data *data);
void	set_player_up(t_data *data);
void	set_player_left(t_data *data);
void	set_player_right(t_data *data);
int		exit_prog(t_data *data);
void	img_destroy(t_data *data);
void	game_destroy(t_data *data);
void	player_destroy(t_data *data);
int		key_funct(int keycode, t_data *data);
int		deal_key(int keycode, t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	win_game(t_data *data);
void	free_check(t_data *data);

#endif
