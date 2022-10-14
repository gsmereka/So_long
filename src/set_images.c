/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:01 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/13 23:36:50 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

int	draw_map(t_data *game);
static void	draw(int i, int j, t_data *game, char object);

int	ft_set_images(t_data *game)
{
	if (game->win->ptr_win == NULL)
		return (1);
	// pintar_fundo(game);
	draw_map(game);
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->floor->img, 0, 0);
	draw_object(game->img, game->player);
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->img->mlx_img, 0, 0);
	return (0);
}

int	draw_map(t_data *game)
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
		game->floor->x = j * game->wall->largura;
		game->floor->y = i * game->wall->altura;
		mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->floor->img, game->floor->x, game->floor->y);
	}
	if (object == 'w')
	{
		game->wall->x = j * game->wall->largura;
		game->wall->y = i * game->wall->altura;
		draw_object(game->img, game->wall);
	}
	else if (object == 'e')
	{
		game->exit->x = j * game->exit->largura;
		game->exit->y = i * game->exit->altura;
		draw_object(game->img, game->exit);
	}
	else if (object == 'c')
	{
		game->coin->x = j * game->coin->largura;
		game->coin->y = i * game->coin->altura;
		draw_object(game->img, game->coin);
	}
}
