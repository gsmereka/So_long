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

#include "../header/data.h"

static void	ft_create_player(t_data *game);
static void	ft_create_wall(t_data *game);
static void	ft_create_colect(t_data *game);
static void	ft_create_exit(t_data *game);

void	ft_set_objects(t_data *game)
{
	ft_create_wall(game);
	ft_create_exit(game);
	ft_create_colect(game);
	ft_create_player(game);
}

static void	ft_create_player(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	game->player->frame = 2;
	game->player->size = 80;
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

static void	ft_create_wall(t_data *game)
{
	game->wall->x = 0;
	game->wall->y = 0;
	game->wall->size = 80;
}

static void	ft_create_exit(t_data *game)
{
	game->exit->x = 0;
	game->exit->y = 0;
	game->exit->size = 80;
}

static void	ft_create_colect(t_data *game)
{
	game->colect->x = 0;
	game->colect->y = 0;
	game->colect->size = 80;
}
