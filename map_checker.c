/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:46 by                   #+#    #+#             */
/*   Updated: 2021/10/14 08:41:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_valid_symbol(char c)
{
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'))
		error_exit("Error");
}

void	check_borders(t_vars *vars, int x, int y)
{
	if ((y == 0 || y == vars->map_height - 1 || x == 0
			|| x == vars->map_width - 1) && (vars->map[y][x] != '1'))
	{
		error_exit("Error");
	}
}

void	check_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	if (!(vars->exit_count && vars->points) || (vars->x == -1 && vars->y == -1))
		error_exit("Error");
	while (++y < vars->map_height)
	{
		if (ft_strlen(vars->map[y]) < (size_t) vars->map_width)
			error_exit("Error");
		x = -1;
		while (++x < vars->map_width)
			check_borders(vars, x, y);
	}
}
