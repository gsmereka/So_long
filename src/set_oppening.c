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

#include "../header/data.h"

void	ft_set_oppening(t_data *game, t_config *config)
{
	ft_set_config(config);
	ft_set_memory(game, config);
	ft_set_variables(game, config);
}

void	ft_set_config(t_config *config)
{
	config->start = 'P';
	config->wall = '1';
	config->empty = '0';
	config->colect = 'C';
	config->exit = 'E';
	config->max_lines = 9;
	config->max_cols = 16;
}

void	ft_set_memory(t_data *game, t_config *config)
{
	game->win = malloc(sizeof(t_window));
	game->img = malloc(sizeof(t_img));
	game->map = malloc(sizeof(t_map));
	game->map->grid = (char **)malloc((config->max_lines + 1) * sizeof (int *));
	game->map->objects = malloc(sizeof(t_objects));
	game->player = malloc(sizeof(t_rect));
	game->wall = malloc(sizeof(t_rect));
	game->coin = malloc(sizeof(t_rect));
	game->exit = malloc(sizeof(t_rect));
	if (!game->win || !game->img || !game->map || !game->map->grid
		|| !game->map->objects || !game->player || !game->wall
		|| !game->coin || !game->exit)
		ft_set_shutdown(0, game, "Erro na alocação de memoria\n");
}

void	ft_set_variables(t_data *game, t_config *config)
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
	game->map->objects->max_player = 0;
	game->map->objects->max_exit = 0;
	game->map->objects->max_collectable = 0;
	game->map->addr = NULL;
	while (i < config->max_lines + 1)
	{
		game->map->grid[i] = NULL;
		i++;
	}
}
