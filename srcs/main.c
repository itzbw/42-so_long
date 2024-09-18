/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:01:36 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 19:59:57 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate(char *error_msg, int status)
{
	ft_putendl_fd(error_msg, 2);
	exit (status);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = start_game();
	check_args (argc, argv);
	create_map (argv[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->img.width * X, game->img.height * Y, "wheek adventure");
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, DESTROY, 1L << 0, exit_window, game);
	mlx_loop(game->mlx);
}
