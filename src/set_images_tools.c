/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:35 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 13:06:50 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

void	ft_draw_floor(int y, int x, t_data *game)
{
	game->floor->x = x * game->wall->size;
	game->floor->y = y * game->wall->size;
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->floor->img[0],
		game->floor->x, game->floor->y);
}

void	ft_draw_wall(int y, int x, t_data *game)
{
	game->wall->x = x * game->wall->size;
	game->wall->y = y * game->wall->size;
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->wall->img[0], game->wall->x, game->wall->y);
}

void	ft_draw_colect(int y, int x, t_data *game)
{
	game->colect->x = x * game->wall->size;
	game->colect->y = y * game->wall->size;
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->colect->img[0],
		game->colect->x, game->colect->y);
}

void	ft_draw_exit(int y, int x, t_data *game)
{
	game->exit->x = x * game->wall->size;
	game->exit->y = y * game->wall->size;
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->exit->img[0], game->exit->x, game->exit->y);
}

void	ft_draw_player(int y, int x, t_data *game)
{
	int	frame;

	frame = game->player->frame;
	game->player->x = x * game->wall->size;
	game->player->y = y * game->wall->size;
	mlx_put_image_to_window(game->win->ptr_mlx,
		game->win->ptr_win, game->player->img[frame],
		game->player->x, game->player->y);
}
