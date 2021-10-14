/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:38 by                   #+#    #+#             */
/*   Updated: 2021/10/14 16:56:31 by                  ###   ########.fr       */
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
				close_game(vars);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->x--;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
		ft_putnbr_fd(vars->steps, 1);
		ft_putchar_fd('\n', 1);
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
				close_game(vars);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->x++;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
		ft_putnbr_fd(vars->steps, 1);
		ft_putchar_fd('\n', 1);
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
				close_game(vars);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->y--;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
		ft_putnbr_fd(vars->steps, 1);
		ft_putchar_fd('\n', 1);
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
				close_game(vars);
			else
				return ;
		}
		vars->map[vars->y][vars->x] = '0';
		vars->y++;
		vars->map[vars->y][vars->x] = 'P';
		vars->steps++;
		ft_putnbr_fd(vars->steps, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_game(vars);
	if (keycode == KEY_A)
		move_left(vars);
	else if (keycode == KEY_D)
		move_right(vars);
	else if (keycode == KEY_S)
		move_down(vars);
	else if (keycode == KEY_W)
		move_up(vars);
	refresh_window(vars);
	return (0);
}
