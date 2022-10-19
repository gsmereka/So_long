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

#include "../header_bonus/so_long_bonus.h"

static void	set_enemies_sprites(t_data *game);

void	set_sprites(t_data *game)
{
	game->floor->addr[0] = ft_strdup("./sprites/floor.xpm");
	game->colect->addr[0] = ft_strdup("./sprites/potion.xpm");
	game->wall->addr[0] = ft_strdup("./sprites/wall.xpm");
	game->exit->addr[0] = ft_strdup("./sprites/portal_0.xpm");
	game->exit->addr[1] = ft_strdup("./sprites/portal_1.xpm");
	game->exit->addr[2] = ft_strdup("./sprites/portal_2.xpm");
	game->exit->addr[3] = ft_strdup("./sprites/portal_3.xpm");
	game->exit->addr[4] = ft_strdup("./sprites/portal_4.xpm");
	game->player->addr[0] = ft_strdup("./sprites/mage_up.xpm");
	game->player->addr[1] = ft_strdup("./sprites/mage_left.xpm");
	game->player->addr[2] = ft_strdup("./sprites/mage_down.xpm");
	game->player->addr[3] = ft_strdup("./sprites/mage_right.xpm");
	game->board->addr[0] = ft_strdup("./sprites/board.xpm");
	set_enemies_sprites(game);
}

static void	set_enemies_sprites(t_data *game)
{
	game->enemy->addr[0] = ft_strdup("./sprites/slime_1.xpm");
	game->enemy->addr[1] = ft_strdup("./sprites/slime_2.xpm");
	game->enemy->addr[2] = ft_strdup("./sprites/slime_3.xpm");
	game->enemy->addr[3] = ft_strdup("./sprites/slime_4.xpm");
}
