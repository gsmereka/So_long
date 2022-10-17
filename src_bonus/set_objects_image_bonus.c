/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects_image_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:07:00 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/17 13:37:29 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	set_player_img(t_data *game);
static void	set_exit_img(t_data *game);
static void	set_board_img(t_data *game);

void	set_objects_image(t_data *game)
{
	int	size;

	size = game->player->size;
	set_player_img(game);
	set_exit_img(game);
	set_board_img(game);
	game->enemy->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->enemy->addr[0], &size, &size);
	game->floor->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->floor->addr[0], &size, &size);
	game->wall->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->wall->addr[0], &size, &size);
	game->colect->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->colect->addr[0], &size, &size);
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

static void	set_exit_img(t_data *game)
{
	int	size;

	size = game->exit->size;
	game->exit->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[0], &size, &size);
	game->exit->img[1] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[1], &size, &size);
	game->exit->img[2] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[2], &size, &size);
	game->exit->img[3] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[3], &size, &size);
	game->exit->img[4] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->exit->addr[4], &size, &size);
}

static void	set_board_img(t_data *game)
{
	int	corners;
	int	up_down;
	int	dense;

	corners = 40;
	up_down = 160;
	dense = 20;
	game->board->img[0] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->board->addr[0], &up_down, &dense);
	game->board->img[1] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->board->addr[1], &dense, &corners);
	game->board->img[2] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->board->addr[2], &up_down, &dense);
	game->board->img[3] = mlx_xpm_file_to_image(game->win->ptr_mlx,
			game->board->addr[3], &dense, &corners);
}
