/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:18:27 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 19:59:52 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	print_moves(t_game *game)
{
	ft_putstr_fd("MOVES: ", 1);
	ft_putnbr_fd(game->hero.moves, 1);
	ft_putendl_fd("", 1);
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map[game->hero.y + y][game->hero.x + x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground,
		X * game->hero.x, Y * game->hero.y);
	if (game->map[game->hero.y][game->hero.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			X * game->hero.x, Y * game->hero.y);
	game->hero.x += x;
	game->hero.y += y;
	game->hero.moves++;
	if (game->map[game->hero.y][game->hero.x] == 'C')
	{
		game->c--;
		game->map[game->hero.y][game->hero.x] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		X * game->hero.x, Y * game->hero.y);
	print_moves(game);
	if (game->map[game->hero.y][game->hero.x] == 'E' && !game->c)
		terminate("YOU WON!", 0);
	if (game->map[game->hero.y][game->hero.x] == 'E' && game->c)
		ft_putendl_fd("Wheek! Not enough! I'm still hungry", 1);
}

int	press_key(int keysym, t_game *game)
{
	if (keysym == ESC)
		exit_window(game);
	else if (keysym == KEYW || keysym == KEYUP)
		move_player(game, 0, -1);
	else if (keysym == KEYA || keysym == KEYLEFT)
		move_player(game, -1, 0);
	else if (keysym == KEYS || keysym == KEYDOWN)
		move_player(game, 0, 1);
	else if (keysym == KEYD || keysym == KEYRIGHT)
		move_player(game, 1, 0);
	return (0);
}
