/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:46 by                   #+#    #+#             */
/*   Updated: 2021/09/17 21:36:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
