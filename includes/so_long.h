/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:39:02 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 15:40:51 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define KEYUP		13
# define KEYDOWN	1
# define KEYRIGHT   2
# define KEYLEFT    0
# define KEYD       124
# define KEYA       123
# define KEYW       126
# define KEYS       125
# define ESC		53
# define DESTROY	17
# define X			72
# define Y			72

# define WALL		"./assets/s72_tree_final.xpm"
# define GROUND		"./assets/s72_grass.xpm"
# define PLAYER		"./assets/s72_gp_right.xpm"
# define COLLECT	"./assets/s72_carrot_simple.xpm"
# define EXIT		"./assets/s72_exit-barn.xpm"

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	move_flag;
	int	dir_flag;
}	t_player;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*ground;
	void	*collectible;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img;
	t_player	hero;
	int			e;
	int			p;
	int			c;
	int			bottom_wall;
}	t_game;

t_game	*start_game(void);
void	check_map(t_game *map, char *line, int fd);
void	create_map(char *argv, t_game *map);
void	draw_map(t_game *game);
void	check_args(int argc, char **argv);
int		press_key(int keysym, t_game *game);
void	move_player(t_game *game, int x, int y);
int		exit_window(t_game *game);
void	terminate(char *error_msg, int status);

#endif