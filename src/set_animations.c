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

#include "../header/so_long.h"

static void	animate_portal_sprites(t_sprites *sprite);
static void	animate_enemies_sprites(t_data *game);

int	set_animations(t_data *game)
{
	if (game->map->objects->n_enemies > 0)
	{
		animate_enemies_sprites(game);
		set_enemies_move(game);
	}
	if (game->map->objects->n_collectibles == 0)
		animate_portal_sprites(game->exit);
	return (0);
}

static void	animate_portal_sprites(t_sprites *sprite)
{
	clock_t			now;
	static long int	save;

	now = clock();
	if (now - save > 22000)
	{
		save = now;
		if (sprite->frame == 4)
			sprite->frame = 1;
		sprite->frame++;
	}
}

static void	animate_enemies_sprites(t_data *game)
{
	static int		change;
	clock_t			now;
	static long int	save;

	now = clock();
	if (now - save > 25000)
	{
		save = now;
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
	}
}
