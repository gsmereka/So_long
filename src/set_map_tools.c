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

#include "../header/data.h"

static int	ft_check_objects(t_map *map);

int	ft_check_walls(t_data *game)
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
			ft_set_shutdown(0, game,
				"O mapa precisa estar cercado por paredes\n");
		i++;
	}
	while (j < game->map->lin)
	{
		if (game->map->grid[j][0] != wall ||
			game->map->grid[j][game->map->col - 1] != wall)
			ft_set_shutdown(0, game,
				"O mapa precisa estar cercado por paredes\n");
		j++;
	}
	return (0);
}

int	ft_check_composition(t_data *game)
{
	int	invalid_char;

	invalid_char = ft_check_objects(game->map);
	if (invalid_char > 0)
		ft_set_shutdown(0, game, "Possui algum caractere invalido\n");
	if (game->map->objects->max_player != 1)
		ft_set_shutdown(0, game, "Numero invalido de jogadores\n");
	if (game->map->objects->max_collectable < 1)
		ft_set_shutdown(0, game, "Falta al menos 1 coletavel\n");
	if (game->map->objects->max_exit != 1)
		ft_set_shutdown(0, game, "Numero invalido de saidas\n");
	return (0);
}

int	ft_check_path(t_data *game)
{
	t_check	valid_path;

	ft_set_path_check(game, &valid_path);
	if (valid_path.coins != game->map->objects->max_collectable)
		ft_set_shutdown(0, game, "O mapa não tem saida\n");
	if (valid_path.exit != game->map->objects->max_exit)
		ft_set_shutdown(0, game, "O mapa não tem saida\n");
	return (0);
}

static int	ft_check_objects(t_map *map)
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
				map->objects->max_player++;
			else if (map->grid[i][j] == map->objects->colect)
				map->objects->max_collectable++;
			else if (map->grid[i][j] == map->objects->exit)
				map->objects->max_exit++;
			else if (map->grid[i][j] != map->objects->empty &&
			map->grid[i][j] != map->objects->wall)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
