/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:10:36 by bwong             #+#    #+#             */
/*   Updated: 2022/07/10 16:10:47 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *map, char *line)
{
	int	i;

	i = -1;
	while (++i != map->img.width - 1)
	{
		if (line[i] == 'E')
			map->e++;
		else if (line[i] == 'C')
			map->c++;
		else if (line[i] == 'P')
		{
			map->p++;
			map->hero.x = i;
			map->hero.y = map->img.height - 1;
		}
		else if (line[i] != '0' && line[i] != '1')
			terminate("Error\nUnknown character on the map", 1);
	}
}

void	check_walls(t_game *map, int width, char *line)
{
	int	i;

	i = 0;
	map->bottom_wall = 1;
	if (width != map->img.width)
		terminate("Error\nThe map is not rectangular", 1);
	while (line[i] == '1')
		i++;
	if (map->img.height > 1 && (!line[i] || line[i] == '\n'))
		map->bottom_wall = 0;
	if (map->img.height == 1 && line[i] && line[i] != '\n')
		terminate("Error\nSomething's wrong in the upper wall", 1);
	if (line[0] != '1' || line[width - 1] != '1')
		terminate("Error\nThe wall is not complete", 1);
	check_chars(map, line);
}

void	check_map(t_game *map, char *line, int fd)
{
	int	width;

	if (!line)
		terminate("Error\nWhere is the map?", 1);
	while (line)
	{
		width = ft_strlen(line);
		if (*line == '\n' || !width)
			terminate("Error\nEmpty line?!", 1);
		if (strrchr(line, '\n'))
			width--;
		if (!map->img.width)
			map->img.width = width;
		map->img.height++;
		check_walls(map, width, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!line && map->bottom_wall)
		terminate("Error\nSomething's wrong at the bottom wall", 1);
	if ((!(map->e) || !(map->c) || map->p != 1))
		terminate("Error\nWrong composition", 1);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		terminate("Error\nHow many arguments do you have here?", 1);
	if (ft_strlen(argv[1]) < 5)
		terminate("Error\nInvalid map", 1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
		terminate("Error\n Wrong extension ", 1);
}
