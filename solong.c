typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	char	*map;
}				t_data;

void putstr_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
}

int	main(int argc, char **argv)
{
	t_data	*data;

    if (argc != 2)
		pustr_error("Le fichier est manquant")
	data = malloc(sizeof(t_data));
	data = base_init(data);
	size_map(data, argv[1]);
	create_map(data, argv[1]);
	check_map(data);
	data->mlx = mlx_init();
	mlx_loop(data->mlx);
}

t_data	*base_init(t_data data)
{
	data->mlx = 0;
	data->win = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->map = 0;
	return (data);
}

void	size_map(t_data *data, char **argv)
{
	int	fd;
    
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		pustr_error("Le fichier n'est pas lisible");
    data->size_x = (nb_cell(fd));
    data->size_y = (nb_lines(fd, data->size_x));
	close(fd);
}

int	nb_cell(int fd)
{
	char	buffer[1];
	int		cell;
	int		i;

	buffer[0] = '\0';
	i = 1;
	cell = 0;
	while (i == 1)
	{
		i = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			cell++;
	}
	return (cell);
}

int	nb_lines(int fd, int x)
{
	char	*line;
    int     line_len;
	int		count;
	int		i;

	i = 0;
	count = 1;
	while (fd == 1)
	{
		line = get_next_line(fd);
        line_len = ft_strlen(line);
		if (line == NULL)
			break ;
		if (line_len != x)
		{
			free(line);
           	putstr_error("La map n'est pas correcte");
		}
		else
		{
			free(line);
			count++;
		}
	}
	return (count);
}

int	isber(char *map)
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

void	create_map(t_data *data, char **argv)
{
	int	fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (isber(argv[1]) == 0)
		putstr_error("La map n'est pas au format .ber");
	line = get_next_line(fd);
	while (line != '\0')
	{
		line = get_next_line(fd);
		if (line)
			data->map = ft_strjoin(data->map, line);
	}
	close(fd);
}

void	check_map(t_data *data)
{
	int	i;
	int line_len;
	int	nb_p;
	int	nb_c;
	int	nb_e;

	i = 0;
	line_len = ft_strlen(game->map)
	nb_p = 0;
	nb_c = 0;
	nb_e = 0;
	while (i < line_len)
	{
		if (data->map[i] == 'P')
			nb_p++;
		else if (data->map[i] == "C")
			nb_c++;
		else if (data->map[i] == "E")
			nb_e++;
		i++;
	}
	if (nb_p == 0 || nb_c == 0 || nb_e == 0)
		putstr_error("La map doit contenir au moins 1 sortie, 1 item et 1 position de départ");
}