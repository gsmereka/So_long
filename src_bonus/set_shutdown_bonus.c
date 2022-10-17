/* ************************************************************************** */
/*						                                                    */
/*                                                        :::      ::::::::   */
/*   set_shutdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:50:40 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:50:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	closing_window(int close_window, t_data *game);
static void	free_grid(char **grid, int lines);

void	set_shutdown(int close_window, t_data *game, char *error_msg)
{
	ft_putstr_fd(error_msg, 1);
	closing_window(close_window, game);
	free_structures(close_window, game);
	exit(0);
}

static void	closing_window(int close_window, t_data *game)
{
	if (close_window == 1)
	{
		destroy_images(game->floor, game);
		destroy_images(game->player, game);
		destroy_images(game->board, game);
		destroy_images(game->enemy, game);
		destroy_images(game->exit, game);
		destroy_images(game->wall, game);
		destroy_images(game->colect, game);
		mlx_destroy_window(game->win->ptr_mlx, game->win->ptr_win);
		game->win->ptr_win = NULL;
		mlx_destroy_display(game->win->ptr_mlx);
		free(game->win->ptr_mlx);
	}
}

void	free_structures(int close_window, t_data *game)
{
	if (close_window > 0)
		free_grid(game->enemy->pos, game->map->objects->n_enemies - 1);
	free_images(game->colect);
	free_images(game->exit);
	free_images(game->wall);
	free_images(game->player);
	free_images(game->enemy);
	free_images(game->board);
	free_images(game->floor);
	free_grid(game->map->grid, game->map->lin);
	free(game->map->player_steps);
	free(game->map->objects);
	free(game->map->addr);
	free(game->map);
	free(game->win);
}

static void	free_grid(char **grid, int lines)
{
	while (lines >= 0)
	{
		free(grid[lines]);
		lines--;
	}
	free(grid);
}
