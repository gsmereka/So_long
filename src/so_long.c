/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:30:38 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/18 10:20:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int argc, char *argv[])
{
	t_data		game;
	t_config	config;

	set_oppening(&game, &config);
	set_values(&game, &config);
	set_map_file(argc, argv[1], &game);
	set_sprites(&game);
	set_map(&game);
	set_objects(&game);
	set_mlx(&game);
	mlx_loop(game.win->ptr_mlx);
	set_shutdown(1, &game, "");
	return (0);
}
