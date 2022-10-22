/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:12:25 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/21 18:34:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	can_walk(t_data *game, int x, int y);
static int	walk(int dir, t_data *game, char axis);
static void	move_player(t_data *game, int dir, char axis);

int	set_commands(int keysym, t_data *game)
{
	int		direction;
	char	axis_x;
	char	axis_y;

	direction = 1;
	axis_x = 'x';
	axis_y = 'y';
	if (keysym == XK_Escape)
		set_shutdown(1, game, "");
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

	x = game->player->x / game->player->size;
	y = game->player->y / game->player->size;
	if (axis == 'y')
	{
		game->player->frame = 1 + dir;
		if (can_walk(game, x, y + dir) == 1)
			move_player(game, dir, 'y');
	}
	if (axis == 'x')
	{
		game->player->frame = 2 + dir;
		if (can_walk(game, x + dir, y) == 1)
			move_player(game, dir, 'x');
	}
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->map->player_moves, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

static int	can_walk(t_data *game, int x, int y)
{
	if (game->map->grid[y][x] != game->map->objects->wall)
	{
		if (game->map->grid[y][x] == game->map->objects->colect)
		{
			game->map->objects->n_collectibles--;
			return (1);
		}
		else if (game->map->grid[y][x] == game->map->objects->exit)
		{
			if (game->map->objects->n_collectibles == 0)
				set_shutdown(1, game, "");
			return (0);
		}
		else
			return (1);
	}
	return (0);
}

static void	move_player(t_data *game, int dir, char axis)
{
	int	x;
	int	y;

	x = game->player->x / game->player->size;
	y = game->player->y / game->player->size;
	if (axis == 'x')
	{
		game->map->grid[y][x] = '0';
		game->player->x = (x + dir) * game->player->size;
		game->map->grid[y][x + dir] = 'P';
		game->map->player_moves++;
	}
	else if (axis == 'y')
	{
		game->map->grid[y][x] = '0';
		game->player->y = (y + dir) * game->player->size;
		game->map->grid[y + dir][x] = 'P';
		game->map->player_moves++;
	}
}
