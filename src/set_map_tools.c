/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:26:36 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:29:48 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	check_objects(t_map *map);

int	check_walls(t_data *game)
{
	int	i;
	int	j;
	int	wall;

	i = 0;
	j = 0;
	wall = game->map->objects->wall;
	while (i < game->map->col)
	{
		if (game->map->grid[0][i] != wall ||
		game->map->grid[game->map->lin - 1][i] != wall)
			set_shutdown(0, game,
				"Error\nThe map needs to be surrounded by walls.\n");
		i++;
	}
	while (j < game->map->lin)
	{
		if (game->map->grid[j][0] != wall ||
			game->map->grid[j][game->map->col - 1] != wall)
			set_shutdown(0, game,
				"Error\nThe map needs to be surrounded by walls.\n");
		j++;
	}
	return (0);
}

int	check_composition(t_data *game)
{
	int	invalid_char;

	invalid_char = check_objects(game->map);
	if (invalid_char > 0)
		set_shutdown(0, game, "Error\nThe map have an invalid character.\n");
	if (game->map->objects->n_players != 1)
		set_shutdown(0, game, "Error\nThe map need exactly 1 player.\n");
	if (game->map->objects->n_collectibles < 1)
		set_shutdown(0, game, "Error\nThe map need at least 1 collectible.\n");
	if (game->map->objects->n_exits != 1)
		set_shutdown(0, game, "Error\nThe map need exactly 1 exit.\n");
	return (0);
}

int	check_path(t_data *game)
{
	t_check	valid_path;

	set_path_check(game, &valid_path);
	if (valid_path.coins != game->map->objects->n_collectibles)
		set_shutdown(0, game, "Error\nThere's something in the way.\n");
	if (valid_path.exit != game->map->objects->n_exits)
		set_shutdown(0, game, "Error\nThere's something in the way.\n");
	return (0);
}

static int	check_objects(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->lin - 1)
	{
		j = 1;
		while (j < map->col - 1)
		{
			if (map->grid[i][j] == map->objects->start)
				map->objects->n_players++;
			else if (map->grid[i][j] == map->objects->colect)
				map->objects->n_collectibles++;
			else if (map->grid[i][j] == map->objects->exit)
				map->objects->n_exits++;
			else if (map->grid[i][j] != map->objects->empty &&
			map->grid[i][j] != map->objects->wall)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
