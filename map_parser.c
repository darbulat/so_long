/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:46 by                   #+#    #+#             */
/*   Updated: 2021/10/14 11:04:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	parse_map(char *map_path, t_vars *vars)
{
	int		i;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_exit("Can't open file");
	i = 0;
	while (get_next_line(fd, &vars->map[i++]))
	{
		if (vars->map[i - 1] == NULL)
			error_exit("Error");
	}
	vars->map[i] = NULL;
	close(fd);
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
