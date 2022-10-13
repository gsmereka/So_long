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
static void	ft_create_coin(t_data *game);
static void	ft_create_exit(t_data *game);

void	ft_set_objects(t_data *game)
{
	ft_create_wall(game);
	ft_create_exit(game);
	ft_create_coin(game);
	ft_create_player(game);
}

static void	ft_create_player(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	game->player->moves = 0;
	game->player->largura = 80;
	game->player->altura = 80;
	game->player->speed = 80;
	game->player->cor = RED_PIXEL;
	while (y < game->map->lin)
	{
		x = 0;
		while (x < game->map->col)
		{
			if (game->map->grid[y][x] == game->map->objects->start)
			{
				game->player->x = x * game->player->largura;
				game->player->y = y * game->player->altura;
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
	game->wall->largura = 80;
	game->wall->altura = 80;
	game->wall->cor = BLACK_PIXEL;
}

static void	ft_create_exit(t_data *game)
{
	game->exit->x = 0;
	game->exit->y = 0;
	game->exit->largura = 80;
	game->exit->altura = 80;
	game->exit->cor = NAVY_BLUE;
}

static void	ft_create_coin(t_data *game)
{
	game->coin->x = 0;
	game->coin->y = 0;
	game->coin->largura = 80;
	game->coin->altura = 80;
	game->coin->cor = GREEN_YELLOW;
}
