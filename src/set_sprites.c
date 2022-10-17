/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:48:10 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/14 15:26:57 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	set_sprites(t_data *game)
{
	game->floor->addr[0] = ft_strdup("./sprites/floor.xpm");
	game->colect->addr[0] = ft_strdup("./sprites/potion.xpm");
	game->wall->addr[0] = ft_strdup("./sprites/wall.xpm");
	game->exit->addr[0] = ft_strdup("./sprites/portal_0.xpm");
	game->player->addr[0] = ft_strdup("./sprites/mage_up.xpm");
	game->player->addr[1] = ft_strdup("./sprites/mage_left.xpm");
	game->player->addr[2] = ft_strdup("./sprites/mage_down.xpm");
	game->player->addr[3] = ft_strdup("./sprites/mage_right.xpm");
}
