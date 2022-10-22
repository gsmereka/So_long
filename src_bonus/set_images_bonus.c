/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:01 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/22 01:16:18 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	draw_map(t_data *game);
static void	draw_steps(t_data *game);
static void	draw_board(t_data *game);

int	set_images(t_data *game)
{
	set_animations(game);
	draw_board(game);
	draw_steps(game);
	draw_map(game);
	return (0);
}

static void	draw_steps(t_data *game)
{
	char	*steps;

	steps = game->map->player_steps;
	mlx_string_put(game->win->ptr_mlx,
		game->win->ptr_win, 120, 45, 0xFFFFFF, "Steps:");
	mlx_string_put(game->win->ptr_mlx,
		game->win->ptr_win, 160, 45, 0xFFFFFF, steps);
}

static void	draw_board(t_data *game)
{
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->board->img[0],
		80, 0);
}

static void	draw_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->lin)
	{
		j = 0;
		while (j < game->map->col)
		{
			if (game->map->grid[i][j] == '0')
				draw(i, j, game, 'f');
			else if (game->map->grid[i][j] == 'X')
				draw(i, j, game, 'x');
			else if (game->map->grid[i][j] == 'P')
				draw(i, j, game, 'P');
			else if (game->map->grid[i][j] == game->map->objects->wall)
				draw(i, j, game, 'w');
			else if (game->map->grid[i][j] == game->map->objects->exit)
				draw(i, j, game, 'e');
			else if (game->map->grid[i][j] == game->map->objects->colect)
				draw(i, j, game, 'c');
			j++;
		}
		i++;
	}
}
