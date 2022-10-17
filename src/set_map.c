/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:10:21 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:45:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	count_col(t_data *game);
static void	count_lines(t_data *game);
static void	check_format(t_data *game);
static int	validate_map(t_data *game);

void	set_map(t_data *game)
{
	game->map->fd = open(game->map->addr, O_RDWR);
	count_lines(game);
	count_col(game);
	check_format(game);
	validate_map(game);
	close(game->map->fd);
}

static void	count_lines(t_data *game)
{
	int	lines;

	lines = 0;
	while (lines < game->map->max_lines)
	{
		game->map->grid[lines] = get_next_line(game->map->fd, 0);
		if (game->map->grid[lines] == NULL)
			break ;
		lines++;
	}
	game->map->grid[lines] = get_next_line(game->map->fd, 1);
	if (game->map->grid[lines] != NULL)
		set_shutdown(0, game, "Error\nThe map is too big.\n");
	if (lines <= 2)
		set_shutdown(0, game,
			"Error\nThe map has less than 3 lines or is invalid.\n");
	game->map->lin = lines;
}

static void	count_col(t_data *game)
{
	int	lines;
	int	cols_nmb;

	lines = game->map->lin;
	cols_nmb = (int)strlen(game->map->grid[lines - 1]);
	if (cols_nmb < 3)
		set_shutdown(0, game,
			"Error\nThe map has less than 3 columns.\n");
	if (cols_nmb > game->map->max_cols)
		set_shutdown(0, game, "Error\nThe map is too big.\n");
	game->map->col = cols_nmb;
}

static void	check_format(t_data *game)
{
	int	i;
	int	cols;
	int	last_line;

	i = 0;
	last_line = game->map->lin;
	while (i < last_line - 1)
	{
		cols = (int)strlen(game->map->grid[i]);
		if (cols != game->map->col + 1)
			set_shutdown(0, game, "Error\nthe map is not rectangular.\n");
		i++;
	}
}

static int	validate_map(t_data *game)
{
	check_walls(game);
	check_composition(game);
	check_path(game);
	return (1);
}
