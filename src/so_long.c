/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:30:38 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 23:28:53 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// make && make clean && clang so_long.a 
// -lX11 -lXext -lmlx && clear && ./a.out ./src/maps

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
