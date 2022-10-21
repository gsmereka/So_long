/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:34:20 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/20 22:54:01 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static int	paint_next_steps(int x, int y, t_check *valid_path, t_data *game);
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
	valid_path->grid[y][x] = ' ';
	paint_next_steps(x, y, valid_path, game);
	free_check_grid(valid_path);
	return (0);
}

static int	paint_next_steps(int x, int y, t_check *valid_path, t_data *game)
{
	if (check_next_step(valid_path, x + 1, y) == 1)
	{
		valid_path->grid[y][x] = ' ';
		paint_next_steps(x + 1, y, valid_path, game);
	}
	if (check_next_step(valid_path, x - 1, y) == 1)
	{
		valid_path->grid[y][x] = ' ';
		paint_next_steps(x - 1, y, valid_path, game);
	}
	if (check_next_step(valid_path, x, y + 1) == 1)
	{
		valid_path->grid[y][x] = ' ';
		paint_next_steps(x, y + 1, valid_path, game);
	}
	if (check_next_step(valid_path, x, y - 1) == 1)
	{
		valid_path->grid[y][x] = ' ';
		paint_next_steps(x, y - 1, valid_path, game);
	}
	return (0);
}

static int	check_next_step(t_check *valid_path, int x, int y)
{
	if (valid_path->grid[y][x] == '1')
		return (0);
	else if (valid_path->grid[y][x] == ' ')
		return (0);
	else if (valid_path->grid[y][x] == 'C')
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
