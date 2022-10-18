/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:05:38 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 11:05:38 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	create_player(t_data *game);

void	set_objects(t_data *game)
{
	create_player(game);
}

static void	create_player(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	game->player->frame = 2;
	while (y < game->map->lin)
	{
		x = 0;
		while (x < game->map->col)
		{
			if (game->map->grid[y][x] == game->map->objects->start)
			{
				game->player->x = x * game->player->size;
				game->player->y = y * game->player->size;
			}
			x++;
		}
		y++;
	}
}
