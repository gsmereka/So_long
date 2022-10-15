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

#include "../header/data.h"

static void	ft_set_window_size(t_data *game);
static int	ft_create_window(t_data *game);
static void	ft_set_hook(t_data *game);

void	ft_set_mlx(t_data *game)
{
	ft_set_window_size(game);
	ft_create_window(game);
	set_objects_image(game);
	ft_set_hook(game);
}

static void	ft_set_window_size(t_data *game)
{
	int	width;
	int	height;

	width = 80 * game->map->col;
	height = 80 * game->map->lin;
	game->win->width = width;
	game->win->height = height;
}

static int	ft_create_window(t_data *game)
{
	game->win->ptr_mlx = mlx_init();
	if (game->win->ptr_mlx == NULL)
		ft_set_shutdown(0, game, "Error\nError initializing mlx\n");
	game->win->ptr_win = mlx_new_window(game->win->ptr_mlx, game->win->width,
			game->win->height, "Retrieve the crystals and get out of there!");
	if (game->win->ptr_win == NULL)
	{
		free(game->win->ptr_win);
		ft_set_shutdown(0, game, "Error\nError initializing mlx\n");
	}
	return (0);
}

static void	ft_set_hook(t_data *game)
{
	mlx_hook(game->win->ptr_win,
		DestroyNotify, NoEventMask, &close_window, game);
	mlx_hook(game->win->ptr_win, KeyPress,
		KeyPressMask, &ft_set_commands, game);
	mlx_expose_hook(game->win->ptr_win, &ft_set_images, game);
	mlx_loop_hook(game->win->ptr_mlx, &ft_set_images, game);
}
