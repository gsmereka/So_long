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

#include "../header/so_long.h"

static void	closing_window(int close_window, t_data *game);
static void	free_grid(t_map *map);

void	set_shutdown(int close_window, t_data *game, char *error_msg)
{
	ft_putstr_fd(error_msg, 1);
	closing_window(close_window, game);
	free_structures(game);
	exit(0);
}

static void	closing_window(int close_window, t_data *game)
{
	if (close_window == 1)
	{
		if (game->floor->img[0] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->floor->img[0]);
		if (game->player->img[0] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->player->img[0]);
		if (game->player->img[1] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->player->img[1]);
		if (game->player->img[2] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->player->img[2]);
		if (game->player->img[3] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->player->img[3]);
		if (game->wall->img[0] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->wall->img[0]);
		if (game->colect->img[0] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->colect->img[0]);
		if (game->exit->img[0] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->exit->img[0]);
		mlx_destroy_window(game->win->ptr_mlx, game->win->ptr_win);
		game->win->ptr_win = NULL;
		mlx_destroy_display(game->win->ptr_mlx);
		free(game->win->ptr_mlx);
	}
}

void	free_structures(t_data *game)
{
	free_images(game->colect);
	free_images(game->exit);
	free_images(game->wall);
	free_images(game->player);
	free_images(game->floor);
	free_grid(game->map);
	free(game->map->objects);
	free(game->map->addr);
	free(game->map);
	free(game->win);
}

static void	free_grid(t_map *map)
{
	int		i;
	char	**grid;

	i = map->max_lines;
	while (i >= 0)
	{
		free(map->grid[i]);
		i--;
	}
	grid = map->grid;
	free(grid);
}
