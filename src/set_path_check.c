/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:34:20 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/25 04:04:41 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	paint_next_step(int x, int y, t_check *valid_path, t_data *game);
static int	check_next_step(t_check *valid_path, int x, int y);

static int	paint_next_step(int x, int y, t_check *valid_path, t_data *game);
static int	check_next_step(t_check *valid_path, int x, int y);

int	set_path_check(t_data *game, t_check *valid_path)
{
	int	x;
	int	y;

	set_check_variables(valid_path, game);
	copy_grid(valid_path, game);
	find_player(valid_path, game);
	y = valid_path->player_y;
	x = valid_path->player_x;
	paint_next_step(x, y, valid_path, game);
	free_check_grid(valid_path);
	return (0);
}

static int	paint_next_step(int x, int y, t_check *valid_path, t_data *game)
{
	valid_path->grid[y][x] = ' ';
	if (x + 1 < game->map->col - 1)
	{
		if (check_next_step(valid_path, x + 1, y) == 1)
			paint_next_step(x + 1, y, valid_path, game);
	}
	if (x - 1 > 0)
	{
		if (check_next_step(valid_path, x - 1, y) == 1)
			paint_next_step(x - 1, y, valid_path, game);
	}
	if (y + 1 < game->map->lin - 1)
	{
		if (check_next_step(valid_path, x, y + 1) == 1)
			paint_next_step(x, y + 1, valid_path, game);
	}
	if (y - 1 > 0)
	{
		if (check_next_step(valid_path, x, y - 1) == 1)
			paint_next_step(x, y - 1, valid_path, game);
	}
	return (0);
}

static int	check_next_step(t_check *valid_path, int x, int y)
{
	if (valid_path->grid[y][x] == 'C')
	{
		valid_path->coins++;
		return (1);
	}
	else if (valid_path->grid[y][x] == 'E' && valid_path->exit < 1)
	{
		valid_path->exit++;
		return (0);
	}
	else if (valid_path->grid[y][x] == '0')
	{
		return (1);
	}
	return (0);
}
