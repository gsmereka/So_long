/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_check_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:38:40 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/21 18:16:56 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	find_player(t_check *valid_path, t_data *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map->lin)
	{
		x = 0;
		while (x < game->map->col)
		{
			if (valid_path->grid[y][x] == game->map->objects->start)
			{
				valid_path->player_x = x;
				valid_path->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	copy_grid(t_check *valid_path, t_data *game)
{
	int	i;

	i = 0;
	while (i < game->map->lin)
	{
		valid_path->grid[i] = ft_strdup(game->map->grid[i]);
		i++;
	}
}

void	set_check_variables(t_check *valid_path, t_data *game)
{
	int	i;

	i = 0;
	valid_path->player_x = 0;
	valid_path->player_y = 0;
	valid_path->max_lines = game->map->max_lines;
	valid_path->max_cols = game->map->max_cols;
	valid_path->lines = game->map->lin;
	valid_path->cols = game->map->col;
	valid_path->coins = 0;
	valid_path->start = 0;
	valid_path->exit = 0;
	valid_path->grid = (char **)malloc((valid_path->max_lines + 1)
			* sizeof (int *));
	if (!valid_path->grid)
		set_shutdown(0, game, "Error\nFail to alloc memory\n");
	while (i < valid_path->max_lines + 1)
	{
		valid_path->grid[i] = NULL;
		i++;
	}
}

void	free_check_grid(t_check *valid_path)
{
	int		i;

	i = valid_path->max_lines;
	while (i >= 0)
	{
		free(valid_path->grid[i]);
		i--;
	}
	free(valid_path->grid);
}
