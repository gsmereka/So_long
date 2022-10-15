/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:07:00 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 15:07:07 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

static void	set_player_img(t_data *game);

void	set_objects_image(t_data *game)
{
	int	x;
	int	y;

	x = 80;
	y = 80;
	set_player_img(game);
	game->floor->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->floor->addr[0], &x, &y);
	game->wall->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->wall->addr[0], &x, &x);
	game->colect->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->colect->addr[0], &x, &x);
	game->exit->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[0], &x, &x);
}

static void	set_player_img(t_data *game)
{
	int	x;

	x = 80;
	game->player->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[0], &x, &x);
	game->player->img[1] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[1], &x, &x);
	game->player->img[2] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[2], &x, &x);
	game->player->img[3] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[3], &x, &x);
}
