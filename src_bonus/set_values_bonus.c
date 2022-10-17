/* ************************************************************************** */
/*						                                                    */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/00/15 14:34:38 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 14:51:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	set_variables(t_data *game, t_config *config);
static void	set_frames(t_data *game);
static void	init_sprites_values(t_sprites *sprites);

void	set_values(t_data *game, t_config *config)
{
	set_variables(game, config);
	game->floor->n_frames = 1;
	game->wall->n_frames = 1;
	game->colect->n_frames = 1;
	game->exit->n_frames = 5;
	game->player->n_frames = 4;
	game->board->n_frames = 4;
	game->enemy->n_frames = 1;
	game->player->size = 80;
	set_frames(game);
	init_sprites_values(game->wall);
	init_sprites_values(game->floor);
	init_sprites_values(game->exit);
	init_sprites_values(game->colect);
	init_sprites_values(game->player);
	init_sprites_values(game->board);
	init_sprites_values(game->enemy);
}

static void	set_variables(t_data *game, t_config *config)
{
	int	i;

	i = 0;
	game->map->objects->start = config->start;
	game->map->objects->enemy = config->enemy;
	game->map->objects->wall = config->wall;
	game->map->objects->empty = config->empty;
	game->map->objects->colect = config->colect;
	game->map->objects->exit = config->exit;
	game->map->max_lines = config->max_lines;
	game->map->max_cols = config->max_cols;
	game->map->player_steps = ft_strdup("0");
	game->map->objects->n_players = 0;
	game->map->objects->n_exits = 0;
	game->map->objects->n_collectibles = 0;
	game->map->objects->n_enemies = 0;
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

static void	set_frames(t_data *game)
{
	game->floor->frame = 0;
	game->wall->frame = 0;
	game->colect->frame = 0;
	game->exit->frame = 0;
	game->player->frame = 0;
	game->enemy->frame = 0;
	game->floor->size = 80;
	game->wall->size = 80;
	game->colect->size = 80;
	game->exit->size = 80;
	game->player->size = 80;
	game->enemy->size = 80;
}
