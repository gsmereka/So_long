/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:35 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/16 01:39:56 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	draw_sprite(int y, int x, t_sprites *sprite, t_window *win)
{
	sprite->x = x * 80;
	sprite->y = y * 80;
	mlx_put_image_to_window(win->ptr_mlx,
		win->ptr_win, sprite->img[0], sprite->x, sprite->y);
}

void	draw_player(int y, int x, t_data *game)
{
	int	frame;

	frame = game->player->frame;
	game->player->x = x * game->player->size;
	game->player->y = y * game->player->size;
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->player->img[frame],
		game->player->x, game->player->y);
}
