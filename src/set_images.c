/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:01 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/14 19:47:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

static int	draw_map(t_data *game);
static void	draw(int i, int j, t_data *game, char object);

int	ft_set_images(t_data *game)
{
	draw_map(game);
	return (0);
}

static int	draw_map(t_data *game)
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
			else if (game->map->grid[i][j] == 'P')
				draw(i, j, game, 'P');
			if (game->map->grid[i][j] == game->map->objects->wall)
				draw(i, j, game, 'w');
			else if (game->map->grid[i][j] == game->map->objects->exit)
				draw(i, j, game, 'e');
			else if (game->map->grid[i][j] == game->map->objects->colect)
				draw(i, j, game, 'c');
			j++;
		}
		i++;
	}
	return (0);
}

static void	draw(int i, int j, t_data *game, char object)
{
	if (object == 'f')
	{
		ft_draw_floor(i, j, game);
	}
	if (object == 'P')
	{
		ft_draw_player(i, j, game);
	}
	if (object == 'w')
	{
		ft_draw_wall(i, j, game);
	}
	else if (object == 'e')
	{
		ft_draw_exit(i, j, game);
	}
	else if (object == 'c')
	{
		ft_draw_colect(i, j, game);
	}
}
