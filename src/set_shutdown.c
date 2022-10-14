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

#include "../header/data.h"

void	ft_free_grid(t_map *map)
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

void	ft_set_shutdown(int close_window, t_data *game, char *error_msg)
{
	printf("%s", error_msg);
	ft_finish_game(close_window, game);
	exit(0);
}

void	ft_finish_game(int close_window, t_data *game)
{
	free(game->play->addr);
	free(game->floor->addr);
	if (close_window == 1)
	{
		if (game->floor->img != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->floor->img);
		if (game->play->img != NULL)
			mlx_destroy_image(game->win->ptr_mlx, game->play->img);
		mlx_destroy_window(game->win->ptr_mlx, game->win->ptr_win);
		game->win->ptr_win = NULL;
		mlx_destroy_display(game->win->ptr_mlx);
		free(game->win->ptr_mlx);
	}
	ft_free_grid(game->map);
	free(game->exit);
	free(game->coin);
	free(game->wall);
	free(game->player);
	free(game->map->objects);
	free(game->map->addr);
	free(game->map);
	free(game->play);
	free(game->floor);
	free(game->win);
}

int	close_window(t_data *game)
{
	ft_set_shutdown(1, game, "See you soon!!!\n");
	return (0);
}
