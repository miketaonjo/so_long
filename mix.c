///header
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_coord			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}				t_game;

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_game			*game;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*ground;
}				t_root;

void			die(char *errmsg, int errnum);

void			draw(t_root *root);

int				key_press(int keycode, t_root *root);
int				key_release(int keycode, t_root *root);
int				destroy_hook(int keycode, t_root *root);

void			game_destroy(t_game *game);

void			game_init(t_root *root, char *filename);

void			map_height(t_root *root, char *file);

void			map_init(t_root *root, char *filename);

void			map_isvalid(t_root *root, char *file);

void			map_parsing(t_root *root, char *file);

void			map_read(t_root *root, char *file);

void			map_width(t_root *root, char *file);

unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

void			move_up(t_root *root, int x, int y);
void			move_down(t_root *root, int x, int y);
void			move_left(t_root *root, int x, int y);
void			move_right(t_root *root, int x, int y);

void			root_destroy(t_root *root, char *errmsg, int errnum);

t_root			*root_init(char *filename);

void			update(t_root *root);

#endif

///main
int	main(int ac, char *av[])
{
	t_root			*root;

	if (ac != 2)
		ft_printf("Nombre d'arguments invalides, il doit être de 2");
	if (isber(av[1]) == 0)
		ft_printf("La map doit être au format .ber");
	root = root_init(av[1]);
	draw(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}

///check erreur avant lancement jeu
/*format map*/
int	isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

/*malloc structure et initialisation*/
t_root	*root_init(char *filename)
{
	t_root			*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (!root)
    {
        free(root);
        ft_printf("Erreur d'initialisation");
        return (NULL);
    }
    root->game = 0;
	root->mlx = 0;
	root->mlx_win = 0;
	root->mlx_img = 0;
	root->player = 0;
	root->exit = 0;
	root->coll = 0;
	root->wall = 0;
	root->ground = 0;
	game_init(root, filename);
	renderer_init(root);
	texture_init(root);
    return (root);
}