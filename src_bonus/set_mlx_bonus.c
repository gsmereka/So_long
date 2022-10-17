/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   set_mlx.c									   :+:	  :+:	:+:   */
/*	                                                +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:28:26 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 11:15:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	set_window_size(t_data *game);
static int	create_window(t_data *game);
static void	set_hook(t_data *game);

void	set_mlx(t_data *game)
{
	set_window_size(game);
	create_window(game);
	set_objects_image(game);
	set_hook(game);
}

static void	set_window_size(t_data *game)
{
	int	width;
	int	height;

	width = game->player->size * game->map->col;
	height = game->player->size * game->map->lin;
	game->win->width = width;
	game->win->height = height;
}

static int	create_window(t_data *game)
{
	game->win->ptr_mlx = mlx_init();
	if (game->win->ptr_mlx == NULL)
		set_shutdown(2, game, "Error\nError initializing mlx\n");
	game->win->ptr_win = mlx_new_window(game->win->ptr_mlx, game->win->width,
			game->win->height, "Retrieve the crystals and get out of there!");
	if (game->win->ptr_win == NULL)
	{
		free(game->win->ptr_win);
		set_shutdown(2, game, "Error\nError initializing mlx\n");
	}
	return (0);
}

static void	set_hook(t_data *game)
{
	mlx_hook(game->win->ptr_win,
		DestroyNotify, NoEventMask, &close_window, game);
	mlx_hook(game->win->ptr_win, KeyPress,
		KeyPressMask, &set_commands, game);
	mlx_loop_hook(game->win->ptr_mlx, &set_images, game);
	mlx_expose_hook(game->win->ptr_win, &set_images, game);
}
