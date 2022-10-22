/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_tools_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:35 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/22 01:19:23 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

void	draw_sprite(int y, int x, t_sprites *sprite, t_window *win)
{
	int	frame;

	frame = sprite->frame;
	sprite->x = x * sprite->size;
	sprite->y = y * sprite->size;
	mlx_put_image_to_window(win->ptr_mlx,
		win->ptr_win, sprite->img[frame], sprite->x, sprite->y);
}

void	draw(int i, int j, t_data *game, char object)
{
	if (object == 'f')
		draw_sprite(i, j, game->floor, game->win);
	if (object == 'x')
		draw_sprite(i, j, game->enemy, game->win);
	if (object == 'P')
		draw_sprite(i, j, game->player, game->win);
	if (object == 'w')
		draw_sprite(i, j, game->wall, game->win);
	if (object == 'e')
		draw_sprite(i, j, game->exit, game->win);
	if (object == 'c')
		draw_sprite(i, j, game->colect, game->win);
}
