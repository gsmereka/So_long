/* ************************************************************************** */
/*					                                                        */
/*                                                        :::      ::::::::   */
/*   set_steps_to_char_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:00:55 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/16 21:04:48 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/so_long_bonus.h"

static char	*steps_to_char(int steps);
static char	*itochar(int size, int steps);
static int	ft_calculate_size(int steps);

void	set_steps_to_char(t_data *game)
{
	int		steps;
	char	*s_steps;

	free(game->map->player_steps);
	steps = game->map->player_moves;
	s_steps = steps_to_char(steps);
	if (s_steps == NULL)
		set_shutdown(1, game, "Error\nMemory Error.\n");
	game->map->player_steps = s_steps;
}

static char	*steps_to_char(int steps)
{
	int		size;
	char	*s_steps;

	if (steps == 0)
		s_steps = ft_strdup("0");
	else
	{
		size = ft_calculate_size(steps);
		s_steps = itochar(size, steps);
	}
	return (s_steps);
}

static int	ft_calculate_size(int steps)
{
	int	size;

	size = 0;
	while (steps > 0)
	{
		steps = steps / 10;
		size++;
	}
	return (size);
}

static char	*itochar(int size, int steps)
{
	char	*s_steps;
	int		index;
	int		temp;
	int		i;

	index = 0;
	s_steps = (char *)malloc((size + 1) * sizeof(char));
	s_steps[size] = '\0';
	while (size > 0)
	{
		i = size - 1;
		temp = steps;
		while (i > 0)
		{
			temp = temp / 10;
			i--;
		}
		temp = (temp % 10) + '0';
		s_steps[index] = temp;
		index++;
		size--;
	}
	return (s_steps);
}
