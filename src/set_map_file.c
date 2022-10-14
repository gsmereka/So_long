/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:44:30 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/13 12:33:58 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

void	ft_set_map_file(int argc, char *addr, t_data *game)
{
	if (argc != 2)
		ft_set_shutdown(0, game, "Aceitamos apenas um mapa aqui\n");
	if (ft_strncmp(addr + ft_strlen(addr) - 4, ".ber", 4) != 0)
		ft_set_shutdown(0, game, "Seu mapa n tem .ber no final, amigo\n");
	game->map->addr = ft_strdup(addr);
}
