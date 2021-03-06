/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:35:22 by                   #+#    #+#             */
/*   Updated: 2021/10/14 15:34:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H

# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# ifdef SO_LONG_IS_MACOS
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
# endif

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_collectible;
	void	*img_wall;
	void	*img_exit;
	char	**map;
	int		x;
	int		y;
	int		steps;
	int		points;
	int		exit_count;
	int		map_height;
	int		map_width;
}				t_vars;

void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		close_game(t_vars *vars);
void	refresh_window(t_vars *vars);
void	error_exit(char *msg);
int		is_ber(char *file);
void	parse_map(char *map_path, t_vars *vars);
t_vars	*init_map(char *map_path, t_vars *vars);
void	check_valid_symbol(char c);
void	check_map(t_vars *vars);

#endif
