#ifndef SO_LONG_H

# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct	s_vars {
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

#endif
