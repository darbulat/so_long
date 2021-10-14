/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:48 by                   #+#    #+#             */
/*   Updated: 2021/10/14 16:55:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	int	j;

	mlx_clear_window(vars->mlx, vars->win);
	i = -1;
	while (++i < vars->map_height)
	{
		j = -1;
		while (++j < vars->map_width)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_wall, j * 50, i * 50);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_collectible, j * 50, i * 50);
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit,
					j * 50, i * 50);
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player,
					j * 50, i * 50);
		}
	}
}

int	close_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_player_d);
	mlx_destroy_image(vars->mlx, vars->img_player_s);
	mlx_destroy_image(vars->mlx, vars->img_player_w);
	mlx_destroy_image(vars->mlx, vars->img_player_a);
	mlx_destroy_image(vars->mlx, vars->img_collectible);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	vars->map = ft_strsfree(vars->map, vars->map_height);
	free(vars->mlx);
	exit(0);
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
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
