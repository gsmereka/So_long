/* ************************************************************************** */
/*						                                                    */
/*                                                        :::      ::::::::   */
/*   set_shutdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:50:40 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:50:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

int	close_window(t_data *game)
{
	set_shutdown(1, game, "");
	return (0);
}

void	free_images(t_sprites *sprites)
{
	int	i;

	i = 0;
	while (i < sprites->n_frames)
	{
		free(sprites->addr[i]);
		i++;
	}
	free(sprites->addr);
	free(sprites->img);
	free(sprites);
}

void	destroy_images(t_sprites *sprite, t_data *game)
{
	int	i;

	i = 0;
	while (i < sprite->n_frames)
	{
		if (sprite->img[i] != NULL)
			mlx_destroy_image(game->win->ptr_mlx, sprite->img[i]);
		i++;
	}
}
