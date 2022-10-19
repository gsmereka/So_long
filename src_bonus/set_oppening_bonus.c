/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   set_oppening.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:23:34 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/10 16:05:06 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	set_sprites_memory(t_data *game);
static void	set_memory(t_data *game, t_config *config);
static void	set_config(t_config *config);

void	set_oppening(t_data *game, t_config *config)
{
	set_config(config);
	set_memory(game, config);
	set_sprites_memory(game);
}

static void	set_config(t_config *config)
{
	config->start = 'P';
	config->enemy = 'X';
	config->wall = '1';
	config->empty = '0';
	config->colect = 'C';
	config->exit = 'E';
	config->max_lines = 9;
	config->max_cols = 16;
}

static void	set_memory(t_data *game, t_config *config)
{
	game->win = malloc(sizeof(t_window));
	game->map = malloc(sizeof(t_map));
	game->map->grid = (char **)malloc((config->max_lines + 1) * sizeof (int *));
	game->map->objects = malloc(sizeof(t_objects));
	game->floor = malloc(sizeof(t_sprites));
	game->player = malloc(sizeof(t_sprites));
	game->board = malloc(sizeof(t_sprites));
	game->enemy = malloc(sizeof(t_sprites));
	game->wall = malloc(sizeof(t_sprites));
	game->colect = malloc(sizeof(t_sprites));
	game->exit = malloc(sizeof(t_sprites));
	if (!game->win || !game->map || !game->map->grid || !game->enemy
		|| !game->map->objects || !game->floor || !game->player || !game->wall
		|| !game->colect || !game->exit || !game->board)
		set_shutdown(0, game, "Error\nError allocating memory.");
}

static void	set_sprites_memory(t_data *game)
{
	game->floor->addr = (char **)malloc((1) * sizeof (int *));
	game->player->addr = (char **)malloc((4) * sizeof (int *));
	game->board->addr = (char **)malloc((1) * sizeof (int *));
	game->enemy->addr = (char **)malloc((4) * sizeof (int *));
	game->wall->addr = (char **)malloc((1) * sizeof (int *));
	game->colect->addr = (char **)malloc((1) * sizeof (int *));
	game->exit->addr = (char **)malloc((5) * sizeof (int *));
	game->floor->img = (void **)malloc((1) * sizeof (int *));
	game->player->img = (void **)malloc((4) * sizeof (int *));
	game->board->img = (void **)malloc((1) * sizeof (int *));
	game->enemy->img = (void **)malloc((4) * sizeof (int *));
	game->wall->img = (void **)malloc((1) * sizeof (int *));
	game->colect->img = (void **)malloc((1) * sizeof (int *));
	game->exit->img = (void **)malloc((5) * sizeof (int *));
	if (!game->floor->addr || !game->player->addr || !game->wall->addr
		|| !game->colect->addr || !game->exit->addr || !game->floor->img
		|| !game->player->img || !game->exit->img || !game->colect->img
		|| !game->wall->img || !game->enemy->addr || !game->enemy->img
		|| !game->board->addr || !game->board->img)
		set_shutdown(0, game, "Error\nError allocating memory.");
}
