/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   set_animations_bonus.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gsmereka <gsmereka@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/10/19 12:05:09 by gsmereka		  #+#	#+#			 */
/*   Updated: 2022/10/19 16:44:01 by gsmereka		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static void	animate_portal_sprites(t_sprites *sprite, int time);
static void	animate_enemies_sprites(t_data *game, int time);

int	set_animations(t_data *game)
{
	clock_t	time;

	time = clock();
	if (game->map->objects->n_enemies > 0)
	{
		animate_enemies_sprites(game, time);
		set_enemies_move(game, time);
	}
	if (game->map->objects->n_collectibles == 0)
		animate_portal_sprites(game->exit, time);
	return (0);
}

static void	animate_portal_sprites(t_sprites *sprite, int last_time)
{
	static int	now;

	if (last_time - now > 60000)
	{
		if (sprite->frame == 4)
			sprite->frame = 1;
		sprite->frame++;
		now = last_time;
	}
}

static void	animate_enemies_sprites(t_data *game, int last_time)
{
	static int		change;
	static int		now;

	if (last_time - now > 60000)
	{
		if (change < 3)
		{
			game->enemy->frame++;
		}
		else if (change >= 3)
		{
			game->enemy->frame--;
		}
		change++;
		if (change == 6)
			change = 0;
		now = last_time;
	}
}
