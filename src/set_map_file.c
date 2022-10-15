/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:44:30 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/15 14:53:02 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

void	ft_set_map_file(int argc, char *addr, t_data *game)
{
	if (argc != 2)
		ft_set_shutdown(0, game, "Error\nOnly one map allowed.\n");
	if (ft_strncmp(addr + ft_strlen(addr) - 4, ".ber", 4) != 0)
		ft_set_shutdown(0, game, "Error\nYour map need to be '.ber'.\n");
	game->map->addr = ft_strdup(addr);
}
