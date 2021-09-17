/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:38 by                   #+#    #+#             */
/*   Updated: 2021/09/17 21:36:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_left(t_vars *vars)
{
	vars->img_player = vars->img_player_a;
	if (vars->map[vars->y][vars->x - 1] != '1')
	{
		if (vars->map[vars->y][vars->x - 1] == 'C')
			vars->points--;
		if (vars->map[vars->y][vars->x - 1] == 'E')
		{
			if (!vars->points)
				exit(1);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->x--;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
	}
}

void	move_right(t_vars *vars)
{
	vars->img_player = vars->img_player_d;
	if (vars->map[vars->y][vars->x + 1] != '1')
	{
		if (vars->map[vars->y][vars->x + 1] == 'C')
			vars->points--;
		if (vars->map[vars->y][vars->x + 1] == 'E')
		{
			if (!vars->points)
				exit(1);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->x++;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
	}
}

void	move_up(t_vars *vars)
{
	vars->img_player = vars->img_player_w;
	if (vars->map[vars->y - 1][vars->x] != '1')
	{
		if (vars->map[vars->y - 1][vars->x] == 'C')
			vars->points--;
		if (vars->map[vars->y - 1][vars->x] == 'E')
		{
			if (!vars->points)
				exit(1);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->y--;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
	}
}

void	move_down(t_vars *vars)
{
	vars->img_player = vars->img_player_s;
	if (vars->map[vars->y + 1][vars->x] != '1')
	{
		if (vars->map[vars->y + 1][vars->x] == 'C')
			vars->points--;
		if (vars->map[vars->y + 1][vars->x] == 'E')
		{
			if (!vars->points)
				exit(1);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->y++;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_game(vars);
	if (keycode == 97)
		move_left(vars);
	else if (keycode == 100)
		move_right(vars);
	else if (keycode == 115)
		move_down(vars);
	else if (keycode == 119)
		move_up(vars);
	printf("%d\n", vars->steps);
	refresh_window(vars);
	return (0);
}
