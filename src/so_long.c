/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:30:38 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/14 09:23:52 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

// make && make clean && clang so_long.a 
// -lX11 -lXext -lmlx && clear && ./a.out && clear

int	main(int argc, char *argv[])
{
	t_data		game;
	t_config	config;

	ft_set_oppening(&game, &config);
	game.floor->addr = ft_strdup("./floor.xpm");
	game.play->addr = ft_strdup("./mago.xpm");
	ft_set_map_file(argc, argv[1], &game);
	ft_set_map(&game);
	ft_set_objects(&game);
	ft_set_mlx(&game);
	mlx_loop(game.win->ptr_mlx);
	ft_finish_game(1, &game);
	return (0);
}
