typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
}				t_data;


int	main(int argc, char **argv)
{
	t_data	data;
    
	ft_window_size(&data, argv);
}

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

void	ft_window_size(t_data *data, char **argv)
{
	int	fd;
    
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Le fichier n'est pas trouvable\n, 31");
		return(0);
	}
    if (isber(argv[1]) == 0)
    {
        write(2, "La map doit être au format .ber\n", 32);
        return (0);
    }
    data->size_x = (ft_line_length(fd));
    data->size_y = (ft_count_lines(fd, data->size_x));
}

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	ft_count_lines(int fd, int x)
{
	char	*line;
    int     line_len;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (fd == 1)
	{
		line = get_next_line(fd);
        line_len = ft_strlen(line);
		if (line == NULL)
			break ;
		if (line_len < x || line_len == 1 && *line != '\n'))
		{
			free(line);
            write(2, "La map n'est pas aux bonnes dimensions\n", 39);
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}