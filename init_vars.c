/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:43 by                   #+#    #+#             */
/*   Updated: 2021/09/17 21:36:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_images(t_vars *vars)
{
	int		img_width;
	int		img_height;

	vars->img_player_w = mlx_xpm_file_to_image(vars->mlx,
			"./images/play_w.xpm", &img_width, &img_height);
	vars->img_player_a = mlx_xpm_file_to_image(vars->mlx,
			"./images/play_a.xpm", &img_width, &img_height);
	vars->img_player_s = mlx_xpm_file_to_image(vars->mlx,
			"./images/play_s.xpm", &img_width, &img_height);
	vars->img_player_d = mlx_xpm_file_to_image(vars->mlx,
			"./images/play_d.xpm", &img_width, &img_height);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
			"./images/wall.xpm", &img_width, &img_height);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit.xpm", &img_width, &img_height);
	vars->img_collectible = mlx_xpm_file_to_image(vars->mlx,
			"./images/good.xpm", &img_width, &img_height);
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

int	count_rows(char *map_path)
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
	return (i + 1);
}

t_vars	*init_map(char *map_path, t_vars *vars)
{
	int	rows;

	rows = count_rows(map_path);
	vars->map = malloc(sizeof(char *) * (rows + 1));
	parse_map(map_path, vars);
	vars->mlx = mlx_init();
	init_vars(vars);
	init_images(vars);
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 50,
			vars->map_height * 50, "So long...");
	return (vars);
}
