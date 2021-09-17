#include "so_long.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	refresh_window(t_vars *vars)
{
	int	i;
	int j;

	mlx_clear_window(vars->mlx, vars->win);
	i = -1;
	while (++i < vars->map_height)
	{
		j = -1;
		while (++j < vars->map_width)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall, j * 50, i * 50);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_collectible, j * 50, i * 50);
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit, j * 50, i * 50);
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player, j * 50, i * 50);
		}
	}
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	init_images(t_vars *vars)
{
	int		img_width;
	int		img_height;

	vars->img_player_w = mlx_xpm_file_to_image(vars->mlx, "./images/play_w.xpm", &img_width, &img_height);
	vars->img_player_a = mlx_xpm_file_to_image(vars->mlx, "./images/play_a.xpm", &img_width, &img_height);
	vars->img_player_s = mlx_xpm_file_to_image(vars->mlx, "./images/play_s.xpm", &img_width, &img_height);
	vars->img_player_d = mlx_xpm_file_to_image(vars->mlx, "./images/play_d.xpm", &img_width, &img_height);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, "./images/wall.xpm", &img_width, &img_height);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &img_width, &img_height);
	vars->img_collectible = mlx_xpm_file_to_image(vars->mlx, "./images/good.xpm", &img_width, &img_height);
	vars->img_player = vars->img_player_w;
}

void	init_vars(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	vars->steps = 0;
	vars->points = 0;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->y = y;
				vars->x = x;
			}
			if (vars->map[y][x] == 'C')
				vars->points++;
			if (vars->map[y][x] == 'E')
				vars->exit_count++;
		}
	}
	vars->map_height = y;
	vars->map_width = x;
}

int		count_rows(char *map_path)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_exit("Can't open map file");
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	return i + 1;
}

void	parse_map(char *map_path, t_vars *vars)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_exit("Can't open file");
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		vars->map[i] = ft_strdup(line);
		free(line);
		if (vars->map[i] == NULL)
			exit(0);
		i++;
	}
	vars->map[i] = ft_strdup(line);
	free(line);
	close(fd);
}

t_vars *init_map(char *map_path, t_vars *vars)
{
	int	rows;

	rows = count_rows(map_path);
	vars->map = malloc(sizeof(char *) * (rows + 1));
	parse_map(map_path, vars);
	vars->mlx = mlx_init();
	init_vars(vars);
	init_images(vars);
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 50, vars->map_height * 50, "So long...");
	return (vars);
}

int	is_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error_exit("Wrong count of arguments");
	if (is_ber(argv[1]) == 0)
		error_exit("Wrong file name");
	init_map(argv[1], &vars);
	refresh_window(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
