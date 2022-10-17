/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:01 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/16 01:34:27 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	draw_map(t_data *game);
static void	draw(int i, int j, t_data *game, char object);

int	set_images(t_data *game)
{
	draw_map(game);
	return (0);
}

static int	draw_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->lin)
	{
		j = 0;
		while (j < game->map->col)
		{
			if (game->map->grid[i][j] == '0')
				draw(i, j, game, 'f');
			else if (game->map->grid[i][j] == 'P')
				draw(i, j, game, 'P');
			if (game->map->grid[i][j] == game->map->objects->wall)
				draw(i, j, game, 'w');
			else if (game->map->grid[i][j] == game->map->objects->exit)
				draw(i, j, game, 'e');
			else if (game->map->grid[i][j] == game->map->objects->colect)
				draw(i, j, game, 'c');
			j++;
		}
		i++;
	}
	return (0);
}

static void	draw(int i, int j, t_data *game, char object)
{
	if (object == 'f')
		draw_sprite(i, j, game->floor, game->win);
	if (object == 'P')
	{
		draw_player(i, j, game);
	}
	if (object == 'w')
		draw_sprite(i, j, game->wall, game->win);
	if (object == 'e')
		draw_sprite(i, j, game->exit, game->win);
	if (object == 'c')
		draw_sprite(i, j, game->colect, game->win);
}
