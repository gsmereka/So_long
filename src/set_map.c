/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:10:21 by gsmereka          #+#    #+#             */
/*   Updated: 2022/10/11 13:45:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data.h"

static void	ft_count_col(t_data *game);
static void	ft_count_lines(t_data *game);
static void	ft_check_format(t_data *game);
static int	ft_validate_map(t_data *game);

void	ft_set_map(t_data *game)
{
	game->map->fd = open(game->map->addr, O_RDWR);
	ft_count_lines(game);
	ft_count_col(game);
	ft_check_format(game);
	ft_validate_map(game);
	close(game->map->fd);
}

static void	ft_count_lines(t_data *game)
{
	int	lines;

	lines = 0;
	while (lines < game->map->max_lines)
	{
		game->map->grid[lines] = get_next_line(game->map->fd, 0);
		if (game->map->grid[lines] == NULL)
			break ;
		lines++;
	}
	game->map->lin = lines;
}

static void	ft_count_col(t_data *game)
{
	int	lines;
	int	cols;
	int	cols_nmb;
	int	i;

	i = 0;
	lines = game->map->lin;
	if (lines <= 2)
		ft_set_shutdown(0, game,
			"\nMapa invalido, tem menos que 3 linhas validas\n");
	cols_nmb = (int)ft_strlen(game->map->grid[lines - 1]);
	while (i < lines - 1)
	{
		cols = (int)ft_strlen(game->map->grid[i]);
		if (cols != cols_nmb + 1)
			ft_set_shutdown(0, game, "\nO Mapa não é retangular\n");
		i++;
	}
	game->map->col = cols_nmb;
}

static void	ft_check_format(t_data *game)
{
	int	stop;
	int	last_line;

	stop = 1;
	last_line = game->map->lin;
	game->map->grid[last_line] = get_next_line(game->map->fd, stop);
	if (game->map->grid[last_line] != NULL
		|| game->map->col > game->map->max_cols)
		ft_set_shutdown(0, game, "\nMapa invalido ou muito grande\n");
	else if (game->map->col < 3)
		ft_set_shutdown(0, game,
			"\nMapa invalido, tem menos que 3 colunas ou não é retangular\n");
	else
		printf("\neste mapa tem %d linhas e %d colunas validas\n",
			game->map->lin, game->map->col);
}

static int	ft_validate_map(t_data *game)
{
	ft_check_walls(game);
	ft_check_composition(game);
	ft_check_path(game);
	printf("the map is valid\n");
	return (1);
}
