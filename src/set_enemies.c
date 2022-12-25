/* ************************************************************************** */
/*					                                                        */
/*                                                        :::      ::::::::   */
/*   set_enemies_move_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:58:36 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/16 16:31:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	alloc_enemies_pos(t_data *game);
static void	save_enemies_pos(t_data *game);

void	set_enemies(t_data *game)
{
	alloc_enemies_pos(game);
	save_enemies_pos(game);
}

static void	alloc_enemies_pos(t_data *game)
{
	game->enemy->pos = (char **)malloc(game->map->objects->n_enemies
			* sizeof(char *));
	if (!game->enemy->pos)
		set_shutdown(0, game, "Error\nMemory Error.\n");
}

static void	save_enemies_pos(t_data *game)
{
	int	y;
	int	x;
	int	enemy;

	y = 0;
	x = 0;
	enemy = 0;
	while (y < game->map->lin)
	{
		x = 0;
		while (x < game->map->col)
		{
			if (game->map->grid[y][x] == game->map->objects->enemy)
			{
				game->enemy->pos[enemy] = (char *)malloc(4 * sizeof(char));
				game->enemy->pos[enemy][0] = x + '0';
				game->enemy->pos[enemy][1] = y + '0';
				game->enemy->pos[enemy][2] = 1 + '0';
				game->enemy->pos[enemy][3] = '\0';
				enemy++;
			}
			x++;
		}
		y++;
	}
}
