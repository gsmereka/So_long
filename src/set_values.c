/* ************************************************************************** */
/*						                                                    */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:34:38 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 14:51:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	set_variables(t_data *game, t_config *config);
static void	init_sprites_values(t_sprites *sprites);

void	set_values(t_data *game, t_config *config)
{
	set_variables(game, config);
	game->floor->n_frames = 1;
	game->wall->n_frames = 1;
	game->colect->n_frames = 1;
	game->exit->n_frames = 1;
	game->player->n_frames = 4;
	game->player->size = 80;
	init_sprites_values(game->wall);
	init_sprites_values(game->floor);
	init_sprites_values(game->exit);
	init_sprites_values(game->colect);
	init_sprites_values(game->player);
}

static void	set_variables(t_data *game, t_config *config)
{
	int	i;

	i = 0;
	game->map->objects->start = config->start;
	game->map->objects->wall = config->wall;
	game->map->objects->empty = config->empty;
	game->map->objects->colect = config->colect;
	game->map->objects->exit = config->exit;
	game->map->max_lines = config->max_lines;
	game->map->max_cols = config->max_cols;
	game->map->objects->n_players = 0;
	game->map->objects->n_exits = 0;
	game->map->objects->n_collectibles = 0;
	game->map->player_moves = 0;
	game->map->addr = NULL;
	while (i < config->max_lines + 1)
	{
		game->map->grid[i] = NULL;
		i++;
	}
}

static void	init_sprites_values(t_sprites *sprites)
{
	int	i;

	i = 0;
	while (i < sprites->n_frames)
	{
		sprites->addr[i] = NULL;
		i++;
	}
}
