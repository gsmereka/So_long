/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:01 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/17 13:49:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	draw_map(t_data *game);
static void	draw_steps(t_data *game);
static void	animate_sprites(t_sprites *sprite);
static void	draw_board(t_data *game);

int	set_images(t_data *game)
{
	game->map->grid[0][1] = 'S';
	game->map->grid[0][2] = 'S';
	if (game->map->objects->n_collectibles == 0)
		animate_sprites(game->exit);
	if (game->map->objects->n_enemies > 0)
		set_enemies_move(game);
	draw_steps(game);
	draw_board(game);
	draw_map(game);
	return (0);
}

static void	draw_steps(t_data *game)
{
	char	*steps;
	int		x;
	int		y;

	y = 30;
	while (y <= 45)
	{
		x = 160;
		while (x <= 200)
		{
			mlx_pixel_put(game->win->ptr_mlx,
				game->win->ptr_win, x, y, 0x000000);
			x++;
		}
		y++;
	}
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
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->board->img[2],
		80, 60);
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->board->img[1],
		80, 20);
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->board->img[3],
		220, 20);
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

static void	animate_sprites(t_sprites *sprite)
{
	static int	frame;

	if (frame == 2)
	{
		if (sprite->frame == 4)
			sprite->frame = 1;
		sprite->frame++;
		frame = 0;
	}
	frame++;
}
