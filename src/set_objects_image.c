/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:07:00 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 23:28:16 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	set_player_img(t_data *game);

void	set_objects_image(t_data *game)
{
	int	size;

	size = game->player->size;
	set_player_img(game);
	game->floor->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->floor->addr[0], &size, &size);
	game->wall->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->wall->addr[0], &size, &size);
	game->colect->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->colect->addr[0], &size, &size);
	game->exit->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[0], &size, &size);
}

static void	set_player_img(t_data *game)
{
	int	size;

	size = game->player->size;
	game->player->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[0], &size, &size);
	game->player->img[1] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[1], &size, &size);
	game->player->img[2] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[2], &size, &size);
	game->player->img[3] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->player->addr[3], &size, &size);
}
