/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:12:25 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 23:39:24 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

static int	can_walk(t_data *game, int x, int y);
static int	walk(int dir, t_data *game, char axis);

int	ft_set_commands(int keysym, t_data *game)
{
	int		direction;
	char	axis_x;
	char	axis_y;

	direction = 1;
	axis_x = 'x';
	axis_y = 'y';
	if (keysym == XK_Escape)
		ft_set_shutdown(1, game, "See you soon!!!\n");
	if (keysym == XK_w)
		walk(-direction, game, axis_y);
	else if (keysym == XK_s)
		walk(direction, game, axis_y);
	else if (keysym == XK_a)
		walk(-direction, game, axis_x);
	else if (keysym == XK_d)
		walk(direction, game, axis_x);
	return (0);
}

static int	walk(int dir, t_data *game, char axis)
{
	int	x;
	int	y;

	x = game->player->x / 80;
	y = game->player->y / 80;
	if (axis == 'y')
	{
		if (can_walk(game, x, y + dir) == 1)
		{
			game->player->y += game->player->speed * dir;
			game->player->moves++;
		}
	}
	if (axis == 'x')
	{
		if (can_walk(game, x + dir, y) == 1)
		{
			game->player->x += game->player->speed * dir;
			game->player->moves++;
		}
	}
	printf("Passos: %d (x=%d,y=%d)\n", game->player->moves, x, y);
	return (0);
}

static int	can_walk(t_data *game, int x, int y)
{
	if (game->map->grid[y][x] != game->map->objects->wall)
	{
		if (game->map->grid[y][x] == game->map->objects->colect)
		{
			game->map->objects->max_collectable--;
			game->map->grid[y][x] = game->map->objects->empty;
			return (1);
		}
		else if (game->map->grid[y][x] == game->map->objects->exit)
		{
			if (game->map->objects->max_collectable == 0)
				ft_set_shutdown(1, game, "Congratulations!!!\n");
		}
		else
			return (1);
	}
	return (0);
}
